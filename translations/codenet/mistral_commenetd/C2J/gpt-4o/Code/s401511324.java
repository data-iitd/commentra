import java.util.Scanner; // Import the Scanner class for input

public class Main { // Define the Main class
    public static void main(String[] args) { // Start of the main method
        Scanner scanner = new Scanner(System.in); // Create a Scanner object for input
        int n; // Declare an integer variable 'n' to store the number of elements
        int[] l = new int[2001]; // Declare an integer array 'l' of size 2001
        int cnt = 0; // Declare an integer variable 'cnt' and initialize it to zero

        n = scanner.nextInt(); // Read an integer value from the standard input and store it in 'n'

        for (int i = 0; i < n; i++) { // Iterate through all elements of the array 'l'
            l[i] = scanner.nextInt(); // Read an integer value from the standard input and store it in the current index of 'l'
        }

        // Sort the array 'l' using a simple bubble sort algorithm
        for (int i = 0; i < n - 1; i++) { // Iterate through all elements except the last one in the array 'l'
            for (int j = i + 1; j < n; j++) { // Iterate through the remaining elements
                if (l[j] < l[i]) { // If the current element is smaller than the previous one
                    int tmp = l[i]; // Swap the current and previous elements
                    l[i] = l[j];
                    l[j] = tmp; // Update the array 'l' with the swapped elements
                }
            }
        }

        for (int i = 0; i < n - 2; i++) { // Iterate through all elements except the last two in the array 'l'
            for (int j = i + 1; j < n - 1; j++) { // Iterate through the remaining elements except the last one
                for (int k = j + 1; k < n; k++) { // Iterate through the remaining elements
                    if (l[i] + l[j] > l[k]) { // Check if the sum of the first two elements is greater than the third one
                        cnt++; // Increment the counter if the condition is true
                    } else { // If the condition is false, break out of the inner loop
                        break;
                    }
                }
            }
        }

        System.out.println(cnt); // Print the value of the counter to the standard output
        scanner.close(); // Close the scanner
    } // End of the main method
} // End of the Main class
// <END-OF-CODE>
