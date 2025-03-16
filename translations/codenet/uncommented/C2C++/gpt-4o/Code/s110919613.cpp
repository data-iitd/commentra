#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int L, tmp, d, def, end, aj, max, min;

    while (true) {
        std::vector<int> an(20), a1(6), a2(6);
        std::cin >> an[0] >> L;
        if (L == 0) break;

        aj = an[0];
        end = 0;
        for (int k = 1; k < 21; k++) {
            for (int i = L - 1; i >= 0; i--, aj /= 10) {
                a1[i] = aj % 10;
                a2[i] = aj % 10;
            }
            for (int i = 1; i < L; i++) {
                for (int j = 1; j < L; j++) {
                    if (a1[j - 1] < a1[j]) {
                        std::swap(a1[j - 1], a1[j]);
                    }
                    if (a2[j - 1] > a2[j]) {
                        std::swap(a2[j - 1], a2[j]);
                    }
                }
            }
            d = 1; 
            max = 0; 
            min = 0;
            for (int i = L - 1; i >= 0; i--, d *= 10) {
                max += (a1[i] % 10) * d;
                min += (a2[i] % 10) * d;
            }
            def = max - min;
            for (int i = 0; i < k; i++) {
                if (def == an[i]) {
                    std::cout << i << " " << def << " " << k - i << std::endl;
                    end = 1; 
                    break;
                }
            }
            if (end == 1) break;
            an[k] = def; 
            aj = def;
        }
    }

    return 0;
}

// <END-OF-CODE>
