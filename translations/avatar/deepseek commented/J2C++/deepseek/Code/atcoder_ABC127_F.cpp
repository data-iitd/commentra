#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <sstream>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::priority_queue<int> pqmax;
    std::priority_queue<int, std::vector<int>, std::greater<int>> pqmin;

    int t;
    std::cin >> t;
    std::cin.ignore(); // Ignore the newline character after reading t

    long long sumMin = 0, sumMax = 0, sumb = 0;
    int min = 0;

    while (t--) {
        std::string line;
        std::getline(std::cin, line);
        std::istringstream iss(line);
        std::string command;
        iss >> command;

        if (command == "2") {
            long long ans = min;
            ans *= pqmin.size();
            ans -= sumMin;
            long long ans1 = min;
            ans1 *= pqmax.size();
            ans1 = sumMax - ans1;
            std::cout << min << " " << (ans + ans1 + sumb) << "\n";
        } else {
            int in;
            iss >> in;
            long long value;
            iss >> value;
            sumb += value;

            if (in > min) {
                pqmax.push(in);
                sumMax += in;
            } else {
                pqmin.push(in);
                sumMin += in;
            }

            if (pqmin.size() > pqmax.size()) {
                sumMax += pqmin.top();
                sumMin -= pqmin.top();
                pqmax.push(pqmin.top());
                pqmin.pop();
            }

            if (pqmin.size() < pqmax.size()) {
                sumMax -= pqmax.top();
                sumMin += pqmax.top();
                pqmin.push(pqmax.top());
                pqmax.pop();
            }

            min = pqmin.top();
        }
    }

    return 0;
}

