
import java.util.Scanner; // Import the Scanner class for input operations

public class Main { // Start of the Main class
  public static void main(String[] args) { // Start of the main function
    Scanner sc = new Scanner(System.in); // Create a new Scanner object to read input from the standard input stream
    char B = sc.next().charAt(0); // Read a character from the standard input stream and store it in variable B
    char OUT; // Declare a character variable named OUT to store the output character

    // Logic block to determine the output character based on the input character
    if(B == 'A'){ // If the input character is 'A'
      OUT = 'T'; // Set the output character to 'T'
    }
    else if(B == 'T'){ // If the input character is 'T'
      OUT = 'A'; // Set the output character to 'A'
    }
    else if(B == 'C'){ // If the input character is 'C'
      OUT = 'G'; // Set the output character to 'G'
    }
    else{ // If the input character is neither 'A', 'T', nor 'C'
      OUT = 'C'; // Set the output character to the input character itself
    }

    System.out.println(OUT); // Output the result character to the standard output stream
  }
}
