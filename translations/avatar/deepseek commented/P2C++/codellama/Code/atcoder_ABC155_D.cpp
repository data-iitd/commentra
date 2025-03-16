
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;
    int A[N];
    for (int i = 0; i < N; i++)
        cin >> A[i];
    sort(A, A + N);

    int ll = -1000000000 - 1;
    int rr = 1000000000 + 1;

    while (ll + 1 < rr)
    {
        int x = (ll + rr) / 2;
        int tot = 0;

        for (int i = 0; i < N; i++)
        {
            if (A[i] < 0)
            {
                int l = -1;
                int r = N;
                while (l + 1 < r)
                {
                    int c = (l + r) / 2;
                    if (A[i] * A[c] < x)
                        r = c;
                    else
                        l = c;
                }
                tot += N - r;
            }
            else
            {
                int l = -1;
                int r = N;
                while (l + 1 < r)
                {
                    int c = (l + r) / 2;
                    if (A[i] * A[c] < x)
                        l = c;
                    else
                        r = c;
                }
                tot += r;
            }

            if (A[i] * A[i] < x)
                tot--;
        }

        tot /= 2;

        if (tot < K)
            ll = x;
        else
            rr = x;
    }

    cout << ll << endl;

    return 0;
}

