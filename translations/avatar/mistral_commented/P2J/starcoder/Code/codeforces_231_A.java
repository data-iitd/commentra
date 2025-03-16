// Take an integer 'n' as input from the user
Scanner sc = new Scanner(System.in);
int n = sc.nextInt();

// Initialize a counter 'c' to 0
int c = 0;

// Iterate through the range of 'n'
for (int i = 0; i < n; i++) {
    // Take 'n' lists of integers as input from the user
    int[] l1 = new int[n];
    for (int j = 0; j < n; j++) {
        l1[j] = sc.nextInt();
    }

    // Check if the sum of the elements in the current list is greater than 1
    if (Arrays.stream(l1).sum() > 1) {
        // Increment the counter 'c' by 1 if the condition is true
        c++;
    }
}

// Print the value of the counter 'c'
System.out.println(c);

