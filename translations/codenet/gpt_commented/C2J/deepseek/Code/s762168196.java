public class MinMaxSum {
    public static void main(String[] args) {
        // Declare an array to hold up to 10,000 integers
        int[] a = new int[10000];
        int min, max, n, i;
        // Initialize a variable to hold the sum of the integers
        long sum = 0;

        // Read the number of integers to be processed
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        n = scanner.nextInt();

        // Read n integers from input and calculate their sum
        for(i = 0; i < n; i++){
            a[i] = scanner.nextInt(); // Read each integer into the array
            sum += a[i];        // Add the integer to the sum
        }

        // Initialize min and max with the first element of the array
        min = max = a[0];

        // Iterate through the array to find the minimum and maximum values
        for(i = 1; i < n; i++){
            if(a[i] > max) max = a[i]; // Update max if the current element is greater
            if(a[i] < min) min = a[i]; // Update min if the current element is smaller
        }

        // Print the minimum, maximum, and sum of the integers
        System.out.println(min + " " + max + " " + sum);
    }
}
