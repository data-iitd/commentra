import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Take the number of elements as input
        int N = scanner.nextInt();
        int[] n = new int[N];

        // Take a space-separated string of integers as input and convert them to an array of integers
        for (int i = 0; i < N; i++) {
            n[i] = scanner.nextInt();
        }

        // Initialize a counter to 1 and a position index to 0
        int a = 1;
        int pos = 0;

        // Loop through the array from the second element to the last
        for (int i = 1; i < N; i++) {
            // Check if the current minimum element is greater than the current element
            if (n[pos] > n[i]) {
                // Increment the counter and update the position index
                a++;
                pos = i;
            }
        }

        // Print the final count of elements that are greater than the current minimum
        System.out.println(a);
        
        scanner.close();
    }
}

// <END-OF-CODE>
