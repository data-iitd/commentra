public class Main {
    public static void main(String[] args) {
        // Declare a variable to hold the size of the array
        long n;

        // Read the size of the array from user input
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        n = scanner.nextLong();
        
        // Declare two arrays: one to hold the input values and another to count occurrences
        long[] a = new long[(int)n];
        long[] count = new long[(int)n];

        // Read the input values into the array 'a', starting from index 1
        for (long i = 1; i < n; i++)
            a[(int)i] = scanner.nextLong();

        // Initialize the count array to zero for all indices
        for (long i = 0; i < n; i++)
            count[(int)i] = 0;

        // Count the occurrences of each value in the array 'a'
        // The value at a[i] is used to index into the count array
        for (long i = 1; i < n; i++)
            count[(int)a[(int)i]-1]++;

        // Print the counts of each index in the count array
        for (long i = 0; i < n; i++)
            System.out.println(count[(int)i]);

        // Return 0 to indicate successful completion of the program
        scanner.close();
    }
}
