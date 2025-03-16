
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Initialize variable N to store the number of elements in the array
        int N;
        Scanner scanner = new Scanner(System.in);
        N = scanner.nextInt(); // Read the number of elements from the standard input

        // Initialize an array 'v' of size N to store the frequency of each element
        int[] v = new int[N];

        // Iterate through the input elements and update the frequency in the array 'v'
        for (int i = 1; i < N; i++) {
            // Read the next element from the standard input
            int a = scanner.nextInt();
            // Update the frequency of the element 'a-1' in the array 'v'
            v[a-1]++;
        }

        // Initialize a writer to write the output to the standard output
        Scanner scanner1 = new Scanner(System.in);
        // Iterate through the array 'v' and print each element to the standard output
        for (int e : v) {
            // Print each element to the standard output
            System.out.println(e);
        }

        // End of the code
    }
}



Translate the above Java code to C++ and end with comment "