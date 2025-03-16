#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    // Taking input of number of days and number of employees
    int n, m;
    cin >> n >> m;

    // Initializing a max heap for storing days and salaries
    priority_queue<pair<int, int>> x; // max heap for days and salaries
    priority_queue<int> y; // max heap for salaries

    // Iterating through each employee and adding their details to the heap 'x'
    for (int i = 0; i < n; i++) {
        int day, salary;
        cin >> day >> salary;
        // Adding employee details as a pair to the heap 'x' with negative day and salary values
        x.push(make_pair(day, salary));
    }

    // Simulation loop to check if an employee can be added to the list 'y'
    while (!x.empty()) {
        // Popping the employee with minimum day from the heap 'x'
        auto employee = x.top();
        x.pop();
        int d = employee.first; // days
        int s = employee.second; // salary

        // Calculating the remaining capacity in the list 'y'
        int r = m - y.size();
        // Checking if the remaining capacity is enough to add the current employee
        if (r >= d) {
            // If yes, adding the salary of the employee to the list 'y'
            y.push(s);
        } else {
            // If no, removing an employee with minimum salary from the list 'y' and adding the current employee
            y.push(s);
            y.pop();
        }
    }

    // Printing the sum of salaries of employees in the list 'y'
    int totalSalary = 0;
    while (!y.empty()) {
        totalSalary += y.top();
        y.pop();
    }
    cout << totalSalary << endl;

    return 0;
}

// <END-OF-CODE>
