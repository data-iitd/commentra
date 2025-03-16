#include <iostream>
#include <cmath>
using namespace std;

int main() {
    long long N, A, B;
    cin >> N >> A >> B;
    long long k = 0;
    if (1 <= N && N <= pow(10, 18) && 0 <= A && 0 <= B && 0 < A + B && A + B <= pow(10, 18)) {
        if (A + B <= N) {
            k = N / (A + B);
            if (N - k * (A + B) > A) {
                cout << A * k + (N - k * (A + B)) - (N - (k * (A + B) + A)) << endl;
            } else {
                cout << A * k + (N - k * (A + B)) << endl;
            }
        } else if (A + B > N && A <= N) {
            cout << A << endl;
        } else {
            cout << N << endl;
        }
    }
