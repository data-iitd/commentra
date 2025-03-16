import java.util.*;

public class StringProcessor {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Initialize variables
        int pya = Integer.parseInt(scanner.nextLine()); // Get the number of strings to be processed
        List<String> arre = new ArrayList<>(); // Initialize an empty list to store the strings

        // Process strings input
        while (pya > 0) {
            pya--; // Decrement pya by 1
            String x = scanner.nextLine().toLowerCase(); // Get the next string as a lowercase string
            arre.add(x); // Append the string to the list
        }

        // Get the original string and its first letter
        String oString = scanner.nextLine(); // Get the original string
        char letter1 = scanner.nextLine().toLowerCase().charAt(0); // Get the first letter of the original string in lowercase

        // Determine the second letter based on the first letter
        char letter2 = (letter1 != 'a') ? 'a' : 'b'; // If the first letter is not 'a', set the second letter to 'b'

        // Initialize a list of valid indices and a set to store the indices of the strings in the original string
        boolean[] valid = new boolean[oString.length()]; // Initialize a boolean array with the length of the original string
        Set<Integer> setcito = new HashSet<>(); // Initialize an empty set

        // Find the indices of the strings in the original string
        for (String x : arre) {
            int index = oString.toLowerCase().indexOf(x); // Find the index of the current string
            while (index >= 0) { // While the string is found
                for (int i = index; i < index + x.length(); i++) {
                    setcito.add(i); // Add the index to the set
                }
                index = oString.toLowerCase().indexOf(x, index + 1); // Find the next occurrence
            }
        }

        // Replace the letters in the original string based on the indices of the strings
        StringBuilder modifiedString = new StringBuilder(oString); // Use StringBuilder for mutable string
        for (int i : setcito) {
            char letter = (Character.isLowerCase(oString.charAt(i)) != Character.isLowerCase(letter1)) ? letter1 : letter2; // Determine the letter to replace
            modifiedString.setCharAt(i, Character.isLowerCase(oString.charAt(i)) ? letter : Character.toUpperCase(letter)); // Replace the letter with the determined letter, preserving the case
        }

        // Print the modified string
        System.out.print(modifiedString.toString()); // Print the modified string
        System.out.println(); // Print a newline after the modified string
    }
}
// <END-OF-CODE>
