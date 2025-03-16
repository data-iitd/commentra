import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the number of elements in round_complexity and george_complexity
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        
        // Read the complexities of the rounds
        int[] roundComplexity = new int[n];
        for (int i = 0; i < n; i++) {
            roundComplexity[i] = scanner.nextInt();
        }
        
        // Read the complexities of George's challenges
        int[] georgeComplexity = new int[m];
        for (int j = 0; j < m; j++) {
            georgeComplexity[j] = scanner.nextInt();
        }
        
        // Initialize counters for both lists
        int i = 0, j = 0;
        
        // Loop through both lists to compare complexities
        while (i < n && j < m) {
            // Increment i if the current round complexity is less than or equal to George's complexity
            if (roundComplexity[i] <= georgeComplexity[j]) {
                i++;
            }
            // Increment j to move to the next element in georgeComplexity
            j++;
        }
        
        // Print the number of rounds George can solve
        System.out.println(n - i);
        
        scanner.close();
    }
}

// <END-OF-CODE>
