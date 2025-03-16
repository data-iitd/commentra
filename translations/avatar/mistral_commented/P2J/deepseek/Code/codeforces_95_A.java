public class Main {
    public static void main(String[] args) {
        // Initialize variables
        int pya = Integer.parseInt(System.console().readLine()); // Get the number of strings to be processed
        ArrayList<String> arre = new ArrayList<>(); // Initialize an empty list to store the strings

        // Process strings input
        while (pya > 0) {
            pya--; // Decrement pya by 1
            String x = System.console().readLine().toLowerCase(); // Get the next string as a lowercase string
            arre.add(x); // Append the string to the list
        }

        // Get the original string and its first letter
        String oString = System.console().readLine(); // Get the original string
        char letter1 = System.console().readLine().toLowerCase().charAt(0); // Get the first letter of the original string in lowercase

        // Determine the second letter based on the first letter
        char letter2 = letter1 == 'a' ? 'b' : 'a'; // If the first letter is not 'a', set the second letter to 'b'

        // Initialize a list of valid indices and a set to store the indices of the strings in the original string
        int[] valid = new int[oString.length()]; // Initialize an array of zeros with the length of the original string
        Set<Integer> setcito = new HashSet<>(); // Initialize an empty set

        // Find the indices of the strings in the original string
        for (String x : arre) {
            if (oString.toLowerCase().indexOf(x) >= 0) { // If the original string contains the current string
                for (int i = oString.indexOf(x); i < oString.length(); i++) { // Iterate through the indices of the string in the original string
                    setcito.add(i); // Add the index to the set
                }
            }
        }

        // Replace the letters in the original string based on the indices of the strings
        char[] oStringArray = oString.toCharArray(); // Convert the string to a char array
        for (int i : setcito) {
            char letter = letter1; // Determine the letter to replace based on the first letter and the case of the letter at the index
            if (Character.isLowerCase(oStringArray[i]) != Character.isLowerCase(letter1)) {
                letter = letter2;
            }
            oStringArray[i] = letter; // Replace the letter with the determined letter, preserving the case
        }

        // Print the modified string
        for (char x : oStringArray) {
            System.out.print(x); // Print each character of the modified string
        }
        System.out.println(); // Print a newline after the modified string
    }
}
