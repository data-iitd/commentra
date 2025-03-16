import java.util.Scanner; // Importing the Scanner class for user input

public class Main { // Defining the main class named Main

    public static void main(String[] args) { // Defining the main method
        @SuppressWarnings("resource") // Suppressing warnings for creating a Scanner object inside the method
        Scanner sc = new Scanner(System.in); // Creating a new Scanner object for user input

        int n = sc.nextInt(); // Reading the number of elements in the array from user input

        int[] h = new int[n]; // Creating an integer array named h with size n

        for (int i = 0 ; i < n ; i++) { // Iterating through the array to read elements from user input
            h[i] = sc.nextInt();
        }

        int max = 0; // Initializing the variable max to 0

        for (int l = 0 ; l < n - 1 ; l++) { // Iterating through the array to find the length of increasing subsequences
            int count = 0; // Initializing the variable count to 0

            while (l < n - 1 && h[l] >= h[l + 1]) { // Finding the length of the current increasing subsequence
                l++;
                count++;
            }

            max = Math.max(max, count); // Updating the maximum length of increasing subsequence found so far
        }

        System.out.println(max); // Printing the maximum length of increasing subsequence
    }

}
