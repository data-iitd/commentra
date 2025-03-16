#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    string S;
    cin >> S;

    vector<char> c1(S.begin(), S.end());
    vector<char> c3(S.begin(), S.end());
    bool flag = false;
    int count = 0;

    for (int i = 0; i < N; i++) {
        if (flag && c1[i] == 'R') {
            flag = false;
            count++;
        }
        if (count == K) {
            break;
        }
        if (c1[i] == 'L') {
            flag = true;
            c1[i] = 'R';
        }
    }

    flag = false;
    count = 0;

    for (int i = 0; i < N; i++) {
        if (flag && c3[i] == 'L') {
            flag = false;
            count++;
        }
        if (count == K) {
            break;
        }
        if (c3[i] == 'R') {
            flag = true;
            c3[i] = 'L';
        }
    }

    string S1(c1.begin(), c1.end());
    string S3(c3.begin(), c3.end());
    count = 1;
    int sum1 = 0;
    char bef = S1[0];

    for (int i = 1; i < N; i++) {
        if (S1[i] == bef) {
            count++;
            if (i == N - 1) {
                sum1 += count - 1;
            }
        } else {
            bef = S1[i];
            sum1 += count - 1;
            count = 1;
        }
    }

    count = 1;
    int sum3 = 0;
    bef = S3[0];

    for (int i = 1; i < N; i++) {
        if (S3[i] == bef) {
            count++;
            if (i == N - 1) {
                sum3 += count - 1;
            }
        } else {
            bef = S3[i];
            sum3 += count - 1;
            count = 1;
        }
    }

    cout << max(sum1, sum3) << endl;

    return 0;
}

// <END-OF-CODE>
