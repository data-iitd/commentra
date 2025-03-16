
public class Solution {
    public static void main(String[] args) {
        // Declare a variable to hold the size of the array
        long n;

        // Read the size of the array from user input
        Scanner sc = new Scanner(System.in);
        n = sc.nextLong();

        // Declare two arrays: one to hold the input values and another to count occurrences
        long[] a = new long[n];
        long[] count = new long[n];

        // Read the input values into the array 'a', starting from index 1
        for (long i = 1; i < n; i++)
            a[i] = sc.nextLong();

        // Initialize the count array to zero for all indices
        for (long i = 0; i < n; i++)
            count[i] = 0;

        // Count the occurrences of each value in the array 'a'
        // The value at a[i] is used to index into the count array
        for (long i = 1; i < n; i++)
            count[a[i]-1]++;

        // Print the counts of each index in the count array
        for (long i = 0; i < n; i++)
            System.out.println(count[i]);

        // Return 0 to indicate successful completion of the program
        sc.close();
    }
}

