import java.util.Scanner; // Import the Scanner class for user input

public class Main { // Define the main class
    public static void main(String[] args) { // The main method is the starting point of the program
        Scanner scanner = new Scanner(System.in); // Create a Scanner object for input

        int hcell, wcell, hpaint, wpaint, nblack, nwhite; // Declare variables

        // Read the height and width of the grid from the user
        hcell = scanner.nextInt(); 
        wcell = scanner.nextInt(); 

        // Read the number of rows and columns to be painted with black and white respectively
        hpaint = scanner.nextInt(); 
        wpaint = scanner.nextInt(); 

        // Calculate the number of black painted cells
        nblack = (wcell * hpaint) + (hcell * wpaint) - (hpaint * wpaint); 

        // Calculate the number of white unpainted cells
        nwhite = (hcell * wcell) - nblack; 

        // Print the number of white unpainted cells to the console
        System.out.println(nwhite); 

        scanner.close(); // Close the scanner
    } // End of main method
} // End of class
// <END-OF-CODE>
