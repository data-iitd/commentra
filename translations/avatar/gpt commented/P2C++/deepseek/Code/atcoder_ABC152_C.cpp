#include <iostream>
#include <vector>
#include <sstream>

int main() {
    int N;
    std::cout << "Enter the number of elements: ";
    std::cin >> N;

    std::vector<int> n;
    std::string input;
    std::cout << "Enter the elements separated by spaces: ";
    std::cin.ignore(); // To ignore the newline character left by the previous input
    std::getline(std::cin, input);

    std::stringstream ss(input);
    int num;
    while (ss >> num) {
        n.push_back(num);
    }

    int a = 1;
    int pos = 0;

    for (int i = 1; i < N; ++i) {
        if (n[pos] > n[i]) {
            ++a;
            pos = i;
        }
    }

    std::cout << a << std::endl;

    return 0;
}
