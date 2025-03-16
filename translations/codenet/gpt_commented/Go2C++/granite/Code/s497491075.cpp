
```cpp
#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <sstream>

void Run(std::istream& r, std::ostream& w) {
    // Initialize a new scanner to read input
    Scanner sc(r);

    // Read the first line of input and parse N (number of lines) and D (distance threshold)
    auto a = sc.ReadLine().Ints();
    int N = a[0], D = a[1];

    // Read the next N lines of input, each containing a pair of integers
    auto lines = sc.ReadLines(N).Ints();

    // Initialize a counter for the number of points within the distance D
    int count = 0;
    // Iterate over each line of input
    for (const auto& line : lines) {
        // Calculate the Euclidean distance from the origin (0, 0)
        double d = std::sqrt(line[0] * line[0] + line[1] * line[1]);
        // Check if the distance is less than or equal to D
        if (static_cast<int>(D) >= d) {
            count++; // Increment the count if within distance
        }
    }
    // Output the total count of points within distance D
    w << count << std::endl;
}

int main() {
    // Call the Run function with standard input and output
    Run(std::cin, std::cout);
}

class Scanner {
public:
    Scanner(std::istream& r) : sc(r) {}

    std::string ReadLine() {
        std::string line;
        std::getline(sc, line);
        return line;
    }

    std::vector<std::string> ReadLines(int n) {
        std::vector<std::string> lines;
        for (int i = 0; i < n; i++) {
            lines.push_back(ReadLine());
        }
        return lines;
    }

private:
    std::istream& sc;
};

int main() {
    Run(std::cin, std::cout);
}

