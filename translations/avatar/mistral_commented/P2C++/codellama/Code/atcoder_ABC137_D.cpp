#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to calculate the sum of salaries of employees in the list 'y'
int sum_salaries(vector<int> y) {
    int sum = 0;
    for (int i = 0; i < y.size(); i++) {
        sum += y[i];
    }
    return sum;
}

int main() {
    // Taking input of number of days and number of employees
    int n, m;
    cin >> n >> m;

    // Initializing empty lists for storing days and salaries
    vector<int> x;
    vector<int> y;

    // Iterating through each employee and adding their details to the heap 'x'
    for (int i = 0; i < n; i++) {
        int day, salary;
        cin >> day >> salary;
        // Adding employee details as a tuple to the heap 'x' with negative day and salary values
        x.push_back(-day);
        x.push_back(-salary);
    }

    // Simulation loop to check if an employee can be added to the list 'y'
    while (x.size() > 0) {
        // Popping the employee with minimum negative day from the heap 'x'
        int d = -x[0];
        int s = -x[1];
        x.erase(x.begin());
        x.erase(x.begin());
        // Calculating the remaining capacity in the list 'y'
        int r = m - y.size();
        // Checking if the remaining capacity is enough to add the current employee
        if (r >= d) {
            // If yes, adding the salary of the employee to the list 'y'
            y.push_back(s);
        } else {
            // If no, removing an employee with minimum salary from the list 'y' and adding the current employee
            sort(y.begin(), y.end());
            y.erase(y.begin());
            y.push_back(s);
        }
    }

    // Printing the sum of salaries of employees in the list 'y'
    cout << sum_salaries(y) << endl;

    return 0;
}

