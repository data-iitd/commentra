import java.util.Scanner; // Importing Scanner class for reading input

public class Main {

    private static Scanner sc = new Scanner(System.in); // Creating a Scanner object for input

    public static void main(String[] args) {
        new Thread(null, new Main(), "", 128 * 1024 * 1024).start(); // Starting a new thread with the current instance of Main
    }

    public void run() {
        int n = sc.nextInt(); // Reading the number of elements
        int[] a = new int[n]; // Creating an array to store the elements
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt(); // Reading the elements and storing them in the array
        }
        long cost1 = 0; // Initializing the cost for the first pointer
        long cost2 = 0; // Initializing the cost for the second pointer
        int current1 = 0; // Initializing the current position for the first pointer
        int current2 = 0; // Initializing the current position for the second pointer
        long[] dp1 = new long[n]; // Creating an array to store the costs for the first pointer
        long[] dp2 = new long[n]; // Creating an array to store the costs for the second pointer
        for (int i = 0, j = n - 1; i < n; i++, j--) {
            cost1 += Math.abs(a[i] - current1); // Calculating the cost for the first pointer
            current1 = a[i]; // Updating the current position for the first pointer
            dp1[i] = cost1; // Storing the cost in the array
            cost2 += Math.abs(a[j] - current2); // Calculating the cost for the second pointer
            current2 = a[j]; // Updating the current position for the second pointer
            dp2[j] = cost2; // Storing the cost in the array
        }

        for (int i = 0; i < n; i++) {
            if (i == 0) {
                System.out.println(dp2[i + 1] + Math.abs(a[1])); // Printing the result for the first element
            } else if (i == n - 1) {
                System.out.println(dp1[i - 1] + Math.abs(a[i - 1])); // Printing the result for the last element
            } else {
                System.out.println(dp1[i - 1] + dp2[i + 1] + Math.abs(a[i - 1] - a[i + 1])); // Printing the result for the intermediate elements
            }
        }
    }
}
