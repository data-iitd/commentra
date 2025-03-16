#include <iostream>
#include <string>
using namespace std;

int main()
{
    int i, sum = 0;
    int flag = 0;
    string x;
    while (true) {
        cin >> x;
        if (x[0] == '0') break;
        sum = 0;
        for (i = 0; i < x.length(); i++) {
            sum += x[i] - '0';
        }
        cout << sum << endl;
    }
    return 0;
}

