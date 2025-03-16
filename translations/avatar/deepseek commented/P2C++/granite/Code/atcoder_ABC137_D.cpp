

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < n; i++) {
        int day, salary;
        cin >> day >> salary;
        pq.push({-day, salary});
    }

    int days_left = m;
    vector<int> chosen_salaries;
    while (!pq.empty()) {
        int day = -pq.top().first;
        int salary = pq.top().second;
        pq.pop();

        if (days_left >= day) {
            chosen_salaries.push_back(salary);
            days_left -= day;
        } else {
            if (!chosen_salaries.empty() && salary > chosen_salaries.back()) {
                chosen_salaries.pop_back();
                chosen_salaries.push_back(salary);
            }
        }
    }

    int sum_salaries = 0;
    for (int salary : chosen_salaries) {
        sum_salaries += salary;
    }
    cout << sum_salaries << endl;

    return 0;
}

