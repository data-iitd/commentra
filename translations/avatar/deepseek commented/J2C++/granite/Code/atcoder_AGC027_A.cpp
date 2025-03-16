

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Step 1: Read an integer N and a long integer x from the standard input
    int N;
    long x;
    cin >> N >> x;

    // Step 2: Read N long integers and store them in a vector called sweet
    vector < long > sweet;
    for (int i = 0; i < N; i++) {
        long a;
        cin >> a;
        sweet.push_back(a);
    }

    // Step 3: Sort the vector sweet
    sort(sweet.begin(), sweet.end());

    // Step 4: Initialize a counter num to 0 and iterate through the sorted vector sweet
    int num = 0;
    for (int i = 0; i < N; i++) {
        // Step 5: Check if subtracting the element from x results in a non-negative value
        if (x - sweet[num] >= 0) {
            // Step 6: Subtract the element from x and increment the counter num
            x = x - sweet[num];
            num++;
        } else {
            // Step 7: Break out of the loop if the condition is not met
            break;
        }
    }

    // Step 8: After the loop, if num equals N and x is greater than 0, decrement num by 1
    if ((num == N) && (x > 0)) {
        num--;
    }

    // Step 9: Print the value of num
    cout << num << endl;

    return 0;
}
