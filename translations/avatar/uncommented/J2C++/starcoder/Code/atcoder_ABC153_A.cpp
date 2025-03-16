#include <iostream>
using namespace std;
int main()
{
    int h, a, num;
    cin >> h >> a;
    for (int i = 1; h > 0; i++)
    {
        h = h - a;
        num++;
    }
    cout << num << endl;
    return 0;
}
