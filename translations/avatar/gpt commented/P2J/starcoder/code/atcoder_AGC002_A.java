
// Import necessary libraries
import java.util.*;

// Function to read a line from standard input and remove trailing whitespace
public static String S() {
    return new Scanner(System.in).nextLine().trim();
}

// Function to read an integer from standard input
public static int I() {
    return Integer.parseInt(S());
}

// Function to read a list of integers from standard input
public static List<Integer> LI() {
    return Arrays.stream(S().split(" ")).map(Integer::parseInt).collect(Collectors.toList());
}

// Function to read a list of strings from standard input
public static List<String> LS() {
    return Arrays.asList(S().split(" "));
}

// Read two integers from input
int a = LI().get(0);
int b = LI().get(1);

// Check if the first integer 'a' is positive
if (a > 0) {
    System.out.println("Positive");  // Output 'Positive' if 'a' is greater than 0
} else if (a <= 0 && b >= 0) {
    System.out.println("Zero");  // Output 'Zero' if 'a' is non-positive and 'b' is non-negative
} else {
    // If 'a' is negative and 'b' is also negative
    if ((a + b) % 2 == 0) {
        System.out.println("Negative");  // Output 'Negative' if the sum of 'a' and 'b' is even
    } else {
        System.out.println("Positive");  // Output 'Positive' if the sum of 'a' and 'b' is odd
}

