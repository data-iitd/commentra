// Take an integer 'n' as input
Scanner sc = new Scanner(System.in);
int n = sc.nextInt();

// Initialize a list 'a' of 'n' integers by taking input
int[] a = new int[n];
for (int i = 0; i < n; i++) {
    a[i] = sc.nextInt();
}

// Initialize an empty list 'b' of length 'n'
int[] b = new int[n];

// Assign indices to 'b' based on the values in 'a'
for (int i = 0; i < n; i++) {
    // Assign index 'i' to the position 'a[i] - 1' in list 'b'
    b[a[i] - 1] = i;
}

// Initialize a variable'res' to 0
int res = 0;

// Calculate the absolute difference between consecutive indices in 'b' and sum them up
for (int i = 1; i < n; i++) {
    // Add the absolute difference between indices 'i' and 'i-1' to'res'
    res += Math.abs(b[i] - b[i-1]);
}

// Print the final result'res'
System.out.println(res);

