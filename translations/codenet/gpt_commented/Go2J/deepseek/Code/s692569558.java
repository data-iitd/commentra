import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read the first line of input (not used)
        scanner.nextLine();
        // Read the second line of input which contains space-separated integers
        String input = scanner.nextLine();

        // Split the input string into an array of strings
        String[] ds = input.split(" ");
        // Create an array of integers to hold the converted values
        int[] dn = new int[ds.length];

        // Convert each string in the array to an integer
        for (int i = 0; i < ds.length; i++) {
            dn[i] = Integer.parseInt(ds[i]); // No need to handle error for simplicity
        }

        // Initialize a variable to hold the sum of products
        int sum = 0;
        // Calculate the sum of products of all unique pairs of integers
        for (int i = 0; i < dn.length; i++) {
            for (int j = i + 1; j < dn.length; j++) {
                sum += dn[i] * dn[j]; // Multiply the pair and add to sum
            }
        }

        // Output the final sum of products
        System.out.println(sum);
    }
}
