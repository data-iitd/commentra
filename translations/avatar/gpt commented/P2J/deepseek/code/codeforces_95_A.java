import java.util.ArrayList;
import java.util.HashSet;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read an integer input which represents the number of strings to be added to the list
        int pya = Integer.parseInt(scanner.nextLine());
        
        // Initialize an empty list to store the input strings
        ArrayList<String> arre = new ArrayList<>();
        
        // Loop to collect 'pya' number of strings from user input
        while (pya > 0) {
            pya--;  // Decrement the counter
            // Append the lowercase version of the input string to the list
            arre.add(scanner.nextLine().toLowerCase());
        }
        
        // Read the original string from user input
        String oString = scanner.nextLine();
        
        // Convert the original string to lowercase for comparison
        String lowString = oString.toLowerCase();
        
        // Read a letter from user input and convert it to lowercase
        char letter1 = scanner.nextLine().toLowerCase().charAt(0);
        
        // Determine the second letter based on the first letter; if it's 'a', use 'b', otherwise use 'a'
        char letter2 = letter1 == 'a' ? 'b' : 'a';
        
        // Initialize a list to track valid indices for replacement
        boolean[] valid = new boolean[oString.length()];
        
        // Create a set to store unique indices where replacements will occur
        HashSet<Integer> setcito = new HashSet<>();
        
        // Loop through each string in the list 'arre'
        for (String x : arre) {
            // Check if the current string 'x' is found in the lowercase version of the original string
            int wat = 0;  // Initialize a variable to track the search position
            while (true) {
                // Find the index of the current string 'x' starting from position 'wat'
                int index = lowString.indexOf(x, wat);
                if (index < 0) {
                    break;  // Exit the loop if no more occurrences are found
                }
                // Add the indices of the found string to the set for replacement
                for (int i = index; i < index + x.length(); i++) {
                    setcito.add(i);
                }
                wat = index + 1;  // Move the search position forward
            }
        }
        
        // Convert the original string to a character array for mutable operations
        char[] oStringArray = oString.toCharArray();
        
        // Loop through the indices stored in 'setcito' for replacement
        for (int i : setcito) {
            // Determine which letter to use for replacement based on the original character
            char letter = letter1 == lowString.charAt(i) ? letter2 : letter1;
            // Replace the character in the original string with the chosen letter, maintaining case
            oStringArray[i] = letter;
        }
        
        // Print the modified string without spaces between characters
        for (char x : oStringArray) {
            System.out.print(x);
        }
        
        // Print a newline at the end
        System.out.println();
    }
}
