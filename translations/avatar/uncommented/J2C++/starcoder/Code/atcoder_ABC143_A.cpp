#include <iostream>
using namespace std;
int main()
{
    try
    {
        int a, b, c;
        cin >> a >> b;
        c = a - b * 2;
        if (c < 0) c = 0;
        cout << c << endl;
    }
    catch (exception& e)
    {
    }
    return 0;
}
