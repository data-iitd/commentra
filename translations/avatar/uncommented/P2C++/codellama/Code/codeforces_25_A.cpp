
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> list;
    stringstream ss(s);
    int temp;
    while (ss >> temp)
    {
        list.push_back(temp % 2);
    }
    int sum = 0;
    for (int i = 0; i < list.size(); i++)
    {
        sum += list[i];
    }
    if (sum == 1)
    {
        cout << list.size() - list.end() + 1 << endl;
    }
    else
    {
        cout << list.end() - list.begin() + 1 << endl;
    }
    return 0;
}

