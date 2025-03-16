#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int numNode, numEdge;
    cin >> numNode >> numEdge;
    
    vector<int> connect[numNode];
    for (int i = 0; i < numEdge; i++) {
        int a, b;
        cin >> a >> b;
        connect[a - 1].push_back(b - 1);
        connect[b - 1].push_back(a - 1);
    }
    
    if (numEdge % 2!= 0) {
        cout << -1 << "\n";
        return 0;
    }
    
    int visited[numNode];
    bool odd[numNode];
    string print;
    
    dfs(0, -1, connect, visited, odd, print);
    
    cout << print;
}

void dfs(int crt, int parent, vector<int> connect[], int visited[], bool odd[], string &print) {
    visited[crt] = 1;
    for (int child : connect[crt]) {
        if (child == parent || visited[child] == 1) {
            continue;
        } else if (visited[child] == 2) {
            print += to_string(crt + 1) + " " + to_string(child + 1) + "\n";
            odd[crt] =!odd[crt];
        } else {
            dfs(child, crt, connect, visited, odd, print);
            if (odd[child]) {
                print += to_string(child + 1) + " " + to_string(crt + 1) + "\n";
                odd[child] =!odd[child];
            } else {
                print += to_string(crt + 1) + " " + to_string(child + 1) + "\n";
                odd[crt] =!odd[crt];
            }
        }
    }
    visited[crt] = 2;
}

