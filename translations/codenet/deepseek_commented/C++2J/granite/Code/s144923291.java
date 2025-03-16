
import java.util.*; // Import the Scanner class for input
import java.io.*; // Import the PrintWriter class for output

public class s144923291{ // Define the main class
 public static void main(String[] args) { // Define the main method
  Scanner sc = new Scanner(System.in); // Create a Scanner object for input
  PrintWriter out = new PrintWriter(System.out); // Create a PrintWriter object for output
  int h = sc.nextInt(); // Read the number of rows
  int w = sc.nextInt(); // Read the number of columns
  char[][] t = new char[h][w]; // Create a 2D character array to store the input
  for(int i = 0; i < h; i++) { // Loop over each row
   String s = sc.next(); // Read a string
   for(int j = 0; j < w; j++) { // Loop over each column
    t[i][j] = s.charAt(j); // Store the character in the 2D array
   }
  }
  String s = "snuke"; // Define the pattern to search for
  for(int i = 0; i < h; i++) { // Loop over each row
   for(int j = 0; j < w; j++) { // Loop over each column
    if(t[i][j] == s.charAt(0) && t[i][j+1] == s.charAt(1) && t[i][j+2] == s.charAt(2) && t[i+1][j+1] == s.charAt(3)) { // Check if the pattern is found
     char c = (char)('A' + j); // Calculate the column letter
     out.println(c + (i+1)); // Output the position in the grid
     out.flush(); // Flush the output buffer
     return; // Terminate the program
    }
   }
  }
 }
} // End of the main class

