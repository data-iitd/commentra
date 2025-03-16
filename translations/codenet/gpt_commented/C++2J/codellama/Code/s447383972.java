
// Java code to read a long long integer from input
static long read() {
    long x = 0, f = 1;
    char ch = getchar();
    // Read characters until a digit or '-' is found
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1; // Check for negative sign
        ch = getchar();
    }
    // Convert the digits to a long long integer
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f; // Return the final value with sign
}

// Java code to write a long long integer to output
static void write(long x) {
    if (x < 0) putchar('-'), x = -x; // Print negative sign if needed
    if (x >= 10) write(x / 10); // Recursively write the digits
    putchar(x % 10 + '0'); // Print the last digit
}

// Java code to write a long long integer followed by a newline
static void writeln(long x) {
    write(x); // Write the integer
    puts(""); // Print a newline
}

// Java code to sort an array of long long integers
static void sort(long[] a, int n) {
    for (int i = 1; i < n; i++) {
        long x = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > x) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = x;
    }
}

// Java code to identify duplicates in an array of long long integers
static void findDuplicates(long[] a, int n, long[] q) {
    int tot = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] == a[i + 1]) {
            q[++tot] = a[i];
            i++;
        }
    }
}

// Java code to output the product of the last two duplicates found
static void output(long[] q, int tot) {
    writeln(q[tot] * q[tot - 1]);
}

public static void main(String[] args) {
    long n = read(); // Read the number of elements
    long[] a = new long[n + 1]; // Declare the array a
    For(i, 1, n) a[i] = read(); // Read the elements into the array a
    sort(a, n + 1); // Sort the array in non-decreasing order

    long[] q = new long[n + 1]; // Declare the array q
    findDuplicates(a, n + 1, q); // Identify duplicates and store them in array q

    output(q, tot); // Output the product of the last two duplicates found
}

