#include <chrono>
#include <cstring>
#include <filesystem>
#include <iostream>
#include <numeric>
#include <thread>

#include "AdFunctions.hpp"
#include "AdTypes.hpp"
#include "DataLoader.hpp"

#include "utils.hpp" // dont forget the include setting for the c++ runner

namespace fs = std::filesystem;

int main(int argc, char **argv)
{
    auto data_filepath = fs::path{};
    auto ego_filepath = fs::path{};

    if (argc != 3)
    {
        data_filepath /= fs::current_path();
        data_filepath /= "data";
        ego_filepath = data_filepath;

        data_filepath /= "vehicle_data.json";
        ego_filepath /= "ego_data.json";
    }
    else
    {
        const auto vehicles_input_path = std::string(argv[1]);
        data_filepath = fs::path(vehicles_input_path);

        const auto ego_input_path = std::string(argv[2]);
        ego_filepath = fs::path(ego_input_path);
    }

    auto cycle = std::uint32_t{0};
    auto ego_vehicle = VehicleType{};
    auto vehicles = NeighborVehiclesType{};

    init_vehicles(data_filepath.string(), vehicles);
    init_ego_vehicle(ego_filepath.string(), ego_vehicle);

    print_vehicle(ego_vehicle);
    print_neighbor_vehicles(vehicles);

    std::cout << "Start simulation?: ";
    auto Input = char{};
    std::cin >> Input;

    while (true)
    {
        clear_console();

        print_scene(ego_vehicle, vehicles);
        compute_future_state(ego_vehicle, vehicles, 0.100F);

        const auto &ego_lane_vehicles =
            get_vehicle_array(ego_vehicle.lane, vehicles);
        longitudinal_control(ego_lane_vehicles[0], ego_vehicle);

        const auto lane_change_request =
            get_lane_change_request(ego_vehicle, vehicles);
        const auto lane_change_executed =
            lateral_control(lane_change_request, ego_vehicle);

        if (lane_change_executed)
        {
            printf("Executed lane change!");
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(100));

        cycle++;
        load_cycle(cycle, vehicles);
    }

    return 0;
}
