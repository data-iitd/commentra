
// A helper function to print output
void out(Object... x) {
    System.out.println(Arrays.deepToString(x));
}

// Function to read an integer from the standard input
int getInt() {
    Scanner sc = new Scanner(System.in);
    return sc.nextInt();
}

// Function to read a string from the standard input
String getString() {
    Scanner sc = new Scanner(System.in);
    return sc.next();
}

// Main function
public static void main(String[] args) {
    // Initialize the scanner for reading input
    Scanner sc = new Scanner(System.in);

    // Read the number of elements 'n' and the number of queries 'q' from the standard input
    int n = getInt();
    int q = getInt();

    // Initialize a Fenwick Tree of size 'n'
    FenwickTree fw = new FenwickTree(n);

    // Iterate through each element and add it to the Fenwick Tree
    for (int i = 0; i < n; i++) {
        // Read an integer 'a' from the standard input and add it to the Fenwick Tree at index 'i'
        int a = getInt();
        fw.add(i, a);
    }

    // Iterate through each query
    for (int i = 0; i < q; i++) {
        // Read an integer 't' from the standard input to determine the type of query
        int t = getInt();

        // If the query is of type 0, read two integers 'p' and 'x' from the standard input and add 'x' to the Fenwick Tree at index 'p'
        if (t == 0) {
            int p = getInt();
            int x = getInt();
            fw.add(p, x);
        } else { // If the query is of type 1, read two integers 'l' and 'r' from the standard input and print the sum of elements in the range [l, r]
            int l = getInt();
            int r = getInt();
            // Call the Sum function of the Fenwick Tree to get the sum of elements in the range [l, r]
            out(fw.sum(l, r));
        }
    }
}

// ** copy from here to your source code **
//
// fenwick tree
//  1. do not care overflow
//  2. do not care negative
//

// BIT :
class BIT {
    int n;
    int[] data;

    public BIT(int n) {
        this.n = n;
        data = new int[n];
    }

    public void add(int p, int x) {
        p++;
        while (p <= n) {
            data[p - 1] += x;
            p += p & -p;
        }
    }

    public int sum(int r) {
        int s = 0;
        while (r > 0) {
            s += data[r - 1];
            r -= r & -r;
        }
        return s;
    }

    public int sum(int l, int r) {
        return sum(r) - sum(l);
    }
}

// FenwickTree :
class FenwickTree {
    BIT bit;

    public FenwickTree(int n) {
        bit = new BIT(n);
    }

    public void add(int p, int x) {
        bit.add(p, x);
    }

    public int sum(int l, int r) {
        return bit.sum(r) - bit.sum(l);
    }
}

