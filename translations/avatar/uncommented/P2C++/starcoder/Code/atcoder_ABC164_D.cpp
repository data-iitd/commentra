#include <iostream>
#include <vector>
using namespace std;
int main()
{
    string s;
    int l = 2019;
    vector<int> m(l+1,0);
    int a = 0, r = 0;
    for (int i = 0; i < s.length(); i++)
    {
        a += (int)(s[i]) * pow(10,i,l);
        r += m[a%l];
        m[a%l]++;
    }
    cout << r << endl;
    return 0;
}
