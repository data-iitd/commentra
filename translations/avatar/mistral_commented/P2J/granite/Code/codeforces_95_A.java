
// Initialize variables
Scanner sc = new Scanner(System.in); // Create a Scanner object to read input
int pya = sc.nextInt(); // Get the number of strings to be processed
String[] arre = new String[pya]; // Initialize an array of strings to store the strings

// Process strings input
for (int i = 0; i < pya; i++) {
    arre[i] = sc.next().toLowerCase(); // Get the next string as a lowercase string and store it in the array
}

// Get the original string and its first letter
String oString = sc.next(); // Get the original string
char letter1 = oString.toLowerCase().charAt(0); // Get the first letter of the original string in lowercase

// Determine the second letter based on the first letter
char letter2 = 'a'; // Set the second letter to 'a'
if (letter1!= 'a') {
    letter2 = 'b'; // If the first letter is not 'a', set the second letter to 'b'
}

// Initialize a list of valid indices and a set to store the indices of the strings in the original string
List<Integer> valid = new ArrayList<>(); // Initialize an empty list of integers
Set<Integer> setcito = new HashSet<>(); // Initialize an empty set of integers

// Find the indices of the strings in the original string
for (String x : arre) {
    int index = oString.toLowerCase().indexOf(x); // Get the index of the current string in the original string, ignoring case
    while (index >= 0) { // While the index is valid
        valid.add(index); // Add the index to the list
        index = oString.toLowerCase().indexOf(x, index + 1); // Find the next index of the current string in the original string, ignoring case
    }
}

// Replace the letters in the original string based on the indices of the strings
char[] oStringArray = oString.toCharArray(); // Convert the string to a character array
for (int i : valid) {
    char letter = letter1; // Set the letter to replace based on the first letter
    if (Character.isLowerCase(oStringArray[i])) {
        letter = (letter == 'a' || letter == 'A')? 'b' : 'a'; // If the letter at the index is lowercase and the first letter is 'a' or 'A', set the letter to 'b'
    } else {
        letter = Character.toUpperCase(letter); // If the letter at the index is uppercase, convert the letter to uppercase
    }
    oStringArray[i] = letter; // Replace the letter with the determined letter
}

// Print the modified string
System.out.println(String.valueOf(oStringArray)); // Print the modified string

