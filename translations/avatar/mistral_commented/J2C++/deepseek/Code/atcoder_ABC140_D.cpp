#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int N, K;
    string S;
    cin >> N >> K >> S;

    char c1[N], c3[N];
    copy(S.begin(), S.end(), c1);
    copy(S.begin(), S.end(), c3);

    bool flag1 = false;
    int count1 = 0;

    for (int i = 0; i < N; i++) {
        if (flag1 && c1[i] == 'R') {
            flag1 = false;
            count1++;
        }
        if (count1 == K) {
            break;
        }
        if (c1[i] == 'L') {
            flag1 = true;
        }
    }

    bool flag3 = false;
    int count3 = 0;

    for (int i = 0; i < N; i++) {
        if (flag3 && c3[i] == 'L') {
            flag3 = false;
            count3++;
        }
        if (count3 == K) {
            break;
        }
        if (c3[i] == 'R') {
            flag3 = true;
        }
    }

    string S1(c1, N);
    string S3(c3, N);

    int count2 = 1;
    int sum1 = 0;
    char bef1 = S1[0];

    for (int i = 1; i < N; i++) {
        if (S1[i] == bef1) {
            count2++;
        } else {
            sum1 += count2 - 1;
            count2 = 1;
            bef1 = S1[i];
        }
    }
    sum1 += count2 - 1;

    int count4 = 1;
    int sum3 = 0;
    char bef3 = S3[0];

    for (int i = 1; i < N; i++) {
        if (S3[i] == bef3) {
            count4++;
        } else {
            sum3 += count4 - 1;
            count4 = 1;
            bef3 = S3[i];
        }
    }
    sum3 += count4 - 1;

    cout << max(sum1, sum3) << endl;

    return 0;
}

