#include <iostream>
#include <vector>
#include <algorithm>

void main_function() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    
    int current_level = 0;
    int counter = 0;
    int counter_turns = -1;

    while (counter < a.size()) {
        counter_turns++;
        for (int i = 0; i < a.size(); ++i) {
            if (a[i] != -1 && a[i] <= counter) {
                counter++;
                a[i] = -1;
            }
        }
        std::reverse(a.begin(), a.end());
    }
    
    std::cout << counter_turns << std::endl;
}

int main() {
    main_function();
    return 0;
}

// <END-OF-CODE>
