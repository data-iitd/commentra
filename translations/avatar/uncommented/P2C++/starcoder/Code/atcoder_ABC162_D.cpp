#include <iostream>
#include <string>
using namespace std;
int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int rNum = 0, gNum = 0, bNum = 0, sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'R')
            rNum++;
        if (s[i] == 'G')
            gNum++;
        if (s[i] == 'B')
            bNum++;
    }
    for (int step = 1; step <= (n + 1) / 2; step++)
    {
        for (int i = 0; i < n - 2 * step; i++)
        {
            string s = s.substr(i, step) + s.substr(i + step, step) + s.substr(i + 2 * step, step);
            if (s == "RGB" || s == "RBG" || s == "BGR" || s == "BRG" || s == "GBR" || s == "GRB")
                sum++;
        }
    }
    cout << rNum * gNum * bNum - sum << endl;
    return 0;
}
