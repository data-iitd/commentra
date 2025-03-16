#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    string n;
    cin >> n;
    vector<string> a = { "10", "100", "1000", "10000", "100000" };
    int new = 0;
    for ( int i = 0 ; i < n.size() ; i++ )
    {
        new += ( int ) n[i] - 48;
    }
    if ( find ( a.begin(), a.end(), n )!= a.end() )
    {
        cout << 10 << endl;
    }
    else
    {
        cout << new << endl;
    }
    return 0;
}

