import java.util.Scanner; // Importing the Scanner class for user input

public class Main { // Defining the Main class
    public String encrypt(final String message, final String key) { // Defining the encrypt method that takes a message and a key as arguments
        if (key.isEmpty()) { // Checking if the key is empty
            throw new IllegalArgumentException("Key cannot be empty."); // Throwing an exception if the key is empty
        }
        StringBuilder result = new StringBuilder(); // Creating an empty StringBuilder to store the encrypted message
        int j = 0; // Initializing a variable j to keep track of the key index
        for (int i = 0; i < message.length(); i++) { // Iterating through each character in the message
            char c = message.charAt(i); // Storing the current character in the message
            if (Character.isLetter(c)) { // Checking if the current character is a letter
                if (Character.isUpperCase(c)) { // Checking if the current character is an uppercase letter
                    result.append((char) ((c + key.toUpperCase().charAt(j) - 2 * 'A') % 26 + 'A')); // Encrypting uppercase letters
                    j = ++j % key.length(); // Incrementing j and making it wrap around the key length
                } else { // If the current character is a lowercase letter
                    result.append((char) ((c + key.toLowerCase().charAt(j) - 2 * 'a') % 26 + 'a')); // Encrypting lowercase letters
                    j = ++j % key.length(); // Incrementing j and making it wrap around the key length
                }
            } else { // If the current character is not a letter
                result.append(c); // Adding the character to the result as it is
            }
        }
        return result.toString(); // Returning the encrypted message as a String
    }
    public String decrypt(final String message, final String key) { // Defining the decrypt method that takes a message and a key as arguments
        if (key.isEmpty()) { // Checking if the key is empty
            throw new IllegalArgumentException("Key cannot be empty."); // Throwing an exception if the key is empty
        }
        StringBuilder result = new StringBuilder(); // Creating an empty StringBuilder to store the decrypted message
        int j = 0; // Initializing a variable j to keep track of the key index
        for (int i = 0; i < message.length(); i++) { // Iterating through each character in the message
            char c = message.charAt(i); // Storing the current character in the message
            if (Character.isLetter(c)) { // Checking if the current character is a letter
                if (Character.isUpperCase(c)) { // Checking if the current character is an uppercase letter
                    result.append((char) ('Z' - (25 - (c - key.toUpperCase().charAt(j))) % 26)); // Decrypting uppercase letters
                    j = ++j % key.length(); // Incrementing j and making it wrap around the key length
                } else { // If the current character is a lowercase letter
                    result.append((char) ('z' - (25 - (c - key.toLowerCase().charAt(j))) % 26)); // Decrypting lowercase letters
                    j = ++j % key.length(); // Incrementing j and making it wrap around the key length
                }
            } else { // If the current character is not a letter
                result.append(c); // Adding the character to the result as it is
            }
        }
        return result.toString(); // Returning the decrypted message as a String
    }
    public static void main(String[] args) { // Defining the main method
        Scanner scanner = new Scanner(System.in); // Creating a new Scanner object for user input
        String operation = scanner.nextLine().toLowerCase(); // Reading the user's operation ('encrypt' or 'decrypt') and converting it to lowercase
        String key = scanner.nextLine(); // Reading the user's key
        if (operation.equals("encrypt")) { // Checking if the user wants to encrypt a message
            String plaintext = scanner.nextLine(); // Reading the user's plaintext message
            Main cipher = new Main(); // Creating a new instance of the Main class
            String encrypted = cipher.encrypt(plaintext, key); // Encrypting the plaintext message using the given key
            System.out.println("Encrypted Message: " + encrypted); // Printing the encrypted message to the console
        } else if (operation.equals("decrypt")) { // Checking if the user wants to decrypt a message
            String ciphertext = scanner.nextLine(); // Reading the user's ciphertext message
            Main cipher = new Main(); // Creating a new instance of the Main class
            String decrypted = cipher.decrypt(ciphertext, key); // Decrypting the ciphertext message using the given key
            System.out.println("Decrypted Message: " + decrypted); // Printing the decrypted message to the console
        } else { // If the user entered an invalid operation
            System.out.println("Invalid operation. Please choose 'encrypt' or 'decrypt'."); // Printing an error message to the console
        }
        scanner.close(); // Closing the Scanner object
    }
}
