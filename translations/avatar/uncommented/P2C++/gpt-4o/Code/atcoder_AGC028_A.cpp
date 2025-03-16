#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
    while (b > 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int N, M;
    cin >> N >> M;
    string S, T;
    cin >> S >> T;

    vector<int> list_S(S.begin(), S.end());
    vector<int> list_T(T.begin(), T.end());
    vector<int> Number_i(N);
    vector<double> Number_iMN(N);
    
    for (int i = 0; i < N; ++i) {
        Number_i[i] = i;
        Number_iMN[i] = i * static_cast<double>(M) / N;
    }

    vector<int> Number_j(M);
    for (int j = 0; j < M; ++j) {
        Number_j[j] = j;
    }

    set<int> Kaburi_j_set;
    for (double num : Number_iMN) {
        if (num >= 0 && num < M) {
            Kaburi_j_set.insert(static_cast<int>(num));
        }
    }

    vector<int> Kaburi_j(Kaburi_j_set.begin(), Kaburi_j_set.end());
    vector<int> Kaburi_i;

    for (int j : Kaburi_j) {
        Kaburi_i.push_back(static_cast<int>(j * static_cast<double>(N) / M));
    }

    int counter = 0;
    bool Flag = false;
    int Kaburi_Size = Kaburi_i.size();

    while (counter < Kaburi_Size) {
        if (list_S[Kaburi_i[counter]] != list_T[Kaburi_j[counter]]) {
            Flag = true;
            break;
        }
        counter++;
    }

    if (Flag) {
        cout << -1 << endl;
    } else {
        cout << (N * M) / gcd(N, M) << endl;
    }

    return 0;
}
