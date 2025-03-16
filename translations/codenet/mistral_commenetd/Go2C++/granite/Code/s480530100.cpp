
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// A helper function to print output
void out(vector<int> x) {
    for (int i = 0; i < x.size(); i++) {
        cout << x[i] << " ";
    }
    cout << endl;
}

// Initialize a scanner for reading input
class Scanner {
public:
    Scanner(istream& in) : sc(in) {
        sc.split(bufio.ScanWords);
        sc.buffer([]byte{}, 1000000);
    }

    // Read an integer from the standard input
    int getInt() {
        sc.scan();
        int i;
        sscanf(sc.text(), "%d", &i);
        return i;
    }

    // Read a string from the standard input
    string getString() {
        sc.scan();
        return sc.text();
    }

private:
    bufio.Scanner sc;
};

// Main function
int main() {
    // Initialize the scanner for reading input
    Scanner sc(cin);

    // Read the number of elements 'n' and the number of queries 'q' from the standard input
    int n = sc.getInt(), q = sc.getInt();

    // Initialize a Fenwick Tree of size 'n'
    vector<int> fw(n);

    // Iterate through each element and add it to the Fenwick Tree
    for (int i = 0; i < n; i++) {
        // Read an integer 'a' from the standard input and add it to the Fenwick Tree at index 'i'
        int a = sc.getInt();
        fw[i] += a;
    }

    // Iterate through each query
    for (int i = 0; i < q; i++) {
        // Read an integer 't' from the standard input to determine the type of query
        int t = sc.getInt();

        // If the query is of type 0, read two integers 'p' and 'x' from the standard input and add 'x' to the Fenwick Tree at index 'p'
        if (t == 0) {
            int p = sc.getInt(), x = sc.getInt();
            fw[p] += x;
        } else { // If the query is of type 1, read two integers 'l' and 'r' from the standard input and print the sum of elements in the range [l, r]
            int l = sc.getInt(), r = sc.getInt();

            // Initialize a variable to store the sum
            int sum = 0;

            // Iterate through the range [l, r] and add the corresponding elements to the sum
            for (int j = l; j < r; j++) {
                sum += fw[j];
            }

            // Print the sum
            cout << sum << endl;
        }
    }

    return 0;
}

// ** copy from here to your source code **
//
// fenwick tree
//  1. go lang have no generics, so implement int(long long)
//  data type only.
//  2. do not care overflow
//

// BIT :
class BIT {
public:
    BIT(int n) : n(n), data(n) {}

    // Add :
    void add(int p, int x) {
        for (int i = p; i < n; i += i & -i) {
            data[i] += x;
        }
    }

    // Sum :
    int sum(int r) {
        int s = 0;
        for (int i = r; i > 0; i -= i & -i) {
            s += data[i-1];
        }
        return s;
    }

private:
    int n;
    vector<int> data;
};

// FenwickTree :
BIT* fenwickTree(int n) {
    return new BIT(n);
}

// Add :
void fenwickTreeAdd(BIT* fw, int p, int x) {
    fw->add(p, x);
}

// Sum :
int fenwickTreeSum(BIT* fw, int l, int r) {
    return fw->sum(r) - fw->sum(l);
}

// ** copy from here to your source code **
//
// fenwick tree
//  1. go lang have no generics, so implement int(long long)
//  data type only.
//  2. do not care overflow
//

// BIT :
class BIT {
public:
    BIT(int n) : n(n), data(n) {}

    // Add :
    void add(int p, int x) {
        for (int i = p; i < n; i += i & -i) {
            data[i] += x;
        }
    }

    // Sum :
    int sum(int r) {
        int s = 0;
        for (int i = r; i > 0; i -= i & -i) {
            s += data[i-1];
        }
        return s;
    }

private:
    int n;
    vector<int> data;
};

// FenwickTree :
BIT* fenwickTree(int n) {
    return new BIT(n);
}

// Add :
void fenwickTreeAdd(BIT* fw, int p, int x) {
    fw->add(p, x);
}

// Sum :
int fenwickTreeSum(BIT* fw, int l, int r) {
    return fw->sum(r) - fw->sum(l);
}

// ** copy from here to your source code **
//
// fenwick tree
//  1. go lang have no generics, so implement int(long long)
//  data type only.
//  2. do not care overflow
//

// BIT :
class BIT {
public:
    BIT(int n) : n(n), data(n) {}

    // Add :
    void add(int p, int x) {
        for (int i = p; i < n; i += i & -i) {
            data[i] += x;
        }
    }

    // Sum :
    int sum(int r) {
        int s = 0;
        for (int i = r; i > 0; i -= i & -i) {
            s += data[i-1];
        }
        return s;
    }

private:
    int n;
    vector<int> data;
};

// FenwickTree :
BIT* fenwickTree(int n) {
    return new BIT(n);
}

// Add :
void fenwickTreeAdd(BIT* fw, int p, int x) {
    fw->add(p, x);
}

// Sum :
int fenwickTreeSum(BIT* fw, int l, int r) {
    return fw->sum(r) - fw->sum(l);
}

// ** copy from here to your source code **
//
// fenwick tree
//  1. go lang have no generics, so implement int(long long)
//  data type only.
//  2. do not care overflow
//

// BIT :
class BIT {
public:
    BIT(int n) : n(n), data(n) {}

    // Add :
    void add(int p, int x) {
        for (int i = p; i < n; i += i & -i) {
            data[i] += x;
        }
    }

    // Sum :
    int sum(int r) {
        int s = 0;
        for (int i = r; i > 0; i -= i & -i) {
            s += data[i-1];
        }
        return s;
    }

private:
    int n;
    vector<int> data;
};

