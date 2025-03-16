#include <iostream>
#include <map>
#include <vector>

using namespace std;

// Function to read input as a list of integers
vector<int> _input() {
    int n;
    cin >> n;
    vector<int> lst(n);
    for (int i = 0; i < n; i++) {
        cin >> lst[i];
    }
    return lst;
}

// Function to calculate the number of elements that have a smaller frequency than the current element
int smaller(map<int, int> &l, int i, int n) {
    int res = 0;
    for (int j = 0; j < i; j++) {
        if (l[lst[j]] < l[lst[i]]) {
            res++;
        }
    }
    return res;
}

// Function to calculate the number of elements that have not been processed yet
int not_processed(map<int, int> &l, int i, int n) {
    int res = 0;
    for (int j = i + 1; j < n; j++) {
        res++;
    }
    return res;
}

int main() {
    // Read number of elements 'n' and size 'm' of the list 'lst'
    vector<int> lst = _input();
    int n = lst.size();

    // Initialize an empty dictionary 'l' to store the frequency of each element
    map<int, int> l;

    // Iterate through each element in the list 'lst'
    for (int i = 0; i < n; i++) {
        // If the current element is not already present in the dictionary 'l'
        if (l.find(lst[i]) == l.end()) {
            // Add the current element to the dictionary 'l' with a frequency of 1
            l[lst[i]] = 1;
        }
        // If the current element is already present in the dictionary 'l'
        else {
            // Increment the frequency of the current element in the dictionary 'l'
            l[lst[i]]++;
        }
    }

    // Initialize result variable 'res' to 0
    int res = 0;

    // Iterate through each element in the list 'lst'
    for (int i = 0; i < n; i++) {
        // If the frequency of the current element in the dictionary 'l' is greater than 1
        if (l[lst[i]] > 1) {
            // Calculate the number of elements that have a smaller frequency than the current element
            // and add it to the result variable 'res'
            res += smaller(l, i, n);
            // Decrease the frequency of the current element in the dictionary 'l' by 1
            l[lst[i]]--;
        }
        // If the frequency of the current element in the dictionary 'l' is equal to 1
        else {
            // Calculate the number of elements that have not been processed yet and add it to the result variable 'res'
            res += not_processed(l, i, n);
        }
    }

    // Print the final result
    cout << res << endl;

    return 0;
}

