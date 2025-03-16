// Import the Java utility library for string manipulation and input/output
import java.util.Scanner ;

// Define a static method named 'generateString' that returns a character array
// representing a string of numbers from 1 to 1000
public static char[] generateString() {
    StringBuilder sb = new StringBuilder(); // Create a StringBuilder object

    // Use a for loop to append numbers from 1 to 1000 to the StringBuilder object
    for (int i = 1; i <= 1000; i++) {
        sb.append(i); // Append the current number to the StringBuilder object
    }

    // Convert the StringBuilder object to a character array and return it
    return sb.toString().toCharArray();
}

// Define the main method that reads user input and prints the result
public static void main(String[] args) {
    Scanner sc = new Scanner(System.in); // Create a Scanner object to read user input

    // Read an integer value from the user input
    int n = sc.nextInt();

    // Print the character at the specified index of the generated string
    System.out.println(generateString()[n - 1]);
}
