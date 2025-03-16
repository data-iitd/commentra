#include <iostream>
using namespace std;

int main()
{
    int n, k, m, j, p, l;
    cin >> n >> k;
    int M[n];
    for (int i = 0; i < n; i++)
        cin >> M[i];
    m = 0;
    for (j = 0; j < n; j++)
    {
        for (p = 0; p < n; p++)
        {
            if (M[p] == 0)
            {
                cout << p + 1 << " ";
                break;
            }
        }
        for (l = p + 1 - k; l < p; l++)
            M[l]--;
        M[p]--;
    }
    return 0;
}
