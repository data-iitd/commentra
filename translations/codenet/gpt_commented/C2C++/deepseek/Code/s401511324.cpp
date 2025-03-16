#include<iostream>
#include<vector>
#include<algorithm>

int main() {
    // Declare variables
    int n;
    std::vector<int> l;
    int i, j, k, cnt = 0, tmp = 0;

    // Read the number of elements
    std::cin >> n;

    // Input the elements into the vector
    for(i = 0; i < n; i++) {
        std::cin >> tmp;
        l.push_back(tmp);
    }

    // Sort the vector using the sort function from the algorithm library
    std::sort(l.begin(), l.end());

    // Count the number of valid triplets (i, j, k) such that l[i] + l[j] > l[k]
    for(i = 0; i < n - 2; i++) {
        for(j = i + 1; j < n - 1; j++) {
            for(k = j + 1; k < n; k++) {
                // Check if the sum of two elements is greater than the third
                if(l[i] + l[j] > l[k]) {
                    cnt++; // Increment count if the condition is satisfied
                } else {
                    break; // Break if the condition is not satisfied (since vector is sorted)
                }
            }
        }
    }

    // Output the count of valid triplets
    std::cout << cnt << std::endl;
    
    return 0;
}
