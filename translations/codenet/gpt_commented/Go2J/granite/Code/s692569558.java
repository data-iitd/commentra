
import java.util.Scanner; // Importing Scanner for input reading

public class s692569558{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read the first line of input (not used)
        scanner.nextLine();
        // Read the second line of input which contains space-separated integers
        String ds = scanner.nextLine();

        // Split the input string into an array of strings
        String[] dd = ds.split(" ");
        // Create an array of integers to hold the converted values
        int[] dn = new int[dd.length];

        // Convert each string in the array to an integer
        for (int i = 0; i < dd.length; i++) {
            dn[i] = Integer.parseInt(dd[i]);
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
