#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <functional>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    auto gcd = [](int a, int b) { return gcd(b, a % b); };
    int gcd = accumulate(A.begin(), A.end(), 0, gcd);

    cout << gcd << endl;

    return 0;
}

