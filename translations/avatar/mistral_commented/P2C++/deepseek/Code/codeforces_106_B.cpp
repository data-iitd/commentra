#include <iostream>
#include <vector>
#include <tuple>
#include <set>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<std::tuple<int, int, int, int>> input_array;

    for (int i = 0; i < n; ++i) {
        int S, R, H, C;
        std::cin >> S >> R >> H >> C;
        input_array.emplace_back(S, R, H, C);
    }

    std::vector<std::tuple<int, int, int, int>> outdated;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (std::get<0>(input_array[i]) < std::get<0>(input_array[j]) &&
                std::get<1>(input_array[i]) < std::get<1>(input_array[j]) &&
                std::get<2>(input_array[i]) < std::get<2>(input_array[j])) {
                outdated.push_back(input_array[i]);
            }
        }
    }

    std::set<std::tuple<int, int, int, int>> outdated_set(outdated.begin(), outdated.end());

    int minimum_cost = 100000;
    int input_number = 0;

    for (int i = 0; i < n; ++i) {
        int cost = std::get<3>(input_array[i]);
        if (outdated_set.find(input_array[i]) == outdated_set.end() && cost < minimum_cost) {
            minimum_cost = cost;
            input_number = i + 1;
        }
    }

    std::cout << input_number << std::endl;

    return 0;
}