// FenwickTree :
BIT* fenwickTree(int n) {
    return new BIT(n);
}

// Add :
void fenwickTreeAdd(BIT* fw, int p, int x) {
    fw->add(p, x);
}

// Sum :
int fenwickTreeSum(BIT* fw, int l, int r) {
    return fw->sum(r) - fw->sum(l);
}

// ** copy from here to your source code **
//
// fenwick tree
//  1. go lang have no generics, so implement int(long long)
//  data type only.
//  2. do not care overflow
//

// BIT :
class BIT {
public:
    BIT(int n) : n(n), data(n) {}

    // Add :
    void add(int p, int x) {
        for (int i = p; i < n; i += i & -i) {
            data[i] += x;
        }
    }

    // Sum :
    int sum(int r) {
        int s = 0;
        for (int i = r; i > 0; i -= i & -i) {
            s += data[i-1];
        }
        return s;
    }

private:
    int n;
    vector<int> data;
};

// FenwickTree :
BIT* fenwickTree(int n) {
    return new BIT(n);
}

// Add :
void fenwickTreeAdd(BIT* fw, int p, int x) {
    fw->add(p, x);
}

// Sum :
int fenwickTreeSum(BIT* fw, int l, int r) {
    return fw->sum(r) - fw->sum(l);
}

// ** copy from here to your source code **
//
// fenwick tree
//  1. go lang have no generics, so implement int(long long)
//  data type only.
//  2. do not care overflow
//

// BIT :
class BIT {
public:
    BIT(int n) : n(n), data(n) {}

    // Add :
    void add(int p, int x) {
        for (int i = p; i < n; i += i & -i) {
            data[i] += x;
        }
    }

    // Sum :
    int sum(int r) {
        int s = 0;
        for (int i = r; i > 0; i -= i & -i) {
            s += data[i-1];
        }
        return s;
    }

private:
    int n;
    vector<int> data;
};

// FenwickTree :
BIT* fenwickTree(int n) {
    return new BIT(n);
}

// Add :
void fenwickTreeAdd(BIT* fw, int p, int x) {
    fw->add(p, x);
}

// Sum :
int fenwickTreeSum(BIT* fw, int l, int r) {
    return fw->sum(r) - fw->sum(l);
}

// ** copy from here to your source code **
//
// fenwick tree
//  1. go lang have no generics, so implement int(long long)
//  data type only.
//  2. do not care overflow
//

// BIT :
class BIT {
public:
    BIT(int n) : n(n), data(n) {}

    // Add :
    void add(int p, int x) {
        for (int i = p; i < n; i += i & -i) {
            data[i] += x;
        }
    }

    // Sum :
    int sum(int r) {
        int s = 0;
        for (int i = r; i > 0; i -= i & -i) {
            s += data[i-1];
        }
        return s;
    }

private:
    int n;
    vector<int> data;
};

// FenwickTree :
BIT* fenwickTree(int n) {
    return new BIT(n);
}

// Add :
void fenwickTreeAdd(BIT* fw, int p, int x) {
    fw->add(p, x);
}

// Sum :
int fenwickTreeSum(BIT* fw, int l, int r) {
    return fw->sum(r) - fw->sum(l);
}

// ** copy from here to your source code **
//
// fenwick tree
//  1. go lang have no generics, so implement int(long long)
//  data type only.
//  2. do not care overflow
//

// BIT :
class BIT {
public:
    BIT(int n) : n(n), data(n) {}

    // Add :
    void add(int p, int x) {
        for (int i = p; i < n; i += i & -i) {
            data[i] += x;
        }
    }

    // Sum :
    int sum(int r) {
        int s = 0;
        for (int i = r; i > 0; i -= i & -i) {
            s += data[i-1];
        }
        return s;
    }

private:
    int n;
    vector<int> data;
};

// FenwickTree :
BIT* fenwickTree(int n) {
    return new BIT(n);
}

// Add :
void fenwickTreeAdd(BIT* fw, int p, int x) {
    fw->add(p, x);
}

// Sum :
int fenwickTreeSum(BIT* fw, int l, int r) {
    return fw->sum(r) - fw->sum(l);
}

// ** copy from here to your source code **
//
// fenwick tree
//  1. go lang have no generics, so implement int(long long)
//  data type only.
//  2. do not care overflow
//

// BIT :
class BIT {
public:
    BIT(int n) : n(n), data(n) {}

    // Add :
    void add(int p, int x) {
        for (int i = p; i < n; i += i & -i) {
            data[i] += x;
        }
    }

    // Sum :
    int sum(int r) {
        int s = 0;
        for (int i = r; i > 0; i -= i & -i) {
            s += data[i-1];
        }
        return s;
    }

private:
    int n;
    vector<int> data;
};

// FenwickTree :
BIT* fenwickTree(int n) {
    return new BIT(n);
}

// Add :
void fenwickTreeAdd(BIT* fw, int p, int x) {
    fw->add(p, x);
}

// Sum :
int fenwickTreeSum(BIT* fw, int l, int r) {
    return fw->sum(r) - fw->sum(l);
}

// ** copy from here to your source code **
//
// fenwick tree
//  1. go lang have no generics, so implement int(long long)
//  data type only.
//  2. do not care overflow
//

// BIT :
class BIT {
public:
    BIT(int n) : n(n), data(n) {}

    // Add :
    void add(int p, int x) {
        for (int i = p; i < n; i += i & -i) {
            data[i] += x;
        }
    }

    /