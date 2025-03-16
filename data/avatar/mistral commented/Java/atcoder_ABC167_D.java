
import java.util.* ; // Importing the utility class Scanner

public class Main { // Defining the Main class
    Scanner sc = new Scanner(System.in); // Creating a new Scanner object to read input
    final int MOD = 1000000007; // Defining a constant value for modulo arithmetic
    final int MAX = Integer.MAX_VALUE; // Defining a constant value for maximum integer
    final long LMAX = Long.MAX_VALUE; // Defining a constant value for maximum long
    int len = (int) 1e6 + 1; // Defining the length of an array

    void doIt() { // Defining the method doIt() to contain the logic of the program
        int N = sc.nextInt(); // Reading the number of elements in the array
        long K = sc.nextLong(); // Reading the long value K
        int[] A = new int[N]; // Creating an integer array A of size N

        // Reading the elements of the array A
        for (int i = 0; i < N; i++) {
            A[i] = sc.nextInt() - 1; // Subtracting 1 from the input to get the index of the previous element
        }

        Set<Integer> used = new HashSet<>(); // Creating a HashSet named used to store the indices that have already been processed
        int idx[] = new int[N]; // Creating an integer array named idx to store the position of the current index in the circular array
        int pos[] = new int[N]; // Creating an integer array named pos to store the position of the previous index in the circular array
        int next = 0, cur = 0; // Initializing the variables next and cur

        // Finding the cycle starting point using BFS
        while (!used.contains(next)) {
            used.add(next); // Adding the current index to the HashSet used
            idx[next] = cur; // Storing the current position in the idx array
            pos[cur] = next; // Storing the previous position in the pos array
            next = A[next]; // Moving to the next index
            cur++; // Incrementing the current position
        }

        long a = (long) cur - idx[next]; // Calculating the length of the cycle
        long b = (long) idx[next]; // Calculating the starting position of the cycle in the array
        int ans = (int) (10000 * a + K - b + MOD) % a + b; // Calculating the answer using the formula

        // Checking if the starting position of the cycle is greater than K, if yes then the answer is K
        if (b > K) {
            ans = (int) K;
        }

        System.out.println(pos[ans] + 1); // Printing the position of the answer in the array
    }

    public static void main(String[] args) { // Defining the main method to start the execution of the program
        new Main().doIt(); // Calling the doIt() method to execute the logic of the program
    }
}