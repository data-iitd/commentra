// Declare global variables
long N; // N is the number of elements
long[] A; // A is the array to hold the elements
long[][][] dp; // dp array for dynamic programming

public static void main(String[] args) {
    // Read the number of elements
    Scanner sc = new Scanner(System.in);
    N = sc.nextLong();

    // Read the elements into the array A
    A = new long[N + 1];
    for (int i = 1; i <= N; i++) A[i] = sc.nextLong();

    // Initialize the dp array with a very small value
    dp = new long[N + 1][2][20];
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j < 20; j++) {
            dp[i][0][j] = -1000000000000000000L; // Initialize dp for state 0
            dp[i][1][j] = -1000000000000000000L; // Initialize dp for state 1
        }
    }

    // Base case: when no elements are considered, the value at dp[0][0][10] is 0
    dp[0][0][10] = 0;

    // Fill the dp array based on previous states
    for (int i = 1; i <= N; i++) {
        for (int j = 6; j <= 14; j++) {
            // If the previous state in dp[i-1][0][j] is valid
            if (dp[i - 1][0][j] != 1000000000000000000L) {
                // Update the state dp[i][1][j + 1] by adding the current element A[i]
                dp[i][1][j + 1] = Math.max(dp[i][1][j + 1], dp[i - 1][0][j] + A[i]);
                // Update the state dp[i][0][j - 1] without adding the current element
                dp[i][0][j - 1] = Math.max(dp[i][0][j - 1], dp[i - 1][0][j]);
            }
            // If the previous state in dp[i-1][1][j] is valid
            if (dp[i - 1][1][j] != 1000000000000000000L) {
                // Update the state dp[i][0][j - 1] without adding the current element
                dp[i][0][j - 1] = Math.max(dp[i][0][j - 1], dp[i - 1][1][j]);
            }
        }
    }

    // Calculate the target value V based on the number of elements
    long V = 10L + (N / 2) - (N - (N / 2));
    
    // Retrieve the maximum values from the last state of dp
    long T1 = dp[N][0][V];
    long T2 = dp[N][1][V];

    // Output the maximum value obtained from the two states
    System.out.println(Math.max(T1, T2));

    // End of the program
}

