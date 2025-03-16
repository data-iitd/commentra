
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> connect[100000];
int visited[100000];
bool odd[100000];
string print;

void dfs(int crt, int parent) {
    visited[crt] = 1;
    vector<int> crtConnect = connect[crt];
    for (int child : crtConnect) {
        if (child == parent || visited[child] == 1) {
            continue;
        } else if (visited[child] == 2) {
            print += to_string(crt + 1) + " " + to_string(child + 1) + "\n";
            odd[crt] =!odd[crt];
        } else {
            dfs(child, crt);
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

int main() {
    int numNode, numEdge;
    cin >> numNode >> numEdge;
    for (int i = 0; i < numNode; i++) {
        connect[i] = vector<int>();
    }
    for (int i = 0; i < numEdge; i++) {
        int a, b;
        cin >> a >> b;
        connect[a - 1].push_back(b - 1);
        connect[b - 1].push_back(a - 1);
    }
    if (numEdge % 2!= 0) {
        cout << -1 << endl;
        return 0;
    }
    dfs(0, -1);
    cout << print;
    return 0;
}
