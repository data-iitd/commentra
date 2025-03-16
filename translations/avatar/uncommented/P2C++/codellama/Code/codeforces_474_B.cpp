
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    vector<int> L;
    string input;
    int r = 1;
    cin >> input;
    for (int i = 0; i < input.length(); i++)
    {
        L.insert(L.end(), r, input[i] - '0');
        r++;
    }
    cin >> input;
    for (int i = 0; i < input.length(); i++)
    {
        cout << L[input[i] - '0' - 1] << endl;
    }
    return 0;
}

