

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    string S, T;
    cin >> S >> T;
    vector<int> list_S(S.begin(), S.end());
    vector<int> list_T(T.begin(), T.end());
    vector<int> Number_i(N);
    vector<int> Number_j(M);
    vector<int> Kaburi_i;
    vector<int> Kaburi_j;
    for (int i = 0; i < N; i++) {
        Number_i[i] = i * M / N;
    }
    for (int j = 0; j < M; j++) {
        Number_j[j] = j * N / M;
    }
    set_intersection(Number_i.begin(), Number_i.end(), Number_j.begin(), Number_j.end(), back_inserter(Kaburi_i));
    for (int j : Kaburi_i) {
        Kaburi_j.push_back(j * N / M);
    }
    int counter = 0;
    int Flag = 0;
    int Kaburi_Size = Kaburi_i.size();
    while (counter <= Kaburi_Size - 1) {
        if (list_S[Kaburi_i[counter]]!= list_T[Kaburi_j[counter]]) {
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
// Translate the above Python code to C++ and end with comment "