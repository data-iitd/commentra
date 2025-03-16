// Read two integers from input and assign them to variables a and b
Scanner sc = new Scanner(System.in);
int a = sc.nextInt();
int b = sc.nextInt();

// Initialize a variable c to accumulate the result
int c = 0;

// Loop for 2 iterations
for (int i = 0; i < 2; i++) {
    // Add the maximum of a and b to c
    c += Math.max(a, b);
    
    // Decrease the larger of the two numbers (a or b) by 1
    if (a >= b) {
        a--;  // If a is greater than or equal to b, decrement a
    } else {
        b--;  // Otherwise, decrement b
    }
}

// Print the final accumulated value of c
System.out.println(c);

