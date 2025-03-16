
// Function to compare two integers for sorting
int compare(int a, int b)
{
    // Return the difference between b and a for descending order
    return (b - a);
}

public class Main
{
    public static void main(String[] args)
    {
        // Declare an array of integers and a variable for iteration
        int[] array = new int[10];
        int i;

        // Read 10 integers from standard input into the array
        for(i = 0; i != 10; i++)
            array[i] = Integer.parseInt(args[i]);

        // Sort the array in descending order using qsort and the compare function
        java.util.Arrays.sort(array, new java.util.Comparator<Integer>() {
            public int compare(Integer a, Integer b) {
                return compare(a, b);
            }
        });

        // Print the first 3 elements of the sorted array
        for(i = 0; i != 3; i++)
            System.out.println(array[i]);

        // Return 0 to indicate successful completion of the program
        return 0;
    }
}

