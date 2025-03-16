
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int N, K;
    string S;
    cin >> N >> K >> S;
    
    string S1 = S, S3 = S;
    bool flag = false;
    int count = 0;
    
    // Process S1 (Left to Right)
    for (int i = 0; i < N; i++) {
        if (flag && S1[i] == 'R') {
            flag = false;
            count++;
        }
        if (count == K) {
            break;
        }
        if (S1[i] == 'L') {
            flag = true;
            S1[i] = 'R';
        }
    }
    
    flag = false;
    count = 0;
    
    // Process S3 (Right to Left)
    for (int i = 0; i < N; i++) {
        if (flag && S3[i] == 'L') {
            flag = false;
            count++;
        }
        if (count == K) {
            break;
        }
        if (S3[i] == 'R') {
            flag = true;
            S3[i] = 'L';
        }
    }
    
    int sum1 = 0, sum3 = 0;
    int count1 = 1, count3 = 1;
    char bef1 = S1[0], bef3 = S3[0];
    
    // Count consecutive characters in S1
    for (int i = 1; i < N; i++) {
        if (S1[i] == bef1) {
            count1++;
            if (i == N - 1) {
                sum1 += count1 - 1;
            }
        } else {
            bef1 = S1[i];
            sum1 += count1 - 1;
            count1 = 1;
        }
    }
    
    // Count consecutive characters in S3
    for (int i = 1; i < N; i++) {
        if (S3[i] == bef3) {
            count3++;
            if (i == N - 1) {
                sum3 += count3 - 1;
            }
        } else {
            bef3 = S3[i];
            sum3 += count3 - 1;
            count3 = 1;
        }
    }
    
    // Print the maximum of the two sums
    cout << max(sum1, sum3) << endl;
    
    return 0;
}
