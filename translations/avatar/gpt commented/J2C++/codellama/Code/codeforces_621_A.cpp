#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Creating a Scanner object to read input from the console
    int n;
    cin >> n;
    
    // Initializing a list to store the input numbers
    vector<long> list;
    
    // Reading n long integers from input and adding them to the list
    for (int i = 0; i < n; i++) {
        long num;
        cin >> num;
        list.push_back(num);
    }
    
    // Initializing a list to store odd numbers and a variable to hold the sum
    vector<long> odd;
    long sum = 0;
    
    // Iterating through the list to separate even and odd numbers
    for (long i : list) {
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
    for (long i : odd) {
        sum += i;
    }
    
    // If the count of odd numbers is odd, subtract the smallest odd number from the sum
    if (odd.size() % 2 != 0) {
        sum -= odd[0];
    }
    
    // Printing the final calculated sum
    cout << sum << endl;
    
    return 0;
}

