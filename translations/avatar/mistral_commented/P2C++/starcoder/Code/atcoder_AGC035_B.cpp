#include <bits/stdc++.h>
using namespace std;

// Function to print edges of a graph
void printEdges(vector<vector<int>> &edges, int N, int M)
{
    // Iterate through all edges
    for (int i = 0; i < M; i++)
    {
        // Print edge
        cout << edges[i][0] + 1 << " " << edges[i][1] + 1 << endl;
    }
}

// Function to find odd vertices and print their edges
void printOddVertices(vector<vector<int>> &edges, vector<int> &degs, int N, int M)
{
    // Initialize empty list Q to store vertices based on their degrees
    list<pair<int, int>> Q;

    // Iterate through all vertices and add them to Q based on their degrees
    for (int i = 0; i < N; i++)
    {
        Q.push_back({degs[i], i});
    }

    // Sort Q based on degrees
    Q.sort();

    // Initialize empty list to store odd vertices
    list<int> oddVertices;

    // Initialize empty list to store edges of odd vertices
    list<vector<int>> oddEdges;

    // Initialize empty list to store edges of even vertices
    list<vector<int>> evenEdges;

    // Initialize empty list to store edges of odd vertices
    list<vector<int>> oddEdges;

    // Initialize empty list to store edges of even vertices
    list<vector<int>> evenEdges;

    // Initialize parity array to keep track of parity of each vertex
    vector<int> parity(N, 0);

    // Initialize flag array to keep track of visited vertices
    vector<bool> flag(N, false);

    // Iterate through Q until it is empty
    while (!Q.empty())
    {
        // Get vertex with minimum degree from Q
        int u = Q.front().second;
        Q.pop_front();
        // Skip if vertex is already visited
        if (flag[u])
        {
            continue;
        }
        // Mark vertex as visited
        flag[u] = true;
        // Iterate through all adjacent vertices and print their edges and update their parity
        for (int i = 0; i < edges[u].size(); i++)
        {
            // Skip if vertex is already visited
            if (flag[edges[u][i]])
            {
                continue;
            }
            // Print edge and update parity of both vertices
            if (parity[u]!= 0 && i == 0)
            {
                cout << u + 1 << " " << edges[u][i] + 1 << endl;
                parity[u] = 1 - parity[u];
            }
            else
            {
                cout << edges[u][i] + 1 << " " << u + 1 << endl;
                parity[edges[u][i]] = 1 - parity[edges[u][i]];
            }
            // Decrease degree of adjacent vertex and add it to Q
            degs[edges[u][i]] -= 1;
            Q.push_back({degs[edges[u][i]], edges[u][i]});
        }
    }
}

// Function to find even vertices and print their edges
void printEvenVertices(vector<vector<int>> &edges, vector<int> &degs, int N, int M)
{
    // Initialize empty list Q to store vertices based on their degrees
    list<pair<int, int>> Q;

    // Iterate through all vertices and add them to Q based on their degrees
    for (int i = 0; i < N; i++)
    {
        Q.push_back({degs[i], i});
    }

    // Sort Q based on degrees
    Q.sort();

    // Initialize empty list to store odd vertices
    list<int> evenVertices;

    // Initialize empty list to store edges of odd vertices
    list<vector<int>> oddEdges;

    // Initialize empty list to store edges of even vertices
    list<vector<int>> evenEdges;

    // Initialize empty list to store edges of odd vertices
    list<vector<int>> oddEdges;

    // Initialize empty list to store edges of even vertices
    list<vector<int>> evenEdges;

    // Initialize parity array to keep track of parity of each vertex
    vector<int> parity(N, 0);

    // Initialize flag array to keep track of visited vertices
    vector<bool> flag(N, false);

    // Iterate through Q until it is empty
    while (!Q.empty())
    {
        // Get vertex with minimum degree from Q
        int u = Q.front().second;
        Q.pop_front();
        // Skip if vertex is already visited
        if (flag[u])
        {
            continue;
        }
        // Mark vertex as visited
        flag[u] = true;
        // Iterate through all adjacent vertices and print their edges and update their parity
        for (int i = 0; i < edges[u].size(); i++)
        {
            // Skip if vertex is already visited
            if (flag[edges[u][i]])
            {
                continue;
            }
            // Print edge and update parity of both vertices
            if (parity[u]!= 0 && i == 0)
            {
                cout << u + 1 << " " << edges[u][i] + 1 << endl;
                parity[u] = 1 - parity[u];
            }
            else
            {
                cout << edges[u][i] + 1 << " " << u + 1 << endl;
                parity[edges[u][i]] = 1 - parity[edges[u][i]];
            }
            // Decrease degree of adjacent vertex and add it to Q
            degs[edges[u][i]] -= 1;
            Q.push_back({degs[edges[u][i]], edges[u][i]});
        }
    }
}

