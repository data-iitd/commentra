
// ** copy from here to your source code **
//
// fenwick tree
//  1. do not care overflow
//

// FenwickTree represents a Binary Indexed Tree (Fenwick Tree).
class FenwickTree {
    private int n; // Number of elements in the tree
    private int[] data; // Array to store the tree data

    // FenwickTree initializes a new Binary Indexed Tree with n elements.
    public FenwickTree(int n) {
        this.n = n;
        data = new int[n]; // Create a slice to hold the tree data
    }

    // Add updates the Fenwick Tree by adding x to the element at position p.
    public void add(int p, int x) {
        p++; // Increment p to match the 1-based index used in Fenwick Tree
        while (p <= n) {
            data[p - 1] += x; // Update the tree data
            p += p & -p; // Move to the next index
        }
    }

    // Sum calculates the sum of elements in the range [l, r).
    public int sum(int l, int r) {
        return sum(r) - sum(l); // Return the difference of sums
    }

    // sum calculates the prefix sum from the start to index r.
    public int sum(int r) {
        int s = 0; // Initialize sum
        while (r > 0) {
            s += data[r - 1]; // Add the value at index r-1
            r -= r & -r; // Move to the parent index
        }
        return s; // Return the calculated sum
    }
}

// ** copy from here to your source code **
//
// fenwick tree
//  1. do not care overflow
//

// FenwickTree represents a Binary Indexed Tree (Fenwick Tree).
class FenwickTree {
    private int n; // Number of elements in the tree
    private int[] data; // Array to store the tree data

    // FenwickTree initializes a new Binary Indexed Tree with n elements.
    public FenwickTree(int n) {
        this.n = n;
        data = new int[n]; // Create a slice to hold the tree data
    }

    // Add updates the Fenwick Tree by adding x to the element at position p.
    public void add(int p, int x) {
        p++; // Increment p to match the 1-based index used in Fenwick Tree
        while (p <= n) {
            data[p - 1] += x; // Update the tree data
            p += p & -p; // Move to the next index
        }
    }

    // Sum calculates the sum of elements in the range [l, r).
    public int sum(int l, int r) {
        return sum(r) - sum(l); // Return the difference of sums
    }

    // sum calculates the prefix sum from the start to index r.
    public int sum(int r) {
        int s = 0; // Initialize sum
        while (r > 0) {
            s += data[r - 1]; // Add the value at index r-1
            r -= r & -r; // Move to the parent index
        }
        return s; // Return the calculated sum
    }
}

// ** copy from here to your source code **
//
// fenwick tree
//  1. do not care overflow
//

// FenwickTree represents a Binary Indexed Tree (Fenwick Tree).
class FenwickTree {
    private int n; // Number of elements in the tree
    private int[] data; // Array to store the tree data

    // FenwickTree initializes a new Binary Indexed Tree with n elements.
    public FenwickTree(int n) {
        this.n = n;
        data = new int[n]; // Create a slice to hold the tree data
    }

    // Add updates the Fenwick Tree by adding x to the element at position p.
    public void add(int p, int x) {
        p++; // Increment p to match the 1-based index used in Fenwick Tree
        while (p <= n) {
            data[p - 1] += x; // Update the tree data
            p += p & -p; // Move to the next index
        }
    }

    // Sum calculates the sum of elements in the range [l, r).
    public int sum(int l, int r) {
        return sum(r) - sum(l); // Return the difference of sums
    }

    // sum calculates the prefix sum from the start to index r.
    public int sum(int r) {
        int s = 0; // Initialize sum
        while (r > 0) {
            s += data[r - 1]; // Add the value at index r-1
            r -= r & -r; // Move to the parent index
        }
        return s; // Return the calculated sum
    }
}

// ** copy from here to your source code **
//
// fenwick tree
//  1. do not care overflow
//

// FenwickTree represents a Binary Indexed Tree (Fenwick Tree).
class FenwickTree {
    private int n; // Number of elements in the tree
    private int[] data; // Array to store the tree data

    // FenwickTree initializes a new Binary Indexed Tree with n elements.
    public FenwickTree(int n) {
        this.n = n;
        data = new int[n]; // Create a slice to hold the tree data
    }

    // Add updates the Fenwick Tree by adding x to the element at position p.
    public void add(int p, int x) {
        p++; // Increment p to match the 1-based index used in Fenwick Tree
        while (p <= n) {
            data[p - 1] += x; // Update the tree data
            p += p & -p; // Move to the next index
        }
    }

    // Sum calculates the sum of elements in the range [l, r).
    public int sum(int l, int r) {
        return sum(r) - sum(l); // Return the difference of sums
    }

