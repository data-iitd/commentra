
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    string S, T;
    cin >> S >> T;

    vector<int> Number_iMN;
    for (int i = 0; i < N; i++) {
        Number_iMN.push_back(i * M / N);
    }

    vector<int> Kaburi_j;
    for (int j = 0; j < M; j++) {
        if (find(Number_iMN.begin(), Number_iMN.end(), j)!= Number_iMN.end()) {
            Kaburi_j.push_back(j);
        }
    }

    vector<int> Kaburi_i;
    for (int j : Kaburi_j) {
        Kaburi_i.push_back(int(j * N / M));
    }

    int counter = 0;
    int Flag = 0;
    int Kaburi_Size = Kaburi_i.size();

    while (counter <= Kaburi_Size - 1) {
        if (S[Kaburi_i[counter]] == T[Kaburi_j[counter]]) {
            counter++;
        } else {
            Flag = 1;
            break;
        }
    }

    if (Flag == 1) {
        cout << -1 << endl;  // Print -1 if there was a mismatch
    } else {
        int result = N * M / __gcd(N, M);
        cout << result << endl;  // Print the least common multiple (LCM) of N and M
    }

    return 0;
}
