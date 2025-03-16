#include <iostream>
#include <vector>
#include <sstream>

int main() {
    int n, a, b;
    std::vector<int> lista, listb;

    // Read three integers from input: n, a, and b
    std::cin >> n >> a >> b;

    // Read a list of integers from input and store it in lista
    std::string line;
    std::getline(std::cin, line); // To consume the newline character
    std::getline(std::cin, line);
    std::istringstream stream(line);
    int num;
    while (stream >> num) {
        lista.push_back(num);
    }

    // Read another list of integers from input and store it in listb
    std::getline(std::cin, line);
    std::istringstream stream2(line);
    while (stream2 >> num) {
        listb.push_back(num);
    }

    // Iterate through the range of n (from 0 to n-1)
    for (int k = 0; k < n; ++k) {
        // Check if the current index + 1 is present in lista
        if (std::find(lista.begin(), lista.end(), k + 1) != lista.end()) {
            // If present, print 1 followed by a space
            std::cout << 1 << " ";
        } else {
            // If not present, print 2 followed by a space
            std::cout << 2 << " ";
        }
    }

    std::cout << std::endl;
    return 0;
}
