import java.util.Scanner;

public class Main {
    // Function to perform the main logic of the program
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Initialize variables n and m with the given input
        int n = scanner.nextInt();
        int m = scanner.nextInt();

        // Initialize arrays roundComplexity and georgeComplexity
        int[] roundComplexity = new int[n];
        int[] georgeComplexity = new int[m];

        // Read the round complexities
        for (int i = 0; i < n; i++) {
            roundComplexity[i] = scanner.nextInt();
        }

        // Read George's complexities
        for (int j = 0; j < m; j++) {
            georgeComplexity[j] = scanner.nextInt();
        }

        // Initialize variables i and j to 0
        int i = 0, j = 0;

        // Start the while loop that compares the complexity of each
        // round with George's complexity and moves the pointers accordingly
        while (i < n && j < m) {
            // Increment i if the complexity of the current round is
            // less than or equal to George's complexity at the current j
            if (roundComplexity[i] <= georgeComplexity[j]) {
                i++;
            }
            // Increment j
            j++;
        }

        // Print the final answer
        System.out.println(n - i);
        
        scanner.close();
    }
}

// <END-OF-CODE>
