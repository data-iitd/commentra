
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

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
    vector<pair<int, int>> dp;
    dp.push_back(make_pair(A[0], 0));
    for (int i = 1; i < N; i++)
    {
        if (A[i] <= dp.back().first)
        {
            dp.push_back(make_pair(A[i], 0));
        }
        else
        {
            int j = dp.size() - 1;
            while (j > 0 && dp[j].first < A[i])
            {
                j--;
            }
            dp.push_back(make_pair(A[i], dp[j].second + 1));
        }
    }
    int K = 0;
    for (int i = 0; i < dp.size(); i++)
    {
        K = max(K, dp[i].second);
    }
    cout << K << endl;
    return 0;
}

