
import java.util.*; // Import the Scanner class

public class Main {
  public static void main(String[] args) {
    Scanner input = new Scanner(System.in); // Create a Scanner object to read input from the standard input stream

    char B = input.next().charAt(0); // Read a character from the standard input stream and store it in variable B

    // Logic block to determine the output character based on the input character
    char OUT;
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

