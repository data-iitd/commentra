#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> list;
    string input;
    getline(cin, input);
    stringstream ss(input);
    int temp;
    while (ss >> temp)
    {
        list.push_back(temp % 2);
    }

    if (accumulate(list.begin(), list.end(), 0) == 1)
    {
        cout << "The first number with remainder 1 is: " << find(list.begin(), list.end(), 1) - list.begin() + 1 << endl;
    }
    else
    {
        cout << "The first number with remainder 0 is: " << find(list.begin(), list.end(), 0) - list.begin() + 1 << endl;
    }

    return 0;
}

