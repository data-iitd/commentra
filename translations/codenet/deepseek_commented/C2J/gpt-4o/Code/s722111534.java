import java.util.Scanner;  // Import the Scanner class for input

public class Main {  // Define the Main class
    public static void main(String[] args) {  // Define the main method
        Scanner scanner = new Scanner(System.in);  // Create a Scanner object for input

        // Read the number of cells in the grid and the number of rows/columns to be painted
        int hcell = scanner.nextInt();  // Read height of cells
        int wcell = scanner.nextInt();  // Read width of cells
        int hpaint = scanner.nextInt();  // Read height to be painted
        int wpaint = scanner.nextInt();  // Read width to be painted

        // Calculate the number of black cells
        int nblack = (wcell * hpaint) + (hcell * wpaint) - (hpaint * wpaint);

        // Calculate the number of white cells
        int nwhite = (hcell * wcell) - nblack;

        // Print the number of white cells
        System.out.println(nwhite);

        scanner.close();  // Close the scanner
    }  // End of main method
}  // End of Main class
// <END-OF-CODE>
