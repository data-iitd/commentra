#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    // Step 3: Create a Scanner object to read input from the user
    int n, a, b;
    std::cin >> n >> a >> b;

    // Step 4: Create two vector objects to store the lists of integers
    std::vector<int> list1;
    std::vector<int> list2;

    // Step 5: Read the elements of list1 and list2 from the user
    for (int i = 0; i < a; i++) {
        int num;
        std::cin >> num;
        list1.push_back(num);
    }
    for (int i = 0; i < b; i++) {
        int num;
        std::cin >> num;
        list2.push_back(num);
    }

    // Step 6: Iterate through the range from 1 to n and print the appropriate list number
    for (int i = 1; i <= n; i++) {
        if (std::find(list1.begin(), list1.end(), i) != list1.end()) {
            std::cout << 1 << " ";
        } else {
            std::cout << 2 << " ";
        }
    }

    return 0;
}
