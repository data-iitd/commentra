#include <iostream>
#include <vector>
#include <climits>

using namespace std;

#define N 100000
#define INF INT_MAX

struct Date
{
    int go, back, cost;
};

int n, d[N];
vector<Date> a;
void root(int);

int main()
{
    int i, j, k, u, count = 0;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> u >> k;
        for (j = 0; j < k; j++)
        {
            Date temp;
            temp.back = u;
            cin >> temp.go >> temp.cost;
            a.push_back(temp);
            count++;
        }
    }
    root(count);
    for (i = 0; i < n; i++)
        cout << i << " " << d[i] << endl;
    return 0;
}

void root(int b)
{
    int i, flag = 1;

    for (i = 0; i < n; i++)
        d[i] = INF;
    d[0] = 0;

    while (flag != 0)
    {
        flag = 0;
        for (i = 0; i < b; i++)
        {
            if (a[i].cost + d[a[i].back] < d[a[i].go])
            {
                d[a[i].go] = a[i].cost + d[a[i].back];
                flag = 1;
            }
        }
    }
}

