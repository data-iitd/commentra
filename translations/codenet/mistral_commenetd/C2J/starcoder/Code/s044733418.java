
import java.util.Arrays;
import java.util.Scanner;

public class Main
{
    public static void main(String[] args)
    {
        int[] array = new int[10]; // Declare an array of 10 integers
// Initialize an array of 10 integers

        Scanner input = new Scanner(System.in);

        for(int i = 0; i < 10; i++) // Iterate through the array to read 10 integers
        {
            array[i] = input.nextInt();
// Read an integer from the user and store it in the array
        }

        Arrays.sort(array);
// Sort the array using the quicksort algorithm

        for(int i = 0; i < 3; i++) // Iterate through the first three elements of the sorted array
        {
            System.out.println(array[i]);
// Print the first three sorted integers
        }
    }
}

