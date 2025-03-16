
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> li;
    int ind = 0;

    for (int i = 1; i <= 370; i++) {
        std::vector<int> temp;
        int p = i, q = i, count = 0;

        while (p!= 0) {
            p /= 10;
            count++;
        }

        if (count == 1) {
            li.push_back(i);
        }

        if (count == 2) {
            temp.clear();
            while (q!= 0) {
                int x = q % 10;
                q /= 10;
                temp.push_back(x);
            }
            li.insert(li.end(), temp.rbegin(), temp.rend());
        }

        if (count == 3) {
            temp.clear();
            while (q!= 0) {
                int x = q % 10;
                q /= 10;
                temp.push_back(x);
            }
            li.insert(li.end(), temp.rbegin(), temp.rend());
        }
    }

    li.pop_back();
    li.pop_back();

    int n;
    std::cin >> n;
    std::cout << li[n - 1] << std::endl;

    return 0;
}
