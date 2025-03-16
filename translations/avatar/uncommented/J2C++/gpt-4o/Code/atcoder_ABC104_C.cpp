#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 100000;

int main() {
    int D;
    long long G;
    cin >> D >> G;
    
    vector<int> p(D), c(D);
    for (int i = 0; i < D; i++) {
        cin >> p[i] >> c[i];
    }
    
    int min_solve_num = INF;
    
    for (int bit = 0; bit < (1 << D); bit++) {
        long long score = 0;
        int solve_num = 0;
        
        for (int i = 0; i < D; i++) {
            if (bit & (1 << i)) {
                score += 100 * (i + 1) * p[i] + c[i];
                solve_num += p[i];
            }
        }
        
        if (score < G) {
            for (int i = D - 1; i >= 0; i--) {
                if (!(bit & (1 << i))) {
                    for (int j = 0; j < p[i] - 1; j++) {
                        score += 100 * (i + 1);
                        solve_num++;
                        if (score >= G) {
                            break;
                        }
                    }
                }
            }
        }
        
        if (score >= G) {
            min_solve_num = min(min_solve_num, solve_num);
        }
    }
    
    cout << min_solve_num << endl;
    return 0;
}

// <END-OF-CODE>
