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
    string S, T;
    cin >> N >> M;
    cin >> S;
    cin >> T;

    vector<int> Number_i(N);
    vector<int> Number_iMN(N);
    vector<int> Number_j(M);
    set<int> Kaburi_j;
    vector<int> Kaburi_i;

    for (int i = 0; i < N; ++i) {
        Number_i[i] = i;
    }

    for (int i = 0; i < N; ++i) {
        Number_iMN[i] = i * M / N;
    }

    for (int j = 0; j < M; ++j) {
        Number_j[j] = j;
    }

    Kaburi_j = set<int>(Number_iMN.begin(), Number_iMN.end());
    Kaburi_j.insert(Number_j.begin(), Number_j.end());

    for (int j : Kaburi_j) {
        if (set<int>(Number_iMN.begin(), Number_iMN.end()).count(j)) {
            Kaburi_i.push_back(j * N / M);
        }
    }

    int counter = 0;
    int Flag = 0;
    int Kaburi_Size = Kaburi_i.size();

    while (counter <= Kaburi_Size - 1) {
        if (S[Kaburi_i[counter]] != T[counter]) {
            Flag = 1;
            break;
        }
        counter++;
    }

    if (Flag == 1) {
        cout << -1 << endl;
    } else {
        cout << N * M / gcd(N, M) << endl;
    }

    return 0;
}
