
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Define a structure to store connection details
struct Date
{
    int go, back, cost;
};

// Define the maximum number of nodes and the distance array
int n, d[100000];
vector<Date> a;

// Declare the root function
void root(int);

int main()
{
    // Declare variables for iteration and input
    int i, j, k, u, count = 0;

    // Read the number of nodes
    cin >> n;

    // Read each node's connections and store them in the vector 'a'
    for (i = 0; i < n; i++)
    {
        cin >> u >> k;
        for (j = 0; j < k; j++)
        {
            Date temp;
            cin >> temp.go >> temp.cost;
            temp.back = u;
            a.push_back(temp);
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
        d[i] = 1000000;
    d[0] = 0;

    // Use a priority queue to update distances based on connections
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push(make_pair(0, 0));

    while (!q.empty())
    {
        int now = q.top().second;
        int now_cost = q.top().first;
        q.pop();

        if (now_cost > d[now])
            continue;

        for (i = 0; i < b; i++)
        {
            if (a[i].back == now && now_cost + a[i].cost < d[a[i].go])
            {
                d[a[i].go] = now_cost + a[i].cost;
                q.push(make_pair(d[a[i].go], a[i].go));
            }
        }
    }
}

