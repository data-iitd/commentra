#include <iostream>
using namespace std;
int main()
{
    int N, P;
    cin >> N >> P;
    int a = 1;
    for (int i = 0; i < P; i++)
    {
        a *= N - i;
    }
    for (int j = 0; j < P; j++)
    {
        a /= j + 1;
    }
    cout << a << endl;
    return 0;
}
