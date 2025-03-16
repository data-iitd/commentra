#include <bits/stdc++.h>
using namespace std;

int main() {
    // Creating a Scanner object to read input from the console
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Scanner sc;
    sc.sync_with_stdio(0);
    sc.tie(0);
    sc.clear();
    
    // Reading the number of elements to be processed
    int n;
    cin >> n;
    
    // Initializing a list to store the input numbers
    vector<long long> list;
    
    // Reading n long integers from input and adding them to the list
    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        list.push_back(x);
    }
    
    // Initializing a list to store odd numbers and a variable to hold the sum
    vector<long long> odd;
    long long sum = 0;
    
    // Iterating through the list to separate even and odd numbers
    for (long long i : list) {
        if (i % 2 == 0) {
            // If the number is even, add it to the sum
            sum += i;
        } else {
            // If the number is odd, add it to the odd list
            odd.push_back(i);
        }
    }
    
    // Sorting the list of odd numbers in ascending order
    sort(odd.begin(), odd.end());
    
    // Adding all odd numbers to the sum
    for (long long i : odd) {
        sum += i;
    }
    
    // If the count of odd numbers is odd, subtract the smallest odd number from the sum
    if (odd.size() % 2!= 0) {
        sum -= odd.at(0);
    }
    
    // Printing the final calculated sum
    cout << sum << "\n";
}

