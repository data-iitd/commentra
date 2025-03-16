#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iterator>

int main() {
    std::istream_iterator<int> cin_iter(std::cin);
    int num = *cin_iter;
    ++cin_iter;
    std::vector<int> arr(cin_iter, std::istream_iterator<int>());

    std::sort(arr.begin(), arr.end());

    bool divisible = true;
    for (int x : arr) {
        if (x % arr[0] != 0) {
            divisible = false;
            break;
        }
    }

    if (divisible) {
        std::cout << arr[0] << std::endl;
    } else {
        std::cout << -1 << std::endl;
    }

    return 0;
}
