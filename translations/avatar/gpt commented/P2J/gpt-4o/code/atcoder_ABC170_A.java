import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read a line of input, split it into components, and convert each component to an integer
        String[] input = scanner.nextLine().split(" ");
        int[] a = new int[input.length];
        for (int j = 0; j < input.length; j++) {
            a[j] = Integer.parseInt(input[j]);
        }

        // Iterate over the array 'a' using a for loop to get both the index (e) and the value (i)
        for (int e = 0; e < a.length; e++) {
            // Check if the current value is zero
            if (a[e] == 0) {
                // Print the index (1-based) of the first occurrence of zero
                System.out.println(e + 1);
                // Exit the loop after finding the first zero
                break;
            }
        }
        
        scanner.close();
    }
}
// <END-OF-CODE>
