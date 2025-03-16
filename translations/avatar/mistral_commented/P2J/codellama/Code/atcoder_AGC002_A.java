
// Import some built-in Java classes that we may need later
import java.util.Scanner;
import java.util.ArrayList;
import java.util.Arrays;

// Define two helper functions to read input from the standard input stream
public static String S( ) {
    Scanner sc = new Scanner(System.in);
    return sc.nextLine().trim();
}

public static int I( ) {
    Scanner sc = new Scanner(System.in);
    return sc.nextInt();
}

// Define another helper function to read a list of integers from the standard input stream
public static ArrayList<Integer> LI( ) {
    Scanner sc = new Scanner(System.in);
    String[] s = sc.nextLine().trim().split(" ");
    ArrayList<Integer> list = new ArrayList<Integer>();
    for (int i = 0; i < s.length; i++) {
        list.add(Integer.parseInt(s[i]));
    }
    return list;
}

// Define another helper function to read a list of strings from the standard input stream
public static ArrayList<String> LS( ) {
    Scanner sc = new Scanner(System.in);
    String[] s = sc.nextLine().trim().split(" ");
    ArrayList<String> list = new ArrayList<String>();
    for (int i = 0; i < s.length; i++) {
        list.add(s[i]);
    }
    return list;
}

// Define two variables and initialize them with the values read from the standard input stream
int a = I();
int b = I();

// Check if 'a' is positive
if (a > 0) {
    // If it is, print the string 'Positive'
    System.out.println("Positive");
}

// If 'a' is not positive, check if 'b' is non-negative
else if (a <= 0 && b >= 0) {
    // If it is, print the string 'Zero'
    System.out.println("Zero");
}

// If neither 'a' nor 'b' satisfy the above conditions, check if the sum of 'a' and 'b' is even
else {
    // If it is, print the string 'Negative'
    if ((a + b) % 2 == 0) {
        System.out.println("Negative");
    }
    // Otherwise, print the string 'Positive'
    else {
        System.out.println("Positive");
    }
}

