
// Synchronize input/output for faster performance
System.setIn(new BufferedInputStream(System.in));
System.setOut(new PrintStream(new BufferedOutputStream(System.out)));

// Read the number of elements
int n = Integer.parseInt(System.console().readLine());

// Initialize a vector to store the elements and read them from input
int[] a = new int[n];
for (int i = 0; i < n; i++) {
    a[i] = Integer.parseInt(System.console().readLine());
}

// Sort the vector to facilitate duplicate checking
Arrays.sort(a);

// Check for duplicates in the sorted vector
for (int i = 0; i < n - 1; i++) {
    if (a[i] == a[i + 1]) {
        // If a duplicate is found, print "NO" and exit
        System.out.println("NO");
        return;
    }
}

// If no duplicates are found, print "YES"
System.out.println("YES");

// End of the program
