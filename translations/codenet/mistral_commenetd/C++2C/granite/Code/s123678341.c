

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <iostream>
#include <sstream>
#include <string>
#include <bitset>
#include <random>
#include <chrono>
#include <iomanip>
#include <functional>
#include <cassert>
#include <cctype>
#include <climits>
#include <clocale>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#include <deque>
#include <fstream>
#include <list>
#include <numeric>
#include <stack>
#include <utility>
#include <bitset>
#include <exception>
#include <stdexcept>
#include <system_error>
#include <typeinfo>
#include <array>
#include <forward_list>
#include <unordered_map>
#include <unordered_set>

// Main function starts here
int main(){
    // Initialize input variables
    int X, Y, Z, K; // Number of elements in vectors A, B, C and the limit for output
    scanf("%d %d %d %d", &X, &Y, &Z, &K); // Read input values for X, Y, Z, and K from standard input

    // Initialize vectors A, B, and C
    long long A[X]; // A vector of size X, initialized with zeroes
    long long B[Y]; // B vector of size Y, initialized with zeroes
    long long C[Z]; // C vector of size Z, initialized with zeroes

    // Read input values for vectors A, B, and C from standard input
    for(int i=0; i<X; i++){
        scanf("%lld", &A[i]); // Read each element of vector A
    }
    for(int i=0; i<Y; i++){
        scanf("%lld", &B[i]); // Read each element of vector B
    }
    for(int i=0; i<Z; i++){
        scanf("%lld", &C[i]); // Read each element of vector C
    }

    // Sort vectors A, B, and C in descending order
    std::sort(A, A+X, std::greater<long long>());
    std::sort(B, B+Y, std::greater<long long>());
    std::sort(C, C+Z, std::greater<long long>());

    // Create a new vector AB by adding each element of A to each element of B
    std::vector<long long> AB;
    for(int i=0; i<X; i++){
        for(int j=0; j<Y; j++){
            AB.push_back(A[i]+B[j]); // Add A[i] and B[j] and push the sum into vector AB
        }
    }

    // Sort vector AB in descending order
    std::sort(AB.begin(), AB.end(), std::greater<long long>());

    // Create a new vector ABC by adding each element of AB to each element of C
    std::vector<long long> ABC;
    for(int i=0; i<std::min(K, (int)AB.size()); i++){
        for(int j=0; j<Z; j++){
            ABC.push_back(AB[i] + C[j]); // Add AB[i] and C[j] and push the sum into vector ABC
        }
    }

    // Sort vector ABC in descending order
    std::sort(ABC.begin(), ABC.end(), std::greater<long long>());

    // Print K smallest elements of vector ABC
    for(int i=0; i<K; i++){
        printf("%lld\n", ABC[i]); // Print each element of vector ABC
    }

    // Main function ends here
    return 0;
}

