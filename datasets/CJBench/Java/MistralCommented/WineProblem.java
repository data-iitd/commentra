import java.util.Scanner; // Importing the Scanner class for user input

public final class Main { // Defining a final class named Main
    private Main() { // Private constructor to prevent instantiation of the class
    }

    public static void main(String[] args) { // Main method to start the program
        Scanner scanner = new Scanner(System.in); // Creating a new Scanner object for user input

        int n = scanner.nextInt(); // Reading the number of elements in the array from user input

        if (n <= 0) { // Checking if the input is valid
            System.out.println("Invalid input. Please enter a positive integer.");
            scanner.close(); // Closing the Scanner if the input is invalid
            return;
        }

        int[] arr = new int[n]; // Creating an integer array of size n

        for (int i = 0; i < n; i++) { // Reading elements of the array from user input
            arr[i] = scanner.nextInt();
        }

        int result = wpbu(arr); // Calling the wpbu method to find the maximum profit

        System.out.println("Maximum profit: " + result); // Printing the maximum profit to the console

        scanner.close(); // Closing the Scanner after use
    }

    public static int wpbu(int[] arr) { // Method to find the maximum profit using the WPP algorithm
        if (arr == null || arr.length == 0) { // Checking if the input array is null or empty
            throw new IllegalArgumentException("Input array cannot be null or empty.");
        }

        int n = arr.length; // Assigning the length of the array to a variable

        if (n == 1) { // Special case for arrays with only one element
            return arr[0] * (n + 1);
        }

        int[][] strg = new int[n][n]; // Creating a 2D array to store intermediate results

        for (int slide = 0; slide <= n - 1; slide++) { // Iterating through all possible sliding windows
            for (int si = 0; si <= n - slide - 1; si++) { // Iterating through all possible starting indices
                int ei = si + slide; // Calculating the ending index of the current window
                int year = n - (ei - si) + 1; // Calculating the number of years in the current window

                if (si == ei) { // Base case for a single element window
                    strg[si][ei] = arr[si] * year;
                } else { // Recursive case for a window with more than one element
                    int start = strg[si + 1][ei] + arr[si] * year; // Maximum profit for the subarray from si+1 to ei
                    int end = strg[si][ei - 1] + arr[ei] * year; // Maximum profit for the subarray from si to ei-1
                    strg[si][ei] = Math.max(start, end); // Choosing the maximum profit between the two subarrays
                }
            }
        }

        return strg[0][n - 1]; // Returning the maximum profit for the entire array
    }
}
