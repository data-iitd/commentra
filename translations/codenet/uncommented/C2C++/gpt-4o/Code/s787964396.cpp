#include <iostream>
#include <vector>
#include <algorithm>

#define I 10000

void CountingSort(int* a, int* b, int n);

int main() {
    int max = 0, n;
    std::cin >> n;
    
    int* a = new int[n + 1];
    int* b = new int[n + 1];
    
    for (int i = 0; i < n; i++) {
        std::cin >> a[i + 1];
    }
    
    CountingSort(a, b, n);
    
    std::cout << b[1];
    for (int i = 2; i < n + 1; i++) {
        std::cout << " " << b[i];
    }
    std::cout << std::endl;
    
    delete[] a;
    delete[] b;
    
    return 0;
}

void CountingSort(int a[], int b[], int k) {
    int c[I + 1] = {0}; // Initialize the count array to zero
    
    for (int j = 0; j < k; j++) {
        c[a[j + 1]]++;
    }
    
    for (int i = 1; i <= I; i++) {
        c[i] += c[i - 1];
    }
    
    for (int j = k; j > 0; j--) {
        b[c[a[j]]] = a[j];
        c[a[j]]--;
    }
}

// <END-OF-CODE>
