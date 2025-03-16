
#include <bits/stdc++.h>
using namespace std;

// mainFn is the main logic of the program.
void mainFn() {
    // Get the number of elements in the slice.
    int n = getInt();
    // Get the slice of integers.
    vector<int> ls(n);
    for (int i = 0; i < n; i++) {
        ls[i] = getInt();
    }
    // Create a reversed version of the slice.
    vector<int> lsRev = ls;
    // Sort the original slice in ascending order.
    sort(ls.begin(), ls.end());
    // Sort the reversed slice in descending order.
    sort(lsRev.rbegin(), lsRev.rend());

    // Initialize the answer variable.
    int ans = 0;
    // Loop through the slice to calculate the answer.
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            // Calculate p and q based on the current elements.
            int p = min(ls[i], ls[j]);
            int q = max(ls[i], ls[j]);
            // Calculate x and y based on p and q.
            int x = q - p;
            int y = q + p;

            // Find the left boundary using binary search.
            int l = lower_bound(ls.begin(), ls.end(), x) - ls.begin();
            // Find the right boundary using binary search.
            int r = n - (upper_bound(lsRev.begin(), lsRev.end(), y) - lsRev.begin());

            // Calculate the sum of valid pairs.
            int sum = r - l;
            // Adjust the sum if the current indices are within the range.
            if ((i >= l) && (i <= r)) {
                sum--;
            }
            if ((j >= l) && (j <= r)) {
                sum--;
            }
            // Ensure the sum is not negative.
            sum = max(0, sum);
            // Add the sum to the answer.
            ans += sum;
        }
    }

    // Divide the answer by 3 to get the final result.
    ans /= 3;
    // Print the final answer.
    puts(ans);
}

// Helper functions to find the minimum and maximum of two integers.
int min(int a, int b) {
    return a < b? a : b;
}

int max(int a, int b) {
    return a > b? a : b;
}

// -----------------------------------------

// Global variables for input/output operations.
int main() {
    // buf := 200001
    // scanner.Buffer(make([]byte, buf), buf)
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    mainFn();
    return 0;
}

// getInt reads an integer from the standard input.
int getInt() {
    int i;
    cin >> i;
    return i;
}

// getIntSlice reads a slice of integers from the standard input.
vector<int> getIntSlice(int n) {
    vector<int> is(n);
    for (int i = 0; i < n; i++) {
        cin >> is[i];
    }
    return is;
}

// getString reads a string from the standard input.
string getString() {
    string s;
    cin >> s;
    return s;
}

// puts writes the arguments to the standard output.
void puts(int a) {
    cout << a << endl;
}

void puts(string a) {
    cout << a << endl;
}

void puts(vector<int> a) {
    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

void puts(vector<string> a) {
    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << endl;
    }
}

void puts(vector<vector<int>> a) {
    for (int i = 0; i < a.size(); i++) {
        puts(a[i]);
    }
}

void puts(vector<vector<string>> a) {
    for (int i = 0; i < a.size(); i++) {
        puts(a[i]);
    }
}

void puts(map<int, int> a) {
    for (auto it = a.begin(); it!= a.end(); it++) {
        cout << it->first << " " << it->second << endl;
    }
}

void puts(map<string, int> a) {
    for (auto it = a.begin(); it!= a.end(); it++) {
        cout << it->first << " " << it->second << endl;
    }
}

void puts(map<int, string> a) {
    for (auto it = a.begin(); it!= a.end(); it++) {
        cout << it->first << " " << it->second << endl;
    }
}

void puts(map<string, string> a) {
    for (auto it = a.begin(); it!= a.end(); it++) {
        cout << it->first << " " << it->second << endl;
    }
}

void puts(map<int, vector<int>> a) {
    for (auto it = a.begin(); it!= a.end(); it++) {
        cout << it->first << " ";
        puts(it->second);
    }
}

void puts(map<string, vector<int>> a) {
    for (auto it = a.begin(); it!= a.end(); it++) {
        cout << it->first << " ";
        puts(it->second);
    }
}

void puts(map<int, vector<string>> a) {
    for (auto it = a.begin(); it!= a.end(); it++) {
        cout << it->first << " ";
        puts(it->second);
    }
}

void puts(map<string, vector<string>> a) {
    for (auto it = a.begin(); it!= a.end(); it++) {
        cout << it->first << " ";
        puts(it->second);
    }
}

void puts(map<int, map<int, int>> a) {
    for (auto it = a.begin(); it!= a.end(); it++) {
        cout << it->first << " ";
        puts(it->second);
    }
}

void puts(map<string, map<int, int>> a) {
    for (auto it = a.begin(); it!= a.end(); it++) {
        cout << it->first << " ";
        puts(it->second);
    }
}

void puts(map<int, map<string, int>> a) {
    for (auto it = a.begin(); it!= a.end(); it++) {
        cout << it->first << " ";
        puts(it->second);
    }
}

void puts(map<string, map<string, int>> a) {
    for (auto it = a.begin(); it!= a.end(); it++) {
        cout << it->first << " ";
        puts(it->second);
    }
}

