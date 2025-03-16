import java.util.*;

public class Main
{
    public static void main(String[] args)
    {
        // Declare an array of integers and a variable for iteration
        int[] array = new int[10];
        int i;

        // Read 10 integers from standard input into the array
        for(i = 0; i!= 10; i++)
            array[i] = Integer.parseInt(args[i]);

        // Sort the array in descending order using Arrays.sort and the compare function
        Arrays.sort(array, new Comparator<Integer>() {
            public int compare(Integer a, Integer b)
            {
                // Return the difference between b and a for descending order
                return (b - a);
            }
        });

        // Print the first 3 elements of the sorted array
        for(i = 0; i!= 3; i++)
            System.out.println(array[i]);
    }
}
