#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N;
    cin >> N;
    int A[5];
    for (int i = 0; i < 5; i++)
    {
        cin >> A[i];
    }
    cout << ceil(N / *min_element(A, A + 5)) + 4 << endl;
    return 0;
}
