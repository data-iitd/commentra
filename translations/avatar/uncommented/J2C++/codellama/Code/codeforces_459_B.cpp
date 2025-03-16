#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
    int N;
    cin >> N;
    int A[N];
    for (int n = 0; n < N; n++)
    {
        cin >> A[n];
    }
    sort(A, A + N);
    int min = A[0];
    int max = A[N - 1];
    long mins = 0;
    long maxs = 0;
    for (int value : A)
    {
        if (value == min)
            mins++;
        if (value == max)
            maxs++;
    }
    if (min == max)
    {
        cout << (max - min) << " " << mins * (mins - 1) / 2 << endl;
    }
    else
    {
        cout << (max - min) << " " << mins * maxs << endl;
    }
    return 0;
}
