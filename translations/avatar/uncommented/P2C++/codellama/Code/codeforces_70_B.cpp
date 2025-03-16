#include <iostream>
#include <string>
#include <cstring>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int ans = 1, sumL = 0;
    string s;
    while (getline(cin, s))
    {
        s = s.substr(0, s.length() - 1);
        int L = s.length();
        if (L > 1)
        {
            if (L > n)
            {
                cout << "Impossible" << endl;
                return 0;
            }
            if (sumL + L + (sumL > 0) > n)
            {
                ans++;
                sumL = L;
            }
            else
            {
                sumL = sumL + L + (sumL > 0);
            }
        }
    }
    cout << ans << endl;
    return 0;
}