
// Function to perform the main logic of the program
public static void main(String[] args) {

    // Initialize variables n and m with the given input
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int m = sc.nextInt();

    // Initialize lists round_complexity and george_complexity
    // with the given input
    int[] round_complexity = new int[n];
    int[] george_complexity = new int[m];
    for (int i = 0; i < n; i++) {
        round_complexity[i] = sc.nextInt();
    }
    for (int i = 0; i < m; i++) {
        george_complexity[i] = sc.nextInt();
    }

    // Initialize variables i and j to 0
    int i = 0;
    int j = 0;

    // Start the while loop that compares the complexity of each
    // round with George's complexity and moves the pointers accordingly
    while (i < n && j < m) {

        // Increment i if the complexity of the current round is
        // less than or equal to George's complexity at the current j
        i += 1 if (round_complexity[i] <= george_complexity[j]) else 0;

        // Increment j
        j += 1;
    }

    // Print the final answer
    System.out.println(n - i);
}

