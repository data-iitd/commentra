
#include <iostream>
using namespace std;
int main()
{
    int n, c = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int l1[100];
        for (int j = 0; j < 100; j++)
        {
            cin >> l1[j];
        }
        int sum = 0;
        for (int j = 0; j < 100; j++)
        {
            sum += l1[j];
        }
        if (sum > 1)
        {
            c++;
        }
    }
    cout << c << endl;
    return 0;
}