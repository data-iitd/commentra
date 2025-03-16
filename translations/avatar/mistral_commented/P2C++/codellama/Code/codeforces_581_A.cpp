#include <iostream>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;

    int min_value = min(a, b);
    int max_value = max(a, b);

    cout << min_value << " " << (max_value - min_value) / 2 << endl;

    return 0;
}
