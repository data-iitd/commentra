
// Main function starts here
public static void main(String[] args) {
    // Declare and initialize variables
    String N = ""; // string to store the input number
    int S = 0; // sum of digits of the number

    // Read the input number from the standard input
    System.out.print("Enter a number: ");
    N = System.console().readLine();

    // Calculate the sum of digits of the number
    for (int i = 0; i < N.length(); i++) {
        // Increment the sum by the ASCII value of the current digit
        // (subtracting the ASCII value of '0' to get the actual digit value)
        S += N.charAt(i) - '0';
    }

    // Check if the number is divisible by the sum of its digits
    if (Integer.parseInt(N) % S == 0) { // Convert the string to an integer using Integer.parseInt()
        System.out.println("Yes"); // Output "Yes" if the number is divisible
    } else {
        System.out.println("No"); // Output "No" otherwise
    }

    // Terminate the program with an exit status of 0
    System.exit(0);
}

