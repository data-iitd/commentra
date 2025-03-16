
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> li;
    int ind = 0;

    for (int i = 1; i <= 370; i++) {
        vector<int> temp;
        int p = i, q = i;
        int count = 0;

        while (p!= 0) {
            p /= 10;
            count++;
        }

        if (count == 1) {
            li.push_back(i);
        } else if (count == 2) {
            while (q!= 0) {
                int x = q % 10;
                q /= 10;
                temp.push_back(x);
            }
            li.insert(li.end(), temp.rbegin(), temp.rend());
        } else if (count == 3) {
            while (q!= 0) {
                int x = q % 10;
                q /= 10;
                temp.push_back(x);
            }
            li.insert(li.end(), temp.rbegin(), temp.rend());
        }
    }

    li.erase(li.begin());
    li.erase(li.begin());

    int n;
    cin >> n;

    cout << li[n-1] << endl;

    return 0;
}

