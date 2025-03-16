#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

vector<int> connect[];
int visited[];
bool odd[];
string print;

void dfs(int crt, int parent) {
    visited[crt] = 1;
    vector<int> crtConnect = connect[crt];
    for (int child : crtConnect) {
        if (child == parent || visited[child] == 1) {
            continue;
        } else if (visited[child] == 2) {
            print += to_string(crt + 1) + " " + to_string(child + 1) + "\n";
            odd[crt] = !odd[crt];
        } else {
            dfs(child, crt);
            if (odd[child]) {
                print += to_string(child + 1) + " " + to_string(crt + 1) + "\n";
                odd[child] = !odd[child];
            } else {
                print += to_string(crt + 1) + " " + to_string(child + 1) + "\n";
                odd[crt] = !odd[crt];
            }
        }
    }
    visited[crt] = 2;
}

int main() {
    int numNode, numEdge;
    cin >> numNode >> numEdge;
    connect = new vector<int>[numNode];
    for (int i = 0; i < numNode; i++) {
        connect[i] = vector<int>();
    }
    for (int i = 0; i < numEdge; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        connect[a].push_back(b);
        connect[b].push_back(a);
    }
    if (numEdge % 2 != 0) {
        cout << -1 << endl;
        return 0;
    }
    visited = new int[numNode];
    odd = new bool[numNode];
    print = "";
    dfs(0, -1);
    cout << print;
    delete[] connect;
    delete[] visited;
    delete[] odd;
    return 0;
}

