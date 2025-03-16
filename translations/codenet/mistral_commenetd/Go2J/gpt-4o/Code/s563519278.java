import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Initialize variable N to store the number of elements in the array
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt(); // Read the number of elements from the standard input

        // Initialize an array 'v' of size N to store the frequency of each element
        int[] v = new int[N];

        // Iterate through the input elements and update the frequency in the array 'v'
        for (int i = 1; i < N; i++) {
            // Read the next element from the standard input
            int a = scanner.nextInt();
            // Update the frequency of the element 'a-1' in the array 'v'
            v[a - 1]++;
        }

        // Iterate through the array 'v' and print each element to the standard output
        for (int e : v) {
            System.out.println(e);
        }

        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
