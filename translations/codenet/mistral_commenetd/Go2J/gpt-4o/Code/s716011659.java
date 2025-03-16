import java.util.Scanner;

public class Main {
    private static final double INF = 1e12; // Constants should be defined with clear names and values

    public static void main(String[] args) {
        // Initialize variables and read input
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();

        int[] arrA = new int[n]; // Create an array of size n to store input
        for (int i = 0; i < n; i++) {
            arrA[i] = scanner.nextInt(); // Read each element of the array
        }

        int[] cumSumA = new int[n + 1]; // Create an array of size n+1 to store cumulative sum
        cumSumA[0] = 0; // Initialize the first element of cumulative sum array
        for (int i = 0; i < n; i++) { // Iterate through the array and calculate cumulative sum
            cumSumA[i + 1] = cumSumA[i] + arrA[i];
        }

        // Initialize variable to store the answer
        double ans = INF; // Initialize with a large value

        // Iterate through the array to find the answer
        for (int i = 1; i < n; i++) {
            double temp = cumSumA[n] - cumSumA[i] * 2; // Calculate the difference
            if (Math.abs(temp) < ans) { // If the difference is smaller than the current answer
                ans = temp; // Update the answer
            }
        }

        // Print the answer
        System.out.println((int) ans);

        // End of the code
    }
}
