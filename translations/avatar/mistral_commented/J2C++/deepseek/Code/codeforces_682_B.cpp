#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

int main() {
    // Creating a vector to store the elements
    vector<int> list;

    // Reading the number of elements in the list from the input
    int n;
    cin >> n;

    // Reading 'n' elements from the input and adding them to the vector
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        list.push_back(num);
    }

    // Sorting the vector in ascending order using std::sort()
    sort(list.begin(), list.end());

    // Initializing a variable 'c' to keep track of the number of distinct elements
    int c = 1;

    // Iterating through the vector to find the number of distinct elements
    for (int i = 0; i < n; i++) {
        // If the current element is greater than or equal to the current count 'c', increment the count
        if (list[i] >= c) {
            c++;
        }
    }

    // Writing the result to the output
    printf("%d\n", c);

    return 0;
}
