import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        // Declare an array to hold up to 10,000 integers
        int[] a = new int[10000];
        // Initialize a variable to hold the sum of the integers
        long sum = 0;

        // Read the number of integers to be processed
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();

        // Read n integers from input and calculate their sum
        for(int i = 0; i < n; i++){
            a[i] = in.nextInt(); // Read each integer into the array
            sum += a[i];        // Add the integer to the sum
        }

        // Initialize min and max with the first element of the array
        int min = a[0];
        int max = a[0];

        // Iterate through the array to find the minimum and maximum values
        for(int i = 1; i < n; i++){
            if(a[i] > max) max = a[i]; // Update max if the current element is greater
            if(a[i] < min) min = a[i]; // Update min if the current element is smaller
        }

        // Print the minimum, maximum, and sum of the integers
        System.out.printf("%d %d %d\n", min, max, sum);
    }
}
