
// Take a string input from the user
String s = sc.nextLine();

// Initialize an empty string to store the result
String result = "";

// Initialize a variable 'i' to traverse the string 's'
int i = 0;

// Use a while loop to traverse the string 's' until the end
while (i < s.length()) {

    // Check if the current character is a '.'
    if (s.charAt(i) == '.') {

        // If yes, append '0' to the result string
        result += '0';

    }

    // Move to the next character if it's not a '.'
    else {

        // Increment the index 'i' to move to the next character
        i++;

        // Check if the next character is also a '.'
        if (s.charAt(i) == '.') {

            // If yes, append '1' to the result string
            result += '1';

        }

        // If not, append '2' to the result string
        else {
            result += '2';
        }
    }

    // Increment the index 'i' to move to the next character
    i++;
}

// Print the final result string
System.out.println(result);