// Function to find odd vertices and print their edges
void printOddVertices(vector<vector<int>> &edges, vector<int> &degs, int N, int M)
{
    // Initialize empty list Q to store vertices based on their degrees
    list<pair<int, int>> Q;

    // Iterate through all vertices and add them to Q based on their degrees
    for (int i = 0; i < N; i++)
    {
        Q.push_back({degs[i], i});
    }

    // Sort Q based on degrees
    Q.sort();

    // Initialize empty list to store odd vertices
    list<int> oddVertices;

    // Initialize empty list to store edges of odd vertices
    list<vector<int>> oddEdges;

    // Initialize empty list to store edges of even vertices
    list<vector<int>> evenEdges;

    // Initialize empty list to store edges of odd vertices
    list<vector<int>> oddEdges;

    // Initialize empty list to store edges of even vertices
    list<vector<int>> evenEdges;

    // Initialize parity array to keep track of parity of each vertex
    vector<int> parity(N, 0);

    // Initialize flag array to keep track of visited vertices
    vector<bool> flag(N, false);

    // Iterate through Q until it is empty
    while (!Q.empty())
    {
        // Get vertex with minimum degree from Q
        int u = Q.front().second;
        Q.pop_front();
        // Skip if vertex is already visited
        if (flag[u])
        {
            continue;
        }
        // Mark vertex as visited
        flag[u] = true;
        // Iterate through all adjacent vertices and print their edges and update their parity
        for (int i = 0; i < edges[u].size(); i++)
        {
            // Skip if vertex is already visited
            if (flag[edges[u][i]])
            {
                continue;
            }
            // Print edge and update parity of both vertices
            if (parity[u]!= 0 && i == 0)
            {
                cout << u + 1 << " " << edges[u][i] + 1 << endl;
                parity[u] = 1 - parity[u];
            }
            else
            {
                cout << edges[u][i] + 1 << " " << u + 1 << endl;
                parity[edges[u][i]] = 1 - parity[edges[u][i]];
            }
            // Decrease degree of adjacent vertex and add it to Q
            degs[edges[u][i]] -= 1;
            Q.push_back({degs[edges[u][i]], edges[u][i]});
        }
    }
}

// Function to find even vertices and print their edges
void printEvenVertices(vector<vector<int>> &edges, vector<int> &degs, int N, int M)
{
    // Initialize empty list Q to store vertices based on their degrees
    list<pair<int, int>> Q;

    // Iterate through all vertices and add them to Q based on their degrees
    for (int i = 0; i < N; i++)
    {
        Q.push_back({degs[i], i});
    }

    // Sort Q based on degrees
    Q.sort();

    // Initialize empty list to store odd vertices
    list<int> evenVertices;

    // Initialize empty list to store edges of odd vertices
    list<vector<int>> oddEdges;

    // Initialize empty list to store edges of even vertices
    list<vector<int>> evenEdges;

    // Initialize empty list to store edges of odd vertices
    list<vector<int>> oddEdges;

    // Initialize empty list to store edges of even vertices
    list<vector<int>> evenEdges;

    // Initialize parity array to keep track of parity of each vertex
    vector<int> parity(N, 0);

    // Initialize flag array to keep track of visited vertices
    vector<bool> flag(N, false);

    // Iterate through Q until it is empty
    while (!Q.empty())
    {
        // Get vertex with minimum degree from Q
        int u = Q.front().second;
        Q.pop_front();
        // Skip if vertex is already visited
        if (flag[u])
        {
            continue;
        }
        // Mark vertex as visited
        flag[u] = true;
        // Iterate through all adjacent vertices and print their edges and update their parity
        for (int i = 0; i < edges[u].size(); i++)
        {
            // Skip if vertex is already visited
            if (flag[edges[u][i]])
            {
                continue;
            }
            // Print edge and update parity of both vertices
            if (parity[u]!= 0 && i == 0)
            {
                cout << u + 1 << " " << edges[u][i] + 1 << endl;
                parity[u] = 1 - parity[u];
            }
            else
            {
                cout << edges[u][i] + 1 << " " << u + 1 << endl;
                parity[edges[u][i]] = 1 - parity[edges[u][i]];
            }
            // Decrease degree of adjacent vertex and add it to Q
            degs[edges[u][i]] -= 1;
            Q.push_back({degs[edges[u][i]], edges[u][i]});
        }
    }
}

// Function to find odd vertices and print their edges
void printOddVertices(vector<vector<int>> &edges, vector<int> &degs, int N, int M)
{
    // Initialize empty list Q to store vertices based on their degrees
    list<pair<int, int>> Q;

    // Iterate through all vertices and add them to Q based on their degrees
    for (int i = 0; i < N; i++)
    {
        Q.push_back({deg