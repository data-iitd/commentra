import java.util.Scanner; // Importing the Scanner class for user input

public class Main {
    public static void main(String[] args) {
        // Creating a Scanner object to read input from the user
        Scanner in = new Scanner(System.in);
        
        // Prompting the user to enter a word
        String word = in.next();
        
        // Initializing counters for uppercase and lowercase letters
        int uppercase = 0;
        int lowercase = 0;
        
        // Looping through each character in the input word
        for (int i = 0; i < word.length(); i++) {
            char ch = word.charAt(i); // Getting the character at the current index
            
            // Checking if the character is uppercase
            if (Character.isUpperCase(ch)) {
                uppercase++; // Incrementing the uppercase counter
            } else {
                lowercase++; // Incrementing the lowercase counter
            }
        }
        
        // Comparing the counts of uppercase and lowercase letters
        if (uppercase > lowercase) {
            // If there are more uppercase letters, print the word in uppercase
            System.out.println(word.toUpperCase());
        } else if (lowercase > uppercase) {
            // If there are more lowercase letters, print the word in lowercase
            System.out.println(word.toLowerCase());
        } else {
            // If the counts are equal, print the word in lowercase
            System.out.println(word.toLowerCase());
        }
    }
}

