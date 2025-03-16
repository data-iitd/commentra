// Get the text input from the user
String txt = scanner.nextLine();

// Initialize the count of uppercase and lowercase characters
int cu = 0;
int cl = 0;

// Iterate through each character in the text input
for (char z : txt.toCharArray()) {
    // If the character is lowercase, increment the lowercase count
    if (Character.isLowerCase(z)) {
        cl++;
    }
    // If the character is uppercase, increment the uppercase count
    else {
        cu++;
    }
}

// Determine the output based on the count of uppercase and lowercase characters
String out;
if (cu > cl) {
    // If there are more uppercase characters than lowercase characters, convert the entire text to uppercase
    out = txt.toUpperCase();
}
else {
    // If there are more lowercase characters than uppercase characters, convert the entire text to lowercase
    out = txt.toLowerCase();
}

// Print the output
System.out.println(out);

