#include <bits/stdc++.h>

using namespace std;

#define N 100000
#define INF 1000000

// Define a structure to store connection details
typedef struct
{
    int go, back, cost;
} Date;

// Define the maximum number of nodes and the distance array
int n, d[N];
Date a[500000];

// Declare the root function
void root(int);

int main()
{
    // Declare variables for iteration and input
    int i, j, k, u, count = 0;

    // Read the number of nodes
    cin >> n;

    // Read each node's connections and store them in the array 'a'
    for (i = 0; i < n; i++)
    {
        cin >> u >> k;
        for (j = 0; j < k; j++)
        {
            a[count].back = u;
            cin >> a[count].go >> a[count].cost;
            count++;
        }
    }

    // Call the root function to initialize distances
    root(count);

    // Print the shortest distances from the root node to each node
    for (i = 0; i < n; i++)
        cout << i << " " << d[i] << endl;
    return 0;
}

// Function to initialize distances and update them based on connections
void root(int b)
{
    int i, flag = 1;

    // Initialize all distances to INF except the root node (node 0)
    for (i = 0; i < n; i++)
        d[i] = INF;
    d[0] = 0;

    // Use a while loop to update distances based on connections
    while (flag!= 0)
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

