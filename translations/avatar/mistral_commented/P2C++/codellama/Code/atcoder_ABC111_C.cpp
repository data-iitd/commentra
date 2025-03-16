#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> x(n);
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
    }
    vector<int> a, b;
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            a.push_back(x[i]);
        }
        else
        {
            b.push_back(x[i]);
        }
    }
    vector<int> cnta(100002, 0), cntb(100002, 0);
    for (int i = 0; i < n; i++)
    {
        cnta[a[i]]++;
        cntb[b[i]]++;
    }
    int vala = 0, valb = 0;
    int maxCnta = 0, maxCntb = 0;
    for (int i = 0; i < n; i++)
    {
        if (maxCnta < cnta[i])
        {
            vala = i;
            maxCnta = cnta[i];
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (maxCntb < cntb[i])
        {
            valb = i;
            maxCntb = cntb[i];
        }
    }
    if (valb != vala)
    {
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            if (i != vala && i != valb)
            {
                res++;
            }
        }
        cout << res << endl;
    }
    else
    {
        int resa = 0, resb = 0;
        for (int i = 0; i < n; i++)
        {
            if (i != vala)
            {
                resa++;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (i != valb)
            {
                resb++;
            }
        }
        cout << min(resa + resb, resa + resb) << endl;
    }
    return 0;
}

