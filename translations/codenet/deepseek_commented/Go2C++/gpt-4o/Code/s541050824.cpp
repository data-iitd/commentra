#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <iomanip>

using namespace std;

// Function to read an integer from input
int64_t nextInt() {
    int64_t x;
    cin >> x;
    return x;
}

// Function to calculate the maximum of two integers
int64_t max(int64_t x, int64_t y) {
    return (x > y) ? x : y;
}

// Function to calculate the ceiling of the division of x by y
int64_t divUp(int64_t x, int64_t y) {
    return (x + y - 1) / y;
}

// Main function
int main() {
    int64_t N = nextInt();
    vector<int64_t> T(N), A(N);
    
    for (int64_t i = 0; i < N; i++) {
        T[i] = nextInt();
        A[i] = nextInt();
    }
    
    int64_t t = T[0], a = A[0];
    for (int64_t i = 1; i < N; i++) {
        int64_t r = max(divUp(t, T[i]), divUp(a, A[i]));
        t = T[i] * r;
        a = A[i] * r;
    }
    
    cout << t + a << endl;
    return 0;
}

// <END-OF-CODE>
