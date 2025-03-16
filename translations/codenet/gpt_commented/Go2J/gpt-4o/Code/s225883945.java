import java.util.Scanner;

public class Main {
    // Initialize a new scanner to read input from standard input
    private static final Scanner sc = new Scanner(System.in);

    // Function to read the next line of input as an integer
    private static int nextInt() {
        return sc.nextInt(); // Return the next integer from input
    }

    // Function to read 'n' integers from input and return them as an array
    private static int[] nextInts(int n) {
        int[] array = new int[n]; // Create an array to hold 'n' integers
        for (int i = 0; i < n; i++) {
            array[i] = nextInt(); // Fill the array with integers from input
        }
        return array; // Return the array of integers
    }

    public static void main(String[] args) {
        // Read two integers from input: n (number of elements) and k (some parameter)
        int n = nextInt();
        int k = nextInt();

        // Read 'n' integers into array 'a'
        int[] a = nextInts(n);

        // Avoid unused variable error by assigning a value to the first element of 'a'
        a[0] = 0;

        // Initialize sum with the value of k and set ans to 1
        int sum = k;
        int ans = 1;

        // Loop to calculate how many times we can add k to the sum until it reaches or exceeds n
        while (sum < n) {
            sum = sum - 1 + k; // Update sum by subtracting 1 and adding k
            ans++; // Increment the answer counter
        }

        // Print the final answer
        System.out.println(ans);
    }
}

// <END-OF-CODE>
