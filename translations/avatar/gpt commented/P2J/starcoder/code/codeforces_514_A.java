// Get user input
Scanner sc = new Scanner(System.in);
String ip = sc.next();

// Initialize an empty string to store the transformed number
String st = "";

// Check if the input length is not equal to 1
if (ip.length()!= 1) {
    // If the first character is '9', keep it and remove it from the input
    if (ip.charAt(0) == '9') {
        st = "9"; // Start the output string with '9'
        ip = ip.substring(1); // Remove the first character from the input
    }

    // Iterate through each character in the remaining input
    for (int i = 0; i < ip.length(); i++) {
        // If the digit is greater than 4, calculate its complement to 9
        if (ip.charAt(i) > '4') {
            int n = 9 - (int)ip.charAt(i); // Calculate the complement
            st += n; // Append the complement to the output string
        } else {
            // If the digit is 4 or less, keep it unchanged
            st += ip.charAt(i); // Append the original digit to the output string
        }
    }
} else {
    // If the input length is 1, simply assign it to the output
    st = ip;
}

// Print the final transformed number as an integer
System.out.println(Integer.parseInt(st));

