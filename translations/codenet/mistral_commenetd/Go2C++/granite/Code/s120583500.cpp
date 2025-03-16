

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int main() {
    std::string s;
    std::cin >> s;

    int count = 0;
    std::vector<int> counter;
    counter.push_back(0);

    if (s == "") {
        return 0;
    }

    std::vector<char> li(s.begin(), s.end());

    for (char c : li) {
        if (c == 'A' || c == 'C' || c == 'G' || c == 'T') {
            count++;
        } else {
            counter.push_back(count);
            count = 0;
        }
    }

    counter.push_back(count);

    std::sort(counter.begin(), counter.end());

    std::cout << counter[counter.size() - 1] << std::endl;

    return 0;
}

