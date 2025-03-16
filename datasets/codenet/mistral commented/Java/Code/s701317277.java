
import java.util.*; // Importing the utility class Scanner from java.util package

public class Main {
    
    public static void main(String args[]){ // Main method is the entry point of the Java application
        Scanner sc = new Scanner(System.in); // Creating a new Scanner object to read input from the standard input stream

        int N; // Declaring an integer variable 'N' to store the number of elements in the array 'A'
        int[] A; // Declaring an integer array 'A' of size 'N' to store the elements
        int min = Integer.MAX_VALUE; // Declaring an integer variable 'min' and initializing it with the maximum possible value of an integer
        int count = 0; // Declaring an integer variable 'count' and initializing it with zero
        long sum = 0; // Declaring a long variable 'sum' and initializing it with zero

        // Reading the number of elements 'N' from the standard input stream
        N = sc.nextInt();

        // Creating an integer array 'A' of size 'N' and reading its elements from the standard input stream
        A = new int[N];
        for(int i = 0; i < N; i++){
            A[i] = sc.nextInt(); // Reading an integer value from the standard input stream and storing it in the 'i'-th index of the array 'A'

            // Checking if the current element is negative and incrementing the 'count' variable accordingly
            if(A[i] < 0)
                count++;

            // Finding the minimum absolute value of an element in the array 'A'
            min = Math.min(min, Math.abs(A[i]));

            // Calculating the sum of the absolute values of all elements in the array 'A'
            sum += Math.abs(A[i]);
        }

        // Closing the Scanner object to prevent resource leaks
        sc.close();

        // Checking if the number of negative elements in the array 'A' is even or odd and printing the result accordingly
        if(count%2 == 0)
            System.out.println(sum); // If the number of negative elements is even, then the sum of the absolute values of all elements is the answer
        else {
            System.out.println(sum-min*2); // If the number of negative elements is odd, then the sum of the absolute values of all elements minus twice the minimum absolute value is the answer
        }
    }
}