    // sum calculates the prefix sum from the start to index r.
    public int sum(int r) {
        int s = 0; // Initialize sum
        while (r > 0) {
            s += data[r - 1]; // Add the value at index r-1
            r -= r & -r; // Move to the parent index
        }
        return s; // Return the calculated sum
    }
}

// ** copy from here to your source code **
//
// fenwick tree
//  1. do not care overflow
//

// FenwickTree represents a Binary Indexed Tree (Fenwick Tree).
class FenwickTree {
    private int n; // Number of elements in the tree
    private int[] data; // Array to store the tree data

    // FenwickTree initializes a new Binary Indexed Tree with n elements.
    public FenwickTree(int n) {
        this.n = n;
        data = new int[n]; // Create a slice to hold the tree data
    }

    // Add updates the Fenwick Tree by adding x to the element at position p.
    public void add(int p, int x) {
        p++; // Increment p to match the 1-based index used in Fenwick Tree
        while (p <= n) {
            data[p - 1] += x; // Update the tree data
            p += p & -p; // Move to the next index
        }
    }

    // Sum calculates the sum of elements in the range [l, r).
    public int sum(int l, int r) {
        return sum(r) - sum(l); // Return the difference of sums
    }

    // sum calculates the prefix sum from the start to index r.
    public int sum(int r) {
        int s = 0; // Initialize sum
        while (r > 0) {
            s += data[r - 1]; // Add the value at index r-1
            r -= r & -r; // Move to the parent index
        }
        return s; // Return the calculated sum
    }
}

// ** copy from here to your source code **
//
// fenwick tree
//  1. do not care overflow
//

// FenwickTree represents a Binary Indexed Tree (Fenwick Tree).
class FenwickTree {
    private int n; // Number of elements in the tree
    private int[] data; // Array to store the tree data

    // FenwickTree initializes a new Binary Indexed Tree with n elements.
    public FenwickTree(int n) {
        this.n = n;
        data = new int[n]; // Create a slice to hold the tree data
    }

    // Add updates the Fenwick Tree by adding x to the element at position p.
    public void add(int p, int x) {
        p++; // Increment p to match the 1-based index used in Fenwick Tree
        while (p <= n) {
            data[p - 1] += x; // Update the tree data
            p += p & -p; // Move to the next index
        }
    }

    // Sum calculates the sum of elements in the range [l, r).
    public int sum(int l, int r) {
        return sum(r) - sum(l); // Return the difference of sums
    }

    // sum calculates the prefix sum from the start to index r.
    public int sum(int r) {
        int s = 0; // Initialize sum
        while (r > 0) {
            s += data[r - 1]; // Add the value at index r-1
            r -= r & -r; // Move to the parent index
        }
        return s; // Return the calculated sum
    }
}

// ** copy from here to your source code **
//
// fenwick tree
//  1. do not care overflow
//

// FenwickTree represents a Binary Indexed Tree (Fenwick Tree).
class FenwickTree {
    private int n; // Number of elements in the tree
    private int[] data; // Array to store the tree data

    // FenwickTree initializes a new Binary Indexed Tree with n elements.
    public FenwickTree(int n) {
        this.n = n;
        data = new int[n]; // Create a slice to hold the tree data
    }

    // Add updates the Fenwick Tree by adding x to the element at position p.
    public void add(int p, int x) {
        p++; // Increment p to match the 1-based index used in Fenwick Tree
        while (p <= n) {
            data[p - 1] += x; // Update the tree data
            p += p & -p; // Move to the next index
        }
    }

    // Sum calculates the sum of elements in the range [l, r).
    public int sum(int l, int r) {
        return sum(r) - sum(l); // Return the difference of sums
    }

    // sum calculates the prefix sum from the start to index r.
    public int sum(int r) {
        int s = 0; // Initialize sum
        while (r > 0) {
            s += data[r - 1]; // Add the value at index r-1
            r -= r & -r; // Move to the parent index
        }
        return s; // Return the calculated sum
    }
}

// ** copy from here to your source code **
//
// fenwick tree
//  1. do not care overflow
//

// FenwickTree represents a Binary Indexed Tree (Fenwick Tree).
class FenwickTree {
    private int n; // Number of elements in the tree
    private int[] data; // Array to store the tree data

    // FenwickTree initializes a new Binary Indexed Tree with n elements.
    public FenwickTree(int n) {
        this.n = n;
        data = new int[n]; // Create a slice to hold the tree data
    }

    // Add updates the Fenwick Tree by adding x to the element at position p.
    public void add(int p, int x) {
        p++; // Increment p to match the 1-based index used in Fenwick Tree
        while (p <= n) {