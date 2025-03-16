
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <bitset>
#include <deque>
#include <set>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <climits>
#include <utility>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int square = n * n;
    vector<int> odd;
    vector<int> even;
    for (int i = 1; i <= square; i++)
    {
        if (i % 2 == 0)
        {
            even.push_back(i);
        }
        else
        {
            odd.push_back(i);
        }
    }
    int loop = square / n;
    int div = loop / 2;
    // debug(div);
    for (int i = 1; i <= loop; i++)
    {
        for (int j = 0; j < div; j++)
        {
            if (i % 2 == 1)
            {
                cout << odd[j] << " " << even[even.size() - 1 - j] << " ";
            }
            else
            {
                cout << even[j] << " " << odd[odd.size() - 1 - j] << " ";
            }
        }
        cout << endl;
    }
    return 0;
}

