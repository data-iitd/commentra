// Read an integer input from the user, which represents the number of test cases
Scanner sc = new Scanner(System.in);
int n = sc.nextInt();

// Loop through each test case
for (int i = 0; i < n; i++) {
    // Read an integer input for the current test case
    int a = sc.nextInt();
    
    // Check if the input number is less than 2
    if (a < 2) {
        // If true, print 0 as the output for this case
        System.out.println(0);
    }
    
    // Check if the input number is greater than or equal to 2
    if (a >= 2) {
        // If true, print the result of (a - 2)
        System.out.println(a - 2);
    }
}

