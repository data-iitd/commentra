#include <iostream>
#include <vector>
#include <algorithm>

void cutRibbon() {
    std::vector<int> arr;
    int length, temp;
    
    // Read input
    std::cin >> length;
    for (int i = 0; i < 3; ++i) {
        std::cin >> temp;
        arr.push_back(temp);
    }
    
    // Sort the array
    std::sort(arr.begin(), arr.end());
    
    // Check if length is divisible by the largest piece
    if (length % arr[2] == 0) {
        std::cout << length / arr[2] << std::endl;
        return;
    }
    
    int ans = 0;
    if (arr[1] == arr[2]) {
        int k = 0;
        for (int i = 0; i <= length / arr[2]; ++i) {
            int check = length - i * arr[2];
            if (check >= 0 && check % arr[0] == 0) {
                k = check / arr[0];
                ans = std::max(ans, k + i);
            }
        }
    } else {
        int k = 0;
        for (int i = 0; i <= length / arr[2]; ++i) {
            for (int j = 0; j <= length / arr[1]; ++j) {
                int check = length - i * arr[2] - j * arr[1];
                if (check >= 0 && check % arr[0] == 0) {
                    k = check / arr[0];
                    ans = std::max(ans, k + i + j);
                }
            }
        }
    }
    
    std::cout << ans << std::endl;
}

int main() {
    cutRibbon();
    return 0;
}

// <END-OF-CODE>
