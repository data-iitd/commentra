
// Function A is not defined in the provided code.
void A(void) {
    // Function implementation here (if needed)
}

// Function B is defined to take input and calculate the number of iterations.
void B(void) {
    long long int x, sum;
    Scanner in = new Scanner(System.in);
    x = in.nextLong();
    int i = 0; // Initialize i to 0
    sum = 100; // Initialize sum to 100
    for (; sum < x; ++i) {
        sum += sum / 100; // Increment sum by 1%
    }
    System.out.println(i); // Output the number of iterations
}

// Function C is not defined in the provided code.
void C(void) {
    // Function implementation here (if needed)
}

// Function D is not defined in the provided code.
void D(void) {
    // Function implementation here (if needed)
}

// Main function calls the B function.
public static void main(String[] args) {
    B();
}

