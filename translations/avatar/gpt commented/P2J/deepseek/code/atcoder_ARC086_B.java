import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the number of elements
        int N = scanner.nextInt();
        
        // Read the list of integers
        int[] a = new int[N];
        for (int i = 0; i < N; i++) {
            a[i] = scanner.nextInt();
        }
        
        // Initialize variables to track the maximum absolute value, its sign, and index
        int maxVal = 0;
        int maxSign = 0;
        int maxIndex = -1;
        
        // Loop through the list to find the maximum absolute value and its properties
        for (int i = 0; i < N; i++) {
            if (Math.abs(a[i]) > maxVal) {
                maxVal = Math.abs(a[i]);
                maxSign = Integer.compare(a[i], 0);
                maxIndex = i;
            }
        }
        
        // Check the sign of the maximum value and print results accordingly
        if (maxSign == 0) {
            // If the maximum sign is zero, print 0
            System.out.println(0);
        } else if (maxSign == 1) {
            // If the maximum sign is positive, print the number of operations and the operations
            System.out.println(2 * N - 1);
            for (int i = 0; i < N; i++) {
                System.out.println((maxIndex + 1) + " " + (i + 1));
            }
            for (int i = 0; i < N - 1; i++) {
                System.out.println((i + 1) + " " + (i + 2));
            }
        } else {
            // If the maximum sign is negative, print the number of operations and the operations
            System.out.println(2 * N - 1);
            for (int i = 0; i < N; i++) {
                System.out.println((maxIndex + 1) + " " + (i + 1));
            }
            for (int i = N - 1; i > 0; i--) {
                System.out.println((i + 1) + " " + i);
            }
        }
        
        scanner.close();
    }
}
