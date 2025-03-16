import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String[] input = scanner.nextLine().split(" ");  // Take input from user and split it into a string array
        int[] a = new int[input.length];  // Create an integer array of the same length

        // Convert the string array to an integer array
        for (int j = 0; j < input.length; j++) {
            a[j] = Integer.parseInt(input[j]);
        }

        // Iterate over the array, checking each element
        for (int e = 0; e < a.length; e++) {
            if (a[e] == 0) {  // If an element is 0
                System.out.println(e + 1);  // Print the position (1-indexed) of that element and break the loop
                break;
            }
        }
        
        scanner.close();  // Close the scanner
    }
}
// <END-OF-CODE>
