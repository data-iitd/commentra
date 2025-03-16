
#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        cout << sub(a, b) << endl;
    }
    return 0;
}
int sub(int a, int b)
{
    int min = a < b ? a : b;
    int max = a > b ? a : b;
    int result = 0;
    while (min > 0)
    {
        result += max / min;
        max = max % min;
        int curr_min = min < max ? min : max;
        int curr_max = min > max ? min : max;
        min = curr_min;
        max = curr_max;
    }
    return result;
}
