#include <iostream>

using namespace std;

int main()
{
    int candeleIntere, b;
    int s = 0, restoSciolte = 0;

    cin >> candeleIntere >> b;

    while (candeleIntere > 0 || restoSciolte >= b)
    {
        candeleIntere += restoSciolte / b;
        restoSciolte %= b;
        s += candeleIntere;
        restoSciolte += candeleIntere % b;
        candeleIntere /= b;
    }

    cout << s << endl;

    return 0;
}