void puts(map<int, map<int, string>> a) {
    for (auto it = a.begin(); it!= a.end(); it++) {
        cout << it->first << " ";
        puts(it->second);
    }
}

void puts(map<string, map<int, string>> a) {
    for (auto it = a.begin(); it!= a.end(); it++) {
        cout << it->first << " ";
        puts(it->second);
    }
}

void puts(map<int, map<string, string>> a) {
    for (auto it = a.begin(); it!= a.end(); it++) {
        cout << it->first << " ";
        puts(it->second);
    }
}

void puts(map<string, map<string, string>> a) {
    for (auto it = a.begin(); it!= a.end(); it++) {
        cout << it->first << " ";
        puts(it->second);
    }
}

void puts(map<int, map<int, vector<int>>> a) {
    for (auto it = a.begin(); it!= a.end(); it++) {
        cout << it->first << " ";
        puts(it->second);
    }
}

void puts(map<string, map<int, vector<int>>> a) {
    for (auto it = a.begin(); it!= a.end(); it++) {
        cout << it->first << " ";
        puts(it->second);
    }
}

void puts(map<int, map<string, vector<int>>> a) {
    for (auto it = a.begin(); it!= a.end(); it++) {
        cout << it->first << " ";
        puts(it->second);
    }
}

void puts(map<string, map<string, vector<int>>> a) {
    for (auto it = a.begin(); it!= a.end(); it++) {
        cout << it->first << " ";
        puts(it->second);
    }
}

void puts(map<int, map<int, vector<string>>> a) {
    for (auto it = a.begin(); it!= a.end(); it++) {
        cout << it->first << " ";
        puts(it->second);
    }
}

void puts(map<string, map<int, vector<string>>> a) {
    for (auto it = a.begin(); it!= a.end(); it++) {
        cout << it->first << " ";
        puts(it->second);
    }
}

void puts(map<int, map<string, vector<string>>> a) {
    for (auto it = a.begin(); it!= a.end(); it++) {
        cout << it->first << " ";
        puts(it->second);
    }
}

void puts(map<string, map<string, vector<string>>> a) {
    for (auto it = a.begin(); it!= a.end(); it++) {
        cout << it->first << " ";
        puts(it->second);
    }
}

void puts(map<int, map<int, map<int, int>>> a) {
    for (auto it = a.begin(); it!= a.end(); it++) {
        cout << it->first << " ";
        puts(it->second);
    }
}

void puts(map<string, map<int, map<int, int>>> a) {
    for (auto it = a.begin(); it!= a.end(); it++) {
        cout << it->first << " ";
        puts(it->second);
    }
}

void puts(map<int, map<string, map<int, int>>> a) {
    for (auto it = a.begin(); it!= a.end(); it++) {
        cout << it->first << " ";
        puts(it->second);
    }
}

void puts(map<string, map<string, map<int, int>>> a) {
    for (auto it = a.begin(); it!= a.end(); it++) {
        cout << it->first << " ";
        puts(it->second);
    }
}

void puts(map<int, map<int, map<string, int>>> a) {
    for (auto it = a.begin(); it!= a.end(); it++) {
        cout << it->first << " ";
        puts(it->second);
    }
}

void puts(map<string, map<int, map<string, int>>> a) {
    for (auto it = a.begin(); it!= a.end(); it++) {
        cout << it->first << " ";
        puts(it->second);
    }
}

void puts(map<int, map<string, map<string, int>>> a) {
    for (auto it = a.begin(); it!= a.end(); it++) {
        cout << it->first << " ";
        puts(it->second);
    }
}

void puts(map<string, map<string, map<string, int>>> a) {
    for (auto it = a.begin(); it!= a.end(); it++) {
        cout << it->first << " ";
        puts(it->second);
    }
}

void puts(map<int, map<int, map<int, string>>> a) {
    for (auto it = a.begin(); it!= a.end(); it++) {
        cout << it->first << " ";
        puts(it->second);
    }
}

void puts(map<string, map<int, map<int, string>>> a) {
    for (auto it = a.begin(); it!= a.end(); it++) {
        cout << it->first << " ";
        puts(it->second);
    }
}

void puts(map<int, map<string, map<int, string>>> a) {
    for (auto it = a.begin(); it!= a.end(); it++) {
        cout << it->first << " ";
        puts(it->second);
    }
}

void puts(map<string, map<string, map<int, string>>> a) {
    for (auto it = a.begin(); it!= a.end(); it++) {
        cout << it->first << " ";
        puts(it->second);
    }
}

void puts(map<int, map<int, map<string, string>>> a) {
    for (auto it = a.begin(); it!= a.end(); it++) {
        cout << it->first << " ";
        puts(it->second);
    }
}

void puts(map<string, map<int, map<string, string>>> a) {
    for (auto it = a.begin(); it!= a.end(); it++) {
        cout << it->first << " ";
        puts(it->second);
    }
}

void puts(map<int, map<string, map<string, string>>> a) {
    for (auto it = a.begin(); it!= a.end(); it++) {
        cout << it->first << " ";
        puts(it->second);
    }
}

void puts(map<string, map<string, map<string, string>>> a) {
    for (auto it = a.begin(); it!= a.end(); it++) {
      