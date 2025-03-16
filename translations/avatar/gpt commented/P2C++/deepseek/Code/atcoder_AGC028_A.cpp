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

    vector<int> list_S(N);
    vector<int> list_T(M);

    for (int i = 0; i < N; ++i) {
        list_S[i] = S[i];
    }

    for (int j = 0; j < M; ++j) {
        list_T[j] = T[j];
    }

    vector<double> Number_iMN;
    for (int i = 0; i < N; ++i) {
        Number_iMN.push_back(i * M / (double)N);
    }

    set<int> Number_j;
    for (int j = 0; j < M; ++j) {
        Number_j.insert(j);
    }

    set<int> Kaburi_j;
    for (double num : Number_iMN) {
        if (Number_j.find(num) != Number_j.end()) {
            Kaburi_j.insert(num);
        }
    }

    vector<int> Kaburi_i;
    for (int j : Kaburi_j) {
        Kaburi_i.push_back(j * N / M);
    }

    int counter = 0;
    bool Flag = false;

    while (counter < Kaburi_i.size()) {
        if (list_S[Kaburi_i[counter]] != list_T[*Kaburi_j.find(Kaburi_i[counter])]) {
            Flag = true;
            break;
        }
        ++counter;
    }

    if (Flag) {
        cout << -1 << endl;
    } else {
        cout << (N * M / gcd(N, M)) << endl;
    }

    return 0;
}
