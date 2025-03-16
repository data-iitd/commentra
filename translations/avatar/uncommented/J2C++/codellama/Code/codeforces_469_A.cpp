
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <cstdlib>
#include <vector>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <bitset>
#include <deque>
#include <set>
#include <sstream>
using namespace std;

int main()
{
    int n, levels, sum, sum2, sum3, count;
    int *arr, *arr2, *arr3;
    int level2, level3;
    cin >> n >> levels;
    arr = new int[levels];
    arr2 = new int[levels + level2];
    arr3 = new int[n];
    for (int i = 0; i < levels; i++)
    {
        cin >> arr[i];
    }
    cin >> level2;
    for (int i = 0; i < levels; i++)
    {
        arr2[i] = arr[i];
    }
    for (int i = levels; i < levels + level2; i++)
    {
        cin >> arr2[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> arr3[i];
    }
    count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int x = 0; x < levels + level2; x++)
        {
            if (arr3[i] == arr2[x])
            {
                count++;
                break;
            }
        }
    }
    if (count == n)
    {
        cout << "I become the guy." << endl;
    }
    else
    {
        cout << "Oh, my keyboard!" << endl;
    }
    return 0;
}

