// Get input from the user
String txt = sc.next();

// Initialize counters for uppercase and lowercase letters
int cu = 0;  // Counter for uppercase letters
int cl = 0;  // Counter for lowercase letters

// Iterate through each character in the input text
for (char z : txt.toCharArray()) {
    // Check if the character is lowercase
    if (Character.isLowerCase(z)) {
        cl++;  // Increment lowercase counter
    } else {
        cu++;  // Increment uppercase counter
    }
}

// Compare the counts of uppercase and lowercase letters
if (cu > cl) {
    // If there are more uppercase letters, convert the text to uppercase
    String out = txt.toUpperCase();
} else {
    // If there are more lowercase letters or they are equal, convert the text to lowercase
    String out = txt.toLowerCase();
}

// Print the resulting output
System.out.println(out);

