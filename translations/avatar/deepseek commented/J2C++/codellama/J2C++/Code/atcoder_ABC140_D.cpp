#include <iostream>
#include <string>

using namespace std;

int main() {
    int N, K;
    string S;
    
    cin >> N >> K >> S;
    
    char c1[N];
    char c3[N];
    
    bool flag = false;
    int count = 0;
    
    for (int i = 0; i < N; i++) {
        c1[i] = S[i];
        c3[i] = S[i];
    }
    
    // Process c1 (Left to Right)
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
    
    // Process c3 (Right to Left)
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
    
    string S1 = "";
    string S3 = "";
    
    for (int i = 0; i < N; i++) {
        S1 += c1[i];
        S3 += c3[i];
    }
    
    count = 1;
    int sum1 = 0;
    char bef = S1[0];
    
    // Count consecutive characters in S1
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
    
    // Count consecutive characters in S3
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
    
    // Print the maximum of the two sums
    cout << max(sum1, sum3) << endl;
    
    return 0;
}

