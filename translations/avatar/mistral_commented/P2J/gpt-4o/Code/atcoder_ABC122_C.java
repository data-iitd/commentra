import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Creating a Scanner object for input
        Scanner scanner = new Scanner(System.in);

        // Taking input for number of strings 'n' and number of problems 'q'
        int n = scanner.nextInt();
        int q = scanner.nextInt();
        scanner.nextLine(); // Consume the newline character

        // Taking input for the string 's'
        String s = scanner.nextLine();

        // Array to store the start and end indices of each problem
        int[][] problems = new int[q][2];
        for (int i = 0; i < q; i++) {
            problems[i][0] = scanner.nextInt();
            problems[i][1] = scanner.nextInt();
        }

        // Array to store the cumulative sum of 'AC' substrings
        int[] cumsum = new int[n];
        int total = 0;

        // Calculate the cumulative sum of 'AC' substrings in the string 's'
        for (int i = 1; i < n; i++) {
            if (s.substring(i - 1, i + 1).equals("AC")) {
                total++;
            }
            cumsum[i] = total;
        }

        // Iterating through each problem in the list 'problems' and printing the difference
        for (int i = 0; i < q; i++) {
            int l = problems[i][0];
            int r = problems[i][1];
            // Print the difference between the cumulative sum at the end and start of the problem
            System.out.println(cumsum[r - 1] - cumsum[l - 1]);
        }

        // Closing the scanner
        scanner.close();
    }
}
// <END-OF-CODE>
