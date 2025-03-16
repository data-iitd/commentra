import java.util.PriorityQueue; // Importing PriorityQueue from java.util package
import java.util.Queue; // Importing Queue from java.util package
import java.util.Scanner; // Importing Scanner from java.util package

public class Main {
    // Main method is the entry point of the Java application
    public static void main(String[] args) {
        // Initialize System.out for printing output
        System.out.println(solve()); // Calling solve method to get the solution and print it
    }

    // solve method to find the solution
    public static int solve() {
        Scanner sc = new Scanner(System.in); // Creating a new Scanner object to read input

        int N = sc.nextInt(); // Reading the number of elements in the array

        int[] arr = new int[N]; // Creating an integer array of size N

        // Using for loop to read and store elements in the array
        for (int i = 0; i < N; i++) {
            arr[i] = sc.nextInt(); // Reading an integer and storing it in the array at the current index
        }

        int sum = 0; // Initializing sum variable to 0
        Queue<Integer> q = new PriorityQueue<>(); // Creating an empty PriorityQueue

        // Using for loop to iterate through the array
        for (int i = 0; i < arr.length; i++) {
            q.add(arr[i]); // Adding the current element to the queue

            // Checking if the current element is smaller than or equal to the top element of the queue
            if (arr[i] <= q.peek()) {
                sum++; // Incrementing sum if the condition is true
            }
        }

        // Closing the scanner after use
        sc.close();

        // Returning the sum as the solution
        return sum;
    }
}
