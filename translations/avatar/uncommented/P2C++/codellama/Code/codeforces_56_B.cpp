
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int A[N];
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    int mn = N + 1, mx = -1;
    for (int i = 0; i < N; i++)
    {
        if (i + 1 != A[i])
        {
            mn = min(mn, i);
            mx = max(mx, i);
        }
    }
    if (mx == -1)
    {
        cout << "0 0";
    }
    else
    {
        for (int i = mn; i <= mx; i++)
        {
            A[i] = A[i + 1];
        }
        if (is_sorted(A, A + N))
        {
            cout << mn + 1 << " " << mx + 1;
        }
        else
        {
            cout << "0 0";
        }
    }
    return 0;
}

