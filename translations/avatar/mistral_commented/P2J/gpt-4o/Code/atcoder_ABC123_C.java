import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Create a Scanner object for input
        Scanner scanner = new Scanner(System.in);

        // Define a constant variable N, which is the input number
        int N = scanner.nextInt();

        // Define an array A, which consists of five integers, each input as a separate line
        int[] A = new int[5];
        for (int i = 0; i < 5; i++) {
            A[i] = scanner.nextInt();
        }

        // Calculate the minimum value in the array A
        int minValue = A[0];
        for (int i = 1; i < A.length; i++) {
            if (A[i] < minValue) {
                minValue = A[i];
            }
        }

        // Calculate the ceiling value of N divided by the minimum value in the array A
        int ceilingValue = (int) Math.ceil((double) N / minValue);

        // Add 4 to the ceiling value to get the final answer
        int finalAnswer = ceilingValue + 4;

        // Print the final answer
        System.out.println(finalAnswer);

        // Close the scanner
        scanner.close();
    }
}
// <END-OF-CODE>
