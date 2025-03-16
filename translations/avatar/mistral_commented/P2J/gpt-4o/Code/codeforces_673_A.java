import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Create a Scanner object to take input
        Scanner scanner = new Scanner(System.in);
        
        // Take the number of elements in the list as input
        int n = scanner.nextInt();
        
        // Initialize an array to store the input elements
        int[] arr = new int[n];
        
        // Read the elements into the array
        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextInt();
        }
        
        // Check if the first element of the array is greater than 15
        if (arr[0] > 15) {
            // If it is, print 15
            System.out.println(15);
        } else {
            // Else, iterate through the array starting from the second element
            for (int i = 1; i < arr.length; i++) {
                // Check if the difference between the current and previous elements is greater than 15
                if (arr[i] - arr[i - 1] > 15) {
                    // If it is, print the previous element plus 15
                    System.out.println(arr[i - 1] + 15);
                    // Break the loop as we have found the answer
                    break;
                }
            }
            // Else, if we reach here, it means that no difference was greater than 15
            if (arr[arr.length - 1] == 90 || arr[arr.length - 1] + 15 >= 90) {
                // Check if the last element of the array is 90 or if adding 15 to it results in 90 or more
                // If it is, print 90
                System.out.println(90);
            } else {
                // Else, print the last element plus 15
                System.out.println(arr[arr.length - 1] + 15);
            }
        }
        
        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
