// Read an integer input which represents the number of strings to be added to the list
int pya = Integer.parseInt(sc.nextLine());

// Initialize an empty list to store the input strings
List<String> arre = new ArrayList<>();

// Loop to collect 'pya' number of strings from user input
while (pya > 0) {
    pya--; // Decrement the counter
    // Append the lowercase version of the input string to the list
    arre.add(sc.nextLine().toLowerCase());
}

// Read the original string from user input
String oString = sc.nextLine();

// Convert the original string to lowercase for comparison
String lowString = oString.toLowerCase();

// Read a letter from user input and convert it to lowercase
String letter1 = sc.nextLine().toLowerCase();

// Determine the second letter based on the first letter; if it's 'a', use 'b', otherwise use 'a'
String letter2 = letter1.equals("a")? "b" : "a";

// Initialize a list to track valid indices for replacement
List<Integer> valid = new ArrayList<>();

// Create a set to store unique indices where replacements will occur
Set<Integer> setcito = new HashSet<>();

// Loop through each string in the list 'arre'
for (String x : arre) {
    // Check if the current string 'x' is found in the lowercase version of the original string
    if (lowString.contains(x)) {
        int wat = 0; // Initialize a variable to track the search position
        while (true) {
            // Find the index of the current string 'x' starting from position 'wat'
            int index = lowString.indexOf(x, wat);
            if (index < 0) {
                break; // Exit the loop if no more occurrences are found
            }
            // Add the indices of the found string to the set for replacement
            for (int i = index; i < index + x.length(); i++) {
                setcito.add(i);
            }
            wat = index + 1; // Move the search position forward
        }
    }
}

// Convert the original string to a list for mutable operations
List<Character> oString = new ArrayList<>();
for (char c : oString.toCharArray()) {
    oString.add(c);
}

// Loop through the indices stored in'setcito' for replacement
for (int i : setcito) {
    // Determine which letter to use for replacement based on the original character
    char letter = letter1.equals(lowString.charAt(i))? letter1.charAt(0) : letter2.charAt(0);
    // Replace the character in the original string with the chosen letter, maintaining case
    oString.set(i, Character.isLowerCase(oString.get(i))? letter : Character.toUpperCase(letter));
}

// Print the modified string without spaces between characters
for (char c : oString) {
    System.out.print(c);
}

// Print a newline at the end
System.out.println();

