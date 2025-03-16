import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt(); // Number of days
        int D = scanner.nextInt(); // Maximum days
        int X = scanner.nextInt(); // Extra chocolate
        int[] A = new int[101]; // Array to store the number of chocolate pieces for each day
        for (int i = 0; i < N; i++) {
            A[i] = scanner.nextInt(); // Read the number of chocolate pieces for the i-th day
        }
        int numOfChocolate = 0; // Total number of chocolate pieces
        for (int i = 0; i < N; i++) {
            int days = 0; // Number of days eaten from one chocolate piece
            int counter = 0; // Number of chocolate pieces eaten in one day
            for (int j = 0; ; j++) {
                days = j * A[i] + 1; // Calculate the number of days
                if (days <= D) { // Check if the number of days is less than or equal to the maximum number of days
                    counter++; // Increment the counter
                } else { // If the number of days is greater than the maximum number of days, break the loop
                    break;
                }
            }
            numOfChocolate += counter; // Add the number of chocolate pieces eaten in this day to the total number of chocolate pieces
        }
        numOfChocolate += X; // Add the extra chocolate
        System.out.println(numOfChocolate); // Output the result
    }
}
