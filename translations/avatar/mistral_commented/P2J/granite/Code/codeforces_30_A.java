
// Function to find a number X raised to the power n such that A * X^n equals B
public static int task4(int A, int B, int n) {

    // Iterate through all possible values of X from -1000 to 1000
    for (int X = -1000; X <= 1000; X++) {

        // Check if the condition A * X^n equals B is satisfied
        if (A * (int) Math.pow(X, n) == B) {

            // If the condition is satisfied, return the value of X
            return X;
        }
    }

    // If no solution is found, return a message indicating that
    return -1;
}

// Get input values of A, B, and n from the user
Scanner scanner = new Scanner(System.in);
int A = scanner.nextInt();
int B = scanner.nextInt();
int n = scanner.nextInt();

// Call the function and print the result
int result = task4(A, B, n);
if (result!= -1) {
    System.out.println(result);
} else {
    System.out.println("No solution");
}

