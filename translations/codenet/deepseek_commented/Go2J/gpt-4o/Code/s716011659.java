import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int n = scanner.nextInt(); // Reading the size of the array
        int[] arrA = new int[n];
        
        for (int i = 0; i < n; i++) {
            arrA[i] = scanner.nextInt(); // Reading the elements of the array
        }

        int[] cumSumA = new int[n + 1];
        cumSumA[0] = 0; // Initialize the cumulative sum array
        for (int i = 0; i < n; i++) {
            cumSumA[i + 1] = cumSumA[i] + arrA[i]; // Calculate cumulative sums
        }

        double ans = 10000000000.0; // Initialize the answer with a large number
        for (int i = 1; i < n; i++) {
            double difference = Math.abs(cumSumA[n] - (cumSumA[i] * 2));
            if (difference < ans) {
                ans = difference; // Update the answer if a smaller difference is found
            }
        }

        System.out.println((int) ans); // Output the minimum difference
        scanner.close();
    }
}
// <END-OF-CODE>
