import java.util.Scanner;
import java.util.ArrayList;
import java.util.Collections;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt(); // Reading the number of elements
        int T = scanner.nextInt(); // Reading the threshold value
        int[] A = new int[N]; // Declaring an array to store the elements
        ArrayList<Integer> B = new ArrayList<>(N); // Declaring a list to store the differences
        for (int i = 0; i < N; i++) {
            A[i] = scanner.nextInt(); // Reading the elements into the array
        }

        // Initializing the minimum value with the first element of A
        int m = A[0];
        // Calculating the difference between the second element and the initial minimum, and storing it in B.get(1)
        B.add(1, A[1] - m);
        // Updating the minimum value to be the minimum of its current value and the second element of A
        m = Math.min(m, A[1]);
        // For each subsequent element in A, calculate the difference, update the minimum, and add the difference to B
        for (int i = 2; i < N; i++) {
            B.add(i, A[i] - m);
            m = Math.min(m, A[i]);
        }

        // Finding the maximum value in B
        int max_value = Collections.max(B);
        // Counting how many times the maximum value appears in B
        int count = Collections.frequency(B, max_value);
        System.out.println(count);
    }
}
