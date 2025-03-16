import java.util.Scanner;  // Importing the Scanner class for taking input
import java.util.Arrays;   // Importing Arrays class for array manipulation

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);  // Creating a Scanner object for input

        // Taking input for the number of elements
        System.out.print("Enter the number of elements: ");
        int N = scanner.nextInt();  

        // Taking input for the elements and converting them into an array of integers
        System.out.print("Enter the elements separated by spaces: ");
        int[] n = new int[N];
        for (int i = 0; i < N; i++) {
            n[i] = scanner.nextInt();
        }

        // Initializing a counter 'a' to count the number of elements that are less than the current element
        int a = 1;  

        // Initializing 'pos' to keep track of the position of the last element that was smaller
        int pos = 0;  

        // Looping through the array starting from the second element
        for (int i = 1; i < N; i++) {  
            // Checking if the current element is smaller than the element at 'pos'
            if (n[pos] > n[i]) {  
                a++;  // Incrementing the counter if the condition is met
                pos = i;  // Updating 'pos' to the current index
            }
        }

        // Printing the final count of elements that were smaller than the previous ones
        System.out.println(a);  

        scanner.close();  // Closing the scanner
    }
}

// <END-OF-CODE>
