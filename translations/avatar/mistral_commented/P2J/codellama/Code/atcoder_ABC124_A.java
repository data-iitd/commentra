
// Get two integers as input from the user, separated by a space
Scanner sc = new Scanner(System.in);
int a = sc.nextInt();
int b = sc.nextInt();

// Initialize a variable 'c' to store the sum of the larger numbers in each iteration
int c = 0;

// Loop through the given condition for 2 times
for (int i = 0; i < 2; i++) {

    // Calculate the sum of the larger number in each iteration and add it to the variable 'c'
    c += Math.max(a, b);

    // Update the smaller number in each iteration
    if (a >= b) {
        a--;
    } else {
        b--;
    }
}

// Print the final result
System.out.println(c);

