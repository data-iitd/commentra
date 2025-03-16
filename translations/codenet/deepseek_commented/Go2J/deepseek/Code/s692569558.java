import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the first line of input (which we will ignore)
        scanner.nextLine();
        
        // Read the second line of input
        String ds = scanner.nextLine();
        
        // Split the input string into a array of strings
        String[] dd = ds.split(" ");
        
        // Create an array of integers to hold the converted values
        int[] dn = new int[dd.length];
        
        // Convert each string in the array to an integer
        for (int i = 0; i < dd.length; i++) {
            dn[i] = Integer.parseInt(dd[i]);
        }
        
        // Initialize the sum variable to hold the result
        int sum = 0;
        
        // Calculate the sum of the products of all pairs of integers in the array
        for (int i = 0; i < dn.length; i++) {
            for (int j = i + 1; j < dn.length; j++) {
                sum += dn[i] * dn[j];
            }
        }
        
        // Print the result
        System.out.println(sum);
    }
}
