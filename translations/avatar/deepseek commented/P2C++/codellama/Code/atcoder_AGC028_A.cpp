
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, M;
    string S, T;
    cin >> N >> M >> S >> T;
    vector<int> list_S(S.begin(), S.end());
    vector<int> list_T(T.begin(), T.end());
    vector<int> Number_i(N);
    for (int i = 0; i < N; i++) {
        Number_i[i] = i;
    }
    vector<int> Number_iMN(N);
    for (int i = 0; i < N; i++) {
        Number_iMN[i] = i * M / N;
    }
    vector<int> Number_j(M);
    for (int j = 0; j < M; j++) {
        Number_j[j] = j;
    }
    vector<int> Kaburi_j(M);
    set_intersection(Number_iMN.begin(), Number_iMN.end(), Number_j.begin(), Number_j.end(), Kaburi_j.begin());
    vector<int> Kaburi_i(Kaburi_j.size());
    for (int j = 0; j < Kaburi_j.size(); j++) {
        Kaburi_i[j] = int(Kaburi_j[j] * N / M);
    }
    int counter = 0;
    int Flag = 0;
    int Kaburi_Size = Kaburi_i.size();
    while (counter <= Kaburi_Size - 1) {
        if (list_S[Kaburi_i[counter]] == list_T[Kaburi_j[counter]]) {
            counter++;
        } else {
            Flag = 1;
            break;
        }
    }
    if (Flag == 1) {
        cout << -1 << endl;
    } else {
        cout << int(N * M / gcd(N, M)) << endl;
    }
    return 0;
}

