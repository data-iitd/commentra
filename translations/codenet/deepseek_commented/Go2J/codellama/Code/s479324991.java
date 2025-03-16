
import java.util.Scanner;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Read the number of elements
        int n = sc.nextInt();
        
        // Initialize an array to hold the float values
        float[] arr = new float[n];
        
        // Read each integer and convert it to float, then store in the array
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }
        
        // Sort the array of float values
        Arrays.sort(arr);
        
        // Initialize a variable to keep track of the running average
        float prev = arr[0];
        
        // Iterate through the sorted array to calculate the average
        for (int i = 1; i < arr.length; i++) {
            prev = (prev + arr[i]) / 2;
        }

        // Print the final average
        System.out.println(prev);
    }
}

