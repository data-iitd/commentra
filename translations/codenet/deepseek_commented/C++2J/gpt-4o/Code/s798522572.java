import java.util.Scanner;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int N = scanner.nextInt(); // Reading the number of elements
        int T = scanner.nextInt(); // Reading the threshold value
        int[] A = new int[N]; // Declaring an array to store the elements
        int[] B = new int[N]; // Declaring an array to store the differences
        
        for (int i = 0; i < N; i++) {
            A[i] = scanner.nextInt(); // Reading the elements into the array
        }

        // Initializing the minimum value with the first element of A
        int m = A[0];
        // Calculating the difference between the second element and the initial minimum, and storing it in B[1]
        B[1] = A[1] - m;
        // Updating the minimum value to be the minimum of its current value and the second element of A
        m = Math.min(m, A[1]);
        
        // For each subsequent element in A, calculate the difference, update the minimum, and store the difference in B
        for (int i = 2; i < N; i++) {
            B[i] = A[i] - m;
            m = Math.min(m, A[i]);
        }

        // Finding the maximum value in B
        int max_value = Arrays.stream(B).max().getAsInt();
        // Counting how many times the maximum value appears in B
        long count = Arrays.stream(B).filter(x -> x == max_value).count();
        
        System.out.println(count);
        
        scanner.close();
    }
}

// <END-OF-CODE>
