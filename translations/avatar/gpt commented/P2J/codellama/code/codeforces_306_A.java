// Read two integers from input: n (total items) and m (number of groups)
Scanner sc = new Scanner(System.in);
int n = sc.nextInt();
int m = sc.nextInt();

// Calculate the quotient (q) and remainder (r) when n is divided by m
int q = n / m;  // Number of items each group will get
int r = n % m;   // Remaining items after equal distribution

// Create a list 'a' initialized with 'm' elements, each set to the quotient 'q'
int[] a = new int[m];
for (int i = 0; i < m; i++) {
    a[i] = q;
}

// Distribute the remainder 'r' among the first 'r' groups
for (int i = 0; i < r; i++) {
    a[i] += 1;  // Increment the count for the first 'r' groups by 1
}

// Print the final distribution of items in each group
for (int i = 0; i < m; i++) {
    System.out.print(a[i] + " ");
}

// 