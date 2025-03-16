public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);

        // Initialize variables n and m with the given input
        int n = scanner.nextInt();
        int m = scanner.nextInt();

        // Initialize arrays round_complexity and george_complexity
        // with the given input
        int[] round_complexity = new int[n];
        for (int i = 0; i < n; i++) {
            round_complexity[i] = scanner.nextInt();
        }

        int[] george_complexity = new int[m];
        for (int i = 0; i < m; i++) {
            george_complexity[i] = scanner.nextInt();
        }

        // Initialize variables i and j to 0
        int i = 0;
        int j = 0;

        // Start the while loop that compares the complexity of each
        // round with George's complexity and moves the pointers accordingly
        while (i < n && j < m) {

            // Increment i if the complexity of the current round is
            // less than or equal to George's complexity at the current j
            if (round_complexity[i] <= george_complexity[j]) {
                i++;
            }

            // Increment j
            j++;
        }

        // Print the final answer
        System.out.println(n - i);
    }
}
