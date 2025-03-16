#include <iostream>
#include <vector>

int main() {
    int max, max_j, buf;
    std::vector<int> io(5);
    
    std::cin >> io[0] >> io[1] >> io[2] >> io[3] >> io[4];
    
    for (int i = 0; i < 5; i++) {
        max = io[i];
        max_j = i;
        for (int j = i + 1; j < 5; j++) {
            if (max < io[j]) {
                max = io[j];
                max_j = j;
            }
        }
        buf = io[i];
        io[i] = io[max_j];
        io[max_j] = buf;
        i < 4 ? std::cout << io[i] << " " : std::cout << io[i] << std::endl;
    }
    
    return 0;
}

// <END-OF-CODE>
