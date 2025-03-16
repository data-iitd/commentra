import java.util.*; // Importing the utility package for using Scanner and Arrays
import static java.lang.Math.*; // Importing static methods from the Math class

public class Main {
    public static void main(String[] args) {
        // Creating a Scanner object to read input from the console
        Scanner sc = new Scanner(System.in);
        
        // Reading the integer n which determines the size of the array
        int n = sc.nextInt();
        
        // Initializing an array of size 3*n to hold the input values
        int[] array = new int[3 * n];
        
        // Filling the array with user input values
        for (int i = 0; i < array.length; i++) {
            array[i] = sc.nextInt();
        }
        
        // Sorting the array in ascending order
        Arrays.sort(array);
        
        // Setting the head pointer to the second last element of the sorted array
        int head = array.length - 2;
        
        // Initializing a variable to accumulate the result
        long res = 0;
        
        // Looping n times to sum up the required elements from the sorted array
        for (int i = 0; i < n; i++) {
            res += array[head]; // Adding the current element pointed by head to the result
            head -= 2; // Moving the head pointer two positions to the left for the next iteration
        }
        
        // Printing the final result
        System.out.println(res);
    }
}
