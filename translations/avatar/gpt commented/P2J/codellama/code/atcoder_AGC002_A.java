
// Import necessary libraries
import java.util.Scanner;

// Function to read a line from standard input and remove trailing whitespace
public static String S() {
    Scanner sc = new Scanner(System.in);
    return sc.nextLine().trim();
}

// Function to read an integer from standard input
public static int I() {
    Scanner sc = new Scanner(System.in);
    return sc.nextInt();
}

// Function to read a list of integers from standard input
public static List<Integer> LI() {
    Scanner sc = new Scanner(System.in);
    List<Integer> list = new ArrayList<>();
    while (sc.hasNextInt()) {
        list.add(sc.nextInt());
    }
    return list;
}

// Function to read a list of strings from standard input
public static List<String> LS() {
    Scanner sc = new Scanner(System.in);
    List<String> list = new ArrayList<>();
    while (sc.hasNext()) {
        list.add(sc.next());
    }
    return list;
}

// Read two integers from input
int a = I();
int b = I();

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
}

