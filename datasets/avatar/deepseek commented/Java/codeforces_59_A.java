import java.util.Scanner; // Importing the Scanner class for input operations

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in); // Creating a Scanner object to read input
        String word = in.next(); // Reading a single word from the user input
        
        int uppercase = 0; // Initializing the counter for uppercase letters
        int lowercase = 0; // Initializing the counter for lowercase letters
        
        // Looping through each character in the input word
        for (int i = 0; i < word.length(); i++) {
            char ch = word.charAt(i); // Getting the character at the current position
            if (Character.isUpperCase(ch)) { // Checking if the character is uppercase
                uppercase++; // Incrementing the uppercase counter
            } else {
                lowercase++; // Incrementing the lowercase counter
            }
        }
        
        // Comparing the counts of uppercase and lowercase letters and printing the result accordingly
        if (uppercase > lowercase) {
            System.out.println(word.toUpperCase()); // Printing the word in uppercase if there are more uppercase letters
        } else if (lowercase > uppercase) {
            System.out.println(word.toLowerCase()); // Printing the word in lowercase if there are more lowercase letters
        } else {
            System.out.println(word.toLowerCase()); // Printing the word in lowercase if the counts are equal
        }
    }
}
