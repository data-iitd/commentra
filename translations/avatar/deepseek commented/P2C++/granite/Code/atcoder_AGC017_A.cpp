
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Define a function to calculate the binomial coefficient
double combi(int N, int K) {
    double a = 1;
    // Calculate the product part of the binomial coefficient
    for (int i = 0; i < K; i++) {
        a *= N - i;
    }
    // Calculate the division part of the binomial coefficient
    for (int j = 0; j < K; j++) {
        a /= j + 1;
    }
    return a;
}

int main() {
    int N, P;
    cin >> N >> P;

    vector<int> lis(N);
    for (int i = 0; i < N; i++) {
        cin >> lis[i];
    }

    vector<int> ls;
    for (int a : lis) {
        ls.push_back(a % 2);
    }

    int one = count(ls.begin(), ls.end(), 1);
    int zero = count(ls.begin(), ls.end(), 0);

    double pattern_a = 0;
    double pattern_b = 0;

    for (int j = 0; j <= zero; j++) {
        pattern_b += combi(zero, j);
    }

    int time = 0;
    while (time <= one) {
        if (time % 2 == P) {
            pattern_a += combi(one, time);
        }
        time++;
    }

    cout << (int)(pattern_a * pattern_b) << endl;

    return 0;
}

