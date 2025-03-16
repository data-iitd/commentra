// Initialize variables
int pya = Integer.parseInt(sc.nextLine()); // Get the number of strings to be processed
List<String> arre = new ArrayList<>(); // Initialize an empty list to store the strings

// Process strings input
while (pya > 0) {
    pya--; // Decrement pya by 1
    String x = sc.nextLine().toLowerCase(); // Get the next string as a lowercase string
    arre.add(x); // Append the string to the list
}

// Get the original string and its first letter
String oString = sc.nextLine(); // Get the original string
String letter1 = sc.nextLine().toLowerCase().charAt(0); // Get the first letter of the original string in lowercase

// Determine the second letter based on the first letter
String letter2 = "a" + (letter1.toLowerCase().equals("a")? "b" : ""); // If the first letter is not 'a', set the second letter to 'b'

// Initialize a list of valid indices and a set to store the indices of the strings in the original string
List<Integer> valid = new ArrayList<>(); // Initialize a list of zeros with the length of the original string
Set<Integer> setcito = new HashSet<>(); // Initialize an empty set

// Find the indices of the strings in the original string
for (String x : arre) {
    if (oString.toLowerCase().contains(x)) { // If the original string contains the current string
        for (int i = oString.indexOf(x); i < oString.length(); i++) { // Iterate through the indices of the string in the original string
            setcito.add(i); // Add the index to the set
        }
    }
}

// Replace the letters in the original string based on the indices of the strings
char[] oStringc = oString.toCharArray(); // Convert the string to a list
for (int i : setcito) {
    char letter = letter1.toLowerCase().equals(oStringc[i])? letter1.toLowerCase().equals("a")? 'b' : 'B' : letter2.toLowerCase().equals("a")? 'b' : 'B'; // Determine the letter to replace based on the first letter and the case of the letter at the index
    oStringc[i] = letter; // Replace the letter with the determined letter, preserving the case
}

// Print the modified string
for (char x : oStringc) {
    System.out.print(x); // Print each character of the modified string
}
System.out.println(); // Print a newline after the modified string

