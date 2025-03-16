#include <iostream>
#include <string>
using namespace std;
int main()
{
    string input_array[1000];
    int result = 0;
    cin >> input_array;
    for (int i = 0; i < 1000; i++)
    {
        result += 1;
        if (input_array[i] == "0")
            break;
    }
    cout << result << endl;
    return 0;
}
