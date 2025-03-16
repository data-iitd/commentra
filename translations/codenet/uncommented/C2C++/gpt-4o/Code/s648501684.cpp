#include <iostream>
#include <vector>

int main() {
    long int n, k, q;
    
    std::cin >> n >> k >> q;
    
    std::vector<int> arr(n + 1, 0); // Initialize a vector of size n+1 with all elements set to 0
    
    for(long int i = 0; i < q; i++) {
        long int temp;
        std::cin >> temp;
        arr[temp] += 1; // Increment the count for the given index
    }
    
    for(long int i = 1; i <= n; i++) {
        if(arr[i] > (q - k)) {
            std::cout << "Yes\n";
        } else {
            std::cout << "No\n";
        }
    }

    return 0;
}

// <END-OF-CODE>
