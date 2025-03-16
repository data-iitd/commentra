

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> lista(a);
    for (int i = 0; i < a; i++) {
        cin >> lista[i];
    }
    vector<int> listb(b);
    for (int i = 0; i < b; i++) {
        cin >> listb[i];
    }
    for (int k = 0; k < n; k++) {
        if (find(lista.begin(), lista.end(), k + 1)!= lista.end()) {
            cout << 1 << " ";
        } else {
            cout << 2 << " ";
        }
    }
    return 0;
}
// The first line takes three integers n, a, and b as input, separated by spaces.
// The second line takes a list of integers lista as input, separated by spaces.
// The third line takes a list of integers listb as input, separated by spaces.
// The for loop iterates over the range n.
// The if statement checks if the current index k + 1 is in the list lista.
// If it is, it prints 1 to the console. Otherwise, it prints 2 to the console.
// The return statement ends the program.