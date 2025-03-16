#include <iostream>
#include <vector>

// Linear Search Function
// Purpose: This function performs a linear search to find the key in the array S.
// Parameters:
//   - S: The vector to be searched.
//   - key: The value to be searched for.
// Return Value: Returns true if the key is found, otherwise returns false.
bool linearsearch(const std::vector<int>& S, int key) {
    for (int i = 0; i < S.size(); i++) {
        if (S[i] == key) {
            return true; // Key found
        }
    }
    return false; // Key not found
}

// Main Function
// Purpose: This function reads two vectors S and T, and counts the number of elements in T that are present in S using the linearsearch function.
int main() {
    int n, q;
    std::vector<int> S, T;

    std::cin >> n;
    S.resize(n);
    for (int i = 0; i < n; i++) {
        std::cin >> S[i];
    }

    std::cin >> q;
    T.resize(q);
    for (int j = 0; j < q; j++) {
        std::cin >> T[j];
    }

    int count = 0;
    for (int j = 0; j < q; j++) {
        if (!linearsearch(S, T[j])) {
            count++;
        }
    }

    std::cout << count << std::endl;

    return 0;
}

// <END-OF-CODE>
