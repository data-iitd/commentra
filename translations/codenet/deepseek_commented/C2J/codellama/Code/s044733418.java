
// Include the standard input/output library
import java.util.Scanner;

// Define a function to compare two integers
public static int compare(int a, int b)
{
    return b - a;  // Return the difference between the two integers
}

public static void main(String[] args)  // Define the main function
{
    int[] array = new int[10];  // Declare an array of 10 integers
    Scanner sc = new Scanner(System.in);  // Create a Scanner object to read input
    for(int i = 0; i != 10; i++)  // Read 10 integers from the input
        array[i] = sc.nextInt();
    java.util.Arrays.sort(array, new java.util.Comparator<Integer>() {  // Sort the array using the Arrays.sort function and the compare function
        public int compare(Integer a, Integer b)
        {
            return compare(a, b);
        }
    });
    for(int i = 0; i != 3; i++)  // Print the first three elements of the sorted array
        System.out.println(array[i]);
}

