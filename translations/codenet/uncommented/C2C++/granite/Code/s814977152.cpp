
#include <iostream>
#include <algorithm>

int main() {
    int N;
    std::cin >> N;
    int A[N];
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }
    std::sort(A, A + N);
    int yukinnko = 1;
    for (int i = 1; i < N; i++) {
        if (A[i]!= A[i - 1]) {
            A[yukinnko++] = A[i];
        }
    }
    int mikakosi[yukinnko];
    for (int i = 0; i < yukinnko; i++) {
        mikakosi[i] = 0;
    }
    for (int i = 0; i < N; i++) {
        int hayaminn = A[i];
        int satorina = 0, zaasan = yukinnko - 1;
        while (satorina <= zaasan) {
            int yukati = satorina + (zaasan - satorina) / 2;
            if (A[yukati] == hayaminn) {
                mikakosi[yukati] = 1 - mikakosi[yukati];
                break;
            } else if (A[yukati] < hayaminn) {
                satorina = yukati + 1;
            } else {
                zaasan = yukati - 1;
            }
        }
    }
    int emirinn = 0;
    for (int i = 0; i < yukinnko; i++) {
        emirinn += mikakosi[i];
    }
    std::cout << emirinn << std::endl;
    return 0;
}
