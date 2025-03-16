
#include <iostream>
#include <vector>
#include <set>

int main() {
    int n;
    std::cin >> n;

    std::vector<std::vector<int>> input_array(n, std::vector<int>(4));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 4; j++) {
            std::cin >> input_array[i][j];
        }
    }

    std::set<std::vector<int>> outdated;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (input_array[i][0] < input_array[j][0] &&
                input_array[i][1] < input_array[j][1] &&
                input_array[i][2] < input_array[j][2]) {
                outdated.insert(input_array[i]);
            }
        }
    }

    int minimum_cost = 100000;
    int input_number = 0;
    for (int i = 0; i < n; i++) {
        if (outdated.count(input_array[i]) == 0 && input_array[i][3] < minimum_cost) {
            minimum_cost = input_array[i][3];
            input_number = i + 1;
        }
    }

    std::cout << input_number << std::endl;

    return 0;
}
