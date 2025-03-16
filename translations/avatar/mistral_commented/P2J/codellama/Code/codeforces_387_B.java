// Function to perform the main logic of the program
public static void main(String[] args) {

    // Initialize variables n and m with the given input
    int n = Integer.parseInt(args[0]);
    int m = Integer.parseInt(args[1]);

    // Initialize lists round_complexity and george_complexity
    // with the given input
    int[] round_complexity = new int[n];
    int[] george_complexity = new int[m];

    // Initialize variables i and j to 0
    int i = 0;
    int j = 0;

    // Start the while loop that compares the complexity of each
    // round with George's complexity and moves the pointers accordingly
    while (i < n && j < m) {

        // Increment i if the complexity of the current round is
        // less than or equal to George's complexity at the current j
        i += (round_complexity[i] <= george_complexity[j]) ? 1 : 0;

        // Increment j
        j += 1;
    }

    // Print the final answer
    System.out.println(n - i);
}

// End of code
