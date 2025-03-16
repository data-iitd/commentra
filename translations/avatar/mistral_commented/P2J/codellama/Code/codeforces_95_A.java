// Initialize variables
int pya = Integer.parseInt(input.nextLine()); // Get the number of strings to be processed
ArrayList<String> arre = new ArrayList<String>(); // Initialize an empty list to store the strings

// Process strings input
while (pya > 0) {
    pya--; // Decrement pya by 1
    String x = input.nextLine().toLowerCase(); // Get the next string as a lowercase string
    arre.add(x); // Append the string to the list
}

// Get the original string and its first letter
String oString = input.nextLine(); // Get the original string
String letter1 = input.nextLine().toLowerCase().charAt(0); // Get the first letter of the original string in lowercase

// Determine the second letter based on the first letter
String letter2 = "a"; // Initialize the second letter to 'a'
if (letter1.toLowerCase().charAt(0) != 'a') { // If the first letter is not 'a', set the second letter to 'b'
    letter2 = "b";
}

// Initialize a list of valid indices and a set to store the indices of the strings in the original string
ArrayList<Integer> valid = new ArrayList<Integer>(oString.length()); // Initialize a list of zeros with the length of the original string
HashSet<Integer> setcito = new HashSet<Integer>(); // Initialize an empty set

// Find the indices of the strings in the original string
for (String x : arre) {
    if (oString.toLowerCase().contains(x)) { // If the original string contains the current string
        for (int i = oString.toLowerCase().indexOf(x); i < oString.length(); i++) { // Iterate through the indices of the string in the original string
            setcito.add(i); // Add the index to the set
        }
    }
}

// Replace the letters in the original string based on the indices of the strings
char[] oStringArray = oString.toCharArray(); // Convert the string to a char array
for (int i : setcito) {
    char letter = letter1.charAt(0); // Determine the letter to replace based on the first letter
    if (oStringArray[i] == oStringArray[i].toLowerCase().charAt(0)) { // If the letter at the index is lowercase
        letter = letter2.charAt(0); // Set the letter to the second letter
    }
    oStringArray[i] = letter; // Replace the letter with the determined letter
}

// Print the modified string
for (char x : oStringArray) {
    System.out.print(x); // Print each character of the modified string
}
System.out.println(); // Print a newline after the modified string

