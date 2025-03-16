#include <iostream>
#include <string>

using namespace std;

int main()
{
    string mes;
    cin >> mes;
    cout << mes[0] << mes.length()-2 << mes[mes.length()-1] << endl;

    return 0;
}

