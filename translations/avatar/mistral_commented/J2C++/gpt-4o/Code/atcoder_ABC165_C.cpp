#include <iostream>   // Including the iostream library for input and output
#include <vector>     // Including the vector library for using vectors
#include <algorithm>  // Including the algorithm library for using max function

using namespace std;

int a[100], b[100], c[100], d[100]; // Declaring four integer arrays a, b, c, and d
int n = 0; // Declaring and initializing two integer variables n and m to zero
int m = 0;
int q = 0; // Declaring and initializing an integer variable q to zero
long ans = -100L; // Declaring and initializing a long variable ans to a very large negative number

void dfs(vector<int>& list) { // A recursive function named dfs that takes a vector named list as an argument
    if (list.size() == n) { // A conditional statement that checks if the size of the vector list is equal to the integer n
        long score = 0L; // Declaring and initializing a long variable score to zero

        for (int i = 0; i < q; ++i) { // A for loop that calculates the score based on the condition that (list[b[i]] - list[a[i]] == c[i])
            score += (list[b[i]] - list[a[i]] == c[i]) ? d[i] : 0L;
        }

        ans = max(ans, score); // Updating the value of the long variable ans with the maximum value of ans and the score calculated in the for loop
        return; // Returning from the function after updating the value of ans
    }

    if (!list.empty()) { // A conditional statement that checks if the vector list is not empty
        for (int num = list.back(); num <= m; ++num) { // A for loop that adds the integer num to the vector list and recursively calls the function dfs
            list.push_back(num);
            dfs(list);
            list.pop_back();
        }
    } else { // If the vector list is empty
        for (int num = 1; num <= m; ++num) { // A for loop that adds the integer num to the vector list and recursively calls the function dfs
            list.push_back(num);
            dfs(list);
            list.pop_back();
        }
    }
}

int main() {
    cin >> n >> m >> q; // Reading the first three integers n, m, and q from the standard input

    for (int i = 0; i < q; ++i) { // A for loop that reads q integers from the standard input and stores them in arrays a, b, c, and d
        cin >> a[i]; a[i]--; // Reading the integer a[i] from the standard input and storing it in the array a after subtracting 1 from it
        cin >> b[i]; b[i]--; // Reading the integer b[i] from the standard input and storing it in the array b after subtracting 1 from it
        cin >> c[i]; // Reading the integer c[i] from the standard input and storing it in the array c
        cin >> d[i]; // Reading the integer d[i] from the standard input and storing it in the array d
    }

    vector<int> list; // Creating a vector to hold the current combination
    dfs(list); // Calling the recursive function dfs with an empty vector as an argument

    cout << ans << endl; // Printing the value of the long variable ans to the standard output
    return 0; // Returning 0 to indicate successful execution
}

// <END-OF-CODE>
