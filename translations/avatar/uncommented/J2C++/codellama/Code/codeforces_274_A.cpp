
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <set>
using namespace std;

int main()
{
    int n;
    long k;
    long arr[100000];
    set<long> set;
    scanf("%d", &n);
    scanf("%ld", &k);
    for (int i = 0; i < n; i++)
    {
        scanf("%ld", &arr[i]);
    }
    sort(arr, arr + n);
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] % k != 0)
        {
            count++;
            set.insert(arr[i]);
        }
        else if (!set.count(arr[i] / k))
        {
            count++;
            set.insert(arr[i]);
        }
    }
    printf("%d", count);
    return 0;
}

