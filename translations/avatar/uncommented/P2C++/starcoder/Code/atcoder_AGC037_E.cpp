#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N, K;
    cin >> N >> K;
    string S;
    cin >> S;
    bool aaaa = false;
    if (K >= 15)
        aaaa = true;
    else if (2 ** K >= N)
        aaaa = true;
    if (aaaa)
    {
        cout << min(S) * N << endl;
        return 0;
    }
    string U = S + S;
    U = U.substr(0, N);
    int minindex = 0;
    int c = min(S);
    for (int i = 0; i < N; i++)
    {
        if (U[i] == c)
        {
            if (check_normal_dict(U, minindex, i))
                minindex = i;
        }
    }
    string ans = U.substr(minindex, N);
    cout << ans << endl;
    return 0;
}
bool check_normal_dict(string U, int pointer1, int pointer2)
{
    for (int i = 0; i < N; i++)
    {
        if (U[pointer1 + i] > U[pointer2 + i])
            return true;
        else if (U[pointer1 + i] < U[pointer2 + i])
            return false;
    }
    return false;
}
