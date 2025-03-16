// Import the Scanner class
import java.util.Scanner;

// Create a new Scanner object
Scanner scanner = new Scanner(System.in);

// Read the input from the standard input
String a = scanner.nextLine();

// Check if the string contains any '1' character
if (a.indexOf('1') == -1) {
    // If it doesn't, print 0 and exit the program
    System.out.println(0);
    System.exit(0);
}

// If the string contains at least one '1' character, we proceed to calculate the product of the number of zeros in each segment between consecutive '1' characters
int productOfZeros = 1;
for (String segment : a.replaceAll("^0+", "").replaceAll("1+", "1").split("1")) {
    productOfZeros *= Integer.parseInt(segment.replaceAll("[^0]", "")) + 1;
}

// Finally, print the result
System.out.println(productOfZeros);

