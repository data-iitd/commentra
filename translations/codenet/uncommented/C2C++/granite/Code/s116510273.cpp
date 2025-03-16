
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string mes;
    getline(cin,mes);
    cout << mes[0] << mes.size()-2 << mes[mes.size()-1] << endl;

    return 0;
}
