#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

vector<int> connect[100005]; // Assuming a maximum of 100,000 nodes
int visited[100005];
bool odd[100005];
ostringstream print;

void dfs(int crt, int parent) {
    visited[crt] = 1;
    for (int child : connect[crt]) {
        if (child == parent || visited[child] == 1) {
            continue;
        } else if (visited[child] == 2) {
            print << (crt + 1) << " " << (child + 1) << "\n";
            odd[crt] = !odd[crt];
        } else {
            dfs(child, crt);
            if (odd[child]) {
                print << (child + 1) << " " << (crt + 1) << "\n";
                odd[child] = !odd[child];
            } else {
                print << (crt + 1) << " " << (child + 1) << "\n";
                odd[crt] = !odd[crt];
            }
        }
    }
    visited[crt] = 2;
}

int main() {
    int numNode, numEdge;
    cin >> numNode >> numEdge;

    for (int i = 0; i < numNode; i++) {
        connect[i].clear();
    }

    for (int i = 0; i < numEdge; i++) {
        int a, b;
        cin >> a >> b;
        connect[a - 1].push_back(b - 1);
        connect[b - 1].push_back(a - 1);
    }

    if (numEdge % 2 != 0) {
        cout << -1 << endl;
        return 0;
    }

    fill(visited, visited + numNode, 0);
    fill(odd, odd + numNode, false);
    dfs(0, -1);
    cout << print.str();
    
    return 0;
}

// <END-OF-CODE>
