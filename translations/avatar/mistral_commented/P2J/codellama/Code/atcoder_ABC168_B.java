
// Define the main function, taking no arguments
public static void main(String[] args) {

    // Read the integer K from the standard input
    int K = Integer.parseInt(args[0]);

    // Read a string S from the standard input
    String S = args[1];

    // Check if the length of the string S is less than or equal to K
    if (S.length() <= K) {

        // If the condition is true, return the string S
        System.out.println(S);

    } else {

        // If the condition is false, return a slice of the string S
        // from the beginning to the index K, followed by three dots '...'
        System.out.println(S.substring(0, K) + "...");

    }

}

// Define the entry point of the script
public static void main(String[] args) {

    // Call the main function and print its result
    System.out.println(main(args));

}

