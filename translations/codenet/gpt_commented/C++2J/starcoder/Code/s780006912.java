import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare an integer variable to hold the number of elements
        int n;
        // Declare an array to hold up to 100 integers
        int array[] = new int[100];
        
        // Read the number of elements from the user
        Scanner input = new Scanner(System.in);
        n = input.nextInt();
        
        // Input the elements into the array
        for(int i = 0; i < n; i++) {
            array[i] = input.nextInt();
        }
        
        // Initialize a variable to hold the sum of products
        int sum = 0;
        
        // Calculate the sum of products of all unique pairs of elements in the array
        for(int i = 0; i < n - 1; i++) {
            for(int j = i + 1; j < n; j++) {
                sum += array[i] * array[j]; // Add the product of the pair to the sum
            }
        }
        
        // Output the final sum of products
        System.out.println(sum);
    }
}
