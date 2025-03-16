

import java.util.Scanner;

public class codeforces_95_A{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int pya = scanner.nextInt();  // Read the number of inputs to be taken
        String[] arre = new String[pya];  // Initialize an array to store the inputs

        // Read pya number of inputs and convert them to lowercase, then store in arre
        for (int i = 0; i < pya; i++) {
            arre[i] = scanner.next().toLowerCase();
        }

        String oString = scanner.next();  // Read the original string
        String lowString = oString.toLowerCase();  // Convert the original string to lowercase

        // Read the first letter and determine the second letter
        char letter1 = scanner.next().toLowerCase().charAt(0);
        char letter2 = (letter1 == 'a')? 'b' : 'a';

        // Initialize a boolean array of length oString with all values set to false
        boolean[] valid = new boolean[oString.length()];

        // Iterate over each string in arre and check if it exists in lowString
        for (String x : arre) {
            int index = lowString.indexOf(x);  // Find the index of the substring
            while (index >= 0) {
                for (int i = index; i < index + x.length(); i++) {
                    valid[i] = true;  // Set the corresponding indices in valid to true
                }
                index = lowString.indexOf(x, index + 1);  // Find the next index of the substring
            }
        }

        // Convert oString to a character array for easy manipulation
        char[] oStringArray = oString.toCharArray();

        // Update the characters in oString based on the valid indices and letter rules
        for (int i = 0; i < oString.length(); i++) {
            if (valid[i]) {
                char letter = (lowString.charAt(i) == letter1)? letter2 : letter1;
                oStringArray[i] = Character.isUpperCase(oString.charAt(i))? Character.toUpperCase(letter) : letter;
            }
        }

        // Print the modified oString
        System.out.println(new String(oStringArray));
    }
}

Translate the above Java code to C++ and end with comment "