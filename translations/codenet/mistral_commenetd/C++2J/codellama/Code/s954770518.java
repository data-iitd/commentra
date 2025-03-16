import java.util.Scanner; // Import the Scanner class for input and output operations
import java.util.Arrays;  // Import the Arrays class for sorting the array

public class Main { // The Main class is the entry point of the program
    public static void main(String[] args) { // The main function is the entry point of the program
        int s[] = new int[11]; // Declare an integer array 's' of size 11
        int i; // Declare an integer variable 'i' for loop counter

        // Read 10 integers from the user and store them in the array 's'
        for(i=0;i<10;i++){
            s[i] = new Scanner(System.in).nextInt(); // Read an integer from the standard input and store it in the array 's' at the current index
        }

        // Sort the array 's' in ascending order using the sort function from the Arrays library
        Arrays.sort(s);

        // Print the 4th, 5th and 6th smallest elements from the sorted array 's'
        for(i=9;i>6;i--){ // Initialize the loop counter 'i' to 9 (index of the 5th smallest element) and decrement it until it becomes greater than the index of the 6th smallest element
            System.out.println(s[i]); // Print the current element of the array 's' to the standard output
        }
    }
}

