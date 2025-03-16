import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the number of elements
        int N = Integer.parseInt(scanner.nextLine().trim());
        
        // Initialize arrays to hold the original values and a sorted copy
        int[] X = new int[N];
        int[] Y = new int[N];
        
        // Read N integers into array X and copy them to array Y
        String[] input = scanner.nextLine().split(" ");
        for (int i = 0; i < N; i++) {
            X[i] = Integer.parseInt(input[i]);
            Y[i] = X[i];
        }
        
        // Sort the array Y to find the median values
        Arrays.sort(Y);
        
        // Calculate the two middle values (medians) for even-sized arrays
        int m1 = Y[N / 2 - 1]; // First median
        int m2 = Y[N / 2];     // Second median
        
        // For each element in X, print the appropriate median based on its value
        for (int i = 0; i < N; i++) {
            if (X[i] <= m1) {
                System.out.println(m2); // If X[i] is less than or equal to m1, print m2
            } else {
                System.out.println(m1); // Otherwise, print m1
            }
        }
    }
}

