

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n; // Read the number of elements
    vector < long long > list;
    for (int i = 0; i < n; i++) {
        long long num;
        cin >> num; // Read the elements and store them in the vector
        list.push_back(num);
    }
    
    vector < long long > odd; // Vector to store odd numbers
    long long sum = 0; // Initialize sum of numbers
    
    for (long long i : list) { // Iterate through the vector
        if (i % 2 == 0) 
            sum += i; // Add to sum if the number is even
        else 
            odd.push_back(i); // Add to odd vector if the number is odd
    }
    
    sort(odd.begin(), odd.end()); // Sort the vector of odd numbers
    
    for (long long i : odd) 
        sum += i; // Add all odd numbers to the sum
    
    if (odd.size() % 2!= 0) 
        sum -= odd[0]; // Subtract the smallest odd number if the count of odd numbers is odd
    
    cout << sum << endl; // Print the final sum
    
    return 0;
}
