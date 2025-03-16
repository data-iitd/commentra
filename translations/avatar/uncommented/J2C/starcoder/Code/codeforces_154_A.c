#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <ctype.h>
#include <limits.h>
#include <float.h>
#include <time.h>
#include <assert.h>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <deque>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
using namespace std;

int main()
{
    int N, K;
    scanf("%d %d", &N, &K);
    char arr[N];
    scanf("%s", arr);
    set<string> set;
    int res = 0;
    for (int k = 0; k < K; k++)
    {
        char input[100];
        scanf("%s", input);
        int a = 0, b = 0;
        for (int i = 0; i < N; i++)
        {
            if (arr[i] == input[0])
                a++;
            else if (arr[i] == input[1])
                b++;
            else
            {
                res += min(a, b);
                a = b = 0;
            }
        }
        res += min(a, b);
    }
    printf("%d\n", res);
    return 0;
}

