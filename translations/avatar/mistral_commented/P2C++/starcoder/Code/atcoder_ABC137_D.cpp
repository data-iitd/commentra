#include <bits/stdc++.h>
using namespace std;

// Function to check if an employee can be added to the list 'y'
bool check(int d, int s, int m, int n, vector<int> &x, vector<int> &y)
{
    // Calculating the remaining capacity in the list 'y'
    int r = m - y.size();
    // If the remaining capacity is enough to add the current employee
    if (r >= d)
    {
        // If yes, adding the salary of the employee to the list 'y'
        y.push_back(s);
        return true;
    }
    else
    {
        // If no, removing an employee with minimum salary from the list 'y' and adding the current employee
        y.push_back(s);
        y.pop_back();
        return false;
    }
}

// Driver code
int main()
{
    // Taking input of number of days and number of employees
    int n, m;
    cin >> n >> m;

    // Initializing empty lists for storing days and salaries
    vector<int> x, y;

    // Iterating through each employee and adding their details to the heap 'x'
    for (int i = 0; i < n; i++)
    {
        int day, salary;
        cin >> day >> salary;
        // Adding employee details as a tuple to the heap 'x' with negative day and salary values
        x.push_back(-day);
        x.push_back(-salary);
    }

    // Sorting the heap 'x' in ascending order
    sort(x.begin(), x.end());

    // Simulation loop to check if an employee can be added to the list 'y'
    while (x.size())
    {
        // Popping the employee with minimum negative day from the heap 'x'
        int d = x.back();
        x.pop_back();
        int s = x.back();
        x.pop_back();
        // Checking if the remaining capacity is enough to add the current employee
        if (check(d, s, m, n, x, y))
        {
            // If yes, adding the salary of the employee to the list 'y'
            continue;
        }
        else
        {
            // If no, removing an employee with minimum salary from the list 'y' and adding the current employee
            y.pop_back();
            y.push_back(s);
        }
    }

    // Printing the sum of salaries of employees in the list 'y'
    cout << -y[0];

    return 0;
}

