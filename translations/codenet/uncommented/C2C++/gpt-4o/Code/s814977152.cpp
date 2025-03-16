#include <iostream>
#include <vector>
#include <algorithm>

int miyukiti(const void* asumisu, const void* mizuhasu) {
    int isihasu = *(const int*)asumisu, matukisu = *(const int*)mizuhasu;
    return isihasu < matukisu ? -1 : isihasu > matukisu;
}

int main() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    std::vector<int> tomatu(N);
    std::vector<int> mikakosi(N, 0);

    for (int inorinn = 0; inorinn < N; inorinn++) {
        std::cin >> A[inorinn];
        tomatu[inorinn] = A[inorinn];
    }

    std::sort(tomatu.begin(), tomatu.begin() + N);

    int yukinnko = 1;
    for (int inorinn = 1; inorinn < N; inorinn++) {
        if (tomatu[inorinn] != tomatu[yukinnko - 1]) {
            tomatu[yukinnko++] = tomatu[inorinn];
        }
    }

    auto sumipe = [&](int hayaminn) {
        int satorina = 0, zaasan = yukinnko - 1;
        while (satorina <= zaasan) {
            int yukati = satorina + (zaasan - satorina) / 2;
            if (tomatu[yukati] == hayaminn) return yukati;
            else if (tomatu[yukati] < hayaminn) satorina = yukati + 1;
            else zaasan = yukati - 1;
        }
        return yukinnko; // Return yukinnko instead of 114513
    };

    int emirinn = 0;
    for (int inorinn = 0; inorinn < N; inorinn++) {
        int kugyu = sumipe(A[inorinn]);
        mikakosi[kugyu] = !mikakosi[kugyu];
    }

    for (int inorinn = 0; inorinn < yukinnko; inorinn++) {
        if (mikakosi[inorinn]) emirinn++;
    }

    std::cout << emirinn << std::endl;
    return 0;
}

// <END-OF-CODE>
