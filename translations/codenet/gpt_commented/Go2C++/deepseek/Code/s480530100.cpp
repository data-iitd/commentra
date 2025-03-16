#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

// out is a utility function to print output to the console.
void out(vector<int> x) {
    for (int i = 0; i < x.size(); i++) {
        cout << x[i] << " ";
    }
    cout << endl;
}

// getInt reads an integer from input and returns it.
int getInt() {
    string line;
    getline(cin, line);
    istringstream iss(line);
    int num;
    iss >> num;
    return num;
}

// getString reads a string from input and returns it.
string getString() {
    string line;
    getline(cin, line);
    return line;
}

// ** copy from here to your source code **
//
// fenwick tree
//  1. go lang have no generics, so implement int(long long)
//  data type only.
//  2. do not care overflow
//

// BIT represents a Binary Indexed Tree (Fenwick Tree).
class BIT {
public:
    int n; // Number of elements in the tree
    vector<int> data; // Vector to store the tree data

    // Constructor to initialize a new Binary Indexed Tree with n elements.
    BIT(int n) : n(n), data(n, 0) {}

    // Add updates the Fenwick Tree by adding x to the element at position p.
    void Add(int p, int x) {
        p++; // Increment p to match the 1-based index used in Fenwick Tree
        while (p <= n) {
            data[p - 1] += x; // Update the tree data
            p += p & -p; // Move to the next index
        }
    }

    // Sum calculates the sum of elements in the range [l, r).
    int Sum(int l, int r) {
        return sum(r) - sum(l); // Return the difference of sums
    }

private:
    // sum calculates the prefix sum from the start to index r.
    int sum(int r) {
        int s = 0; // Initialize sum
        while (r > 0) {
            s += data[r - 1]; // Add the value at index r-1
            r -= r & -r; // Move to the parent index
        }
        return s; // Return the calculated sum
    }
};

int main() {
    // Read the number of elements (n) and the number of queries (q).
    int n = getInt();
    int q = getInt();

    // Initialize a Fenwick Tree (Binary Indexed Tree) with n elements.
    BIT fw(n);

    // Read n integers and add them to the Fenwick Tree.
    for (int i = 0; i < n; i++) {
        int a = getInt();
        fw.Add(i, a);
    }

    // Process q queries.
    for (int i = 0; i < q; i++) {
        int t = getInt(); // Read the type of query.
        if (t == 0) {
            // For update queries, read position (p) and value (x) and update the Fenwick Tree.
            int p = getInt();
            int x = getInt();
            fw.Add(p, x);
        } else {
            // For sum queries, read the range (l, r) and output the sum from l to r.
            int l = getInt();
            int r = getInt();
            cout << fw.Sum(l, r) << endl;
        }
    }

    return 0;
}
