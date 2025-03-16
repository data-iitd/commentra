#include <iostream>
using namespace std;
int main()
{
    int A, B, amari, result;
    cin >> A >> B;
    result = (B - 1) / (A - 1);
    amari = (B - 1) % (A - 1);
    if (amari!= 0)
        result += 1;
    cout << result << endl;
    return 0;
}
