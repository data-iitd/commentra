import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read the first two lines from standard input and store them in the scanner
        scanner.nextLine();
        scanner.nextLine();

        // Read the second line from standard input and store it in the variable ds
        String ds = scanner.nextLine();

        // Split the string ds into an array of strings dd using the String.split function
        String[] dd = ds.split(" ");

        // Create an array dn of length dd.length and initialize each element to 0
        int[] dn = new int[dd.length];

        // Iterate through each element i in the array dd and convert its string value to integer using Integer.parseInt function and store it in the corresponding index of array dn
        for (int i = 0; i < dd.length; i++) {
            dn[i] = Integer.parseInt(dd[i]);
        }

        // Initialize sum variable to 0
        int sum = 0;

        // Iterate through each index i in the array dn
        for (int i = 0; i < dn.length; i++) {
            // Iterate through each index j greater than i in the array dn
            for (int j = i + 1; j < dn.length; j++) {
                // Add the product of dn[i] and dn[j] to the sum variable
                sum += dn[i] * dn[j];
            }
        }

        // Print the value of sum variable to the standard output using System.out.println function
        System.out.println(sum);

        // End of code
    }
}
