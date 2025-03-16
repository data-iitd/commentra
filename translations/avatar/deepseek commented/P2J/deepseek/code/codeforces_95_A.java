import java.util.ArrayList;
import java.util.HashSet;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int pya = scanner.nextInt();  // Read the number of inputs to be taken
        ArrayList<String> arre = new ArrayList<>();  // Initialize an empty list to store the inputs

        // Read pya number of inputs and convert them to lowercase, then append to arre
        while (pya > 0) {
            pya--;  // Decrement pya by 1 in each iteration
            arre.add(scanner.next().toLowerCase());
        }

        String oString = scanner.next().toLowerCase();  // Read the original string

        // Read the first letter and determine the second letter
        char letter1 = scanner.next().toLowerCase().charAt(0);
        char letter2 = letter1 == 'a' ? 'b' : 'a';

        // Initialize a list of zeros with the length of oString
        int[] valid = new int[oString.length()];
        HashSet<Integer> setcito = new HashSet<>();  // Initialize an empty set to store indices

        // Iterate over each string in arre and check if it exists in lowString
        for (String x : arre) {
            String lowString = oString.toLowerCase();
            int wat = 0;
            while (true) {
                int index = lowString.indexOf(x, wat);  // Find the index of the substring
                if (index < 0) {
                    break;
                }
                for (int i = index; i < index + x.length(); i++) {
                    setcito.add(i);  // Add the indices to the set
                }
                wat = index + 1;
            }
        }

        // Convert oString to a list for easy manipulation
        char[] oStringArray = oString.toCharArray();

        // Update the characters in oString based on the setcito indices and letter rules
        for (int i : setcito) {
            char letter = letter1 == oStringArray[i] ? letter2 : letter1;
            oStringArray[i] = Character.isLowerCase(oStringArray[i]) ? letter : Character.toUpperCase(letter);
        }

        // Print the modified oString
        for (char x : oStringArray) {
            System.out.print(x);
        }
        System.out.println();
    }
}
