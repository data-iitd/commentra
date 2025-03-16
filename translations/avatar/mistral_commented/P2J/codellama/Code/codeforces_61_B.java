
// Importing necessary libraries
import java.util.*;
import java.io.*;
import java.math.*;

// Function to check if given indices are valid
public static boolean valid(int i, int j, int n, int m) {
    /*
     * This function checks if given indices (i, j) are valid within the given dimensions (n, m).
     */
    if (i < n && i >= 0 && j >= 0 && j < m) {
        return true;
    }
    return false;
}

// Function to calculate sum of first n natural numbers
public static int sumn(int i, int n) {
    /*
     * This function calculates the sum of first n natural numbers.
     */
    return (n - i) * (i + n) / 2;
}

// Function to calculate square root of a number using quadratic formula
public static int sqfun(int a, int b, int c) {
    /*
     * This function calculates the square root of a number using quadratic formula.
     */
    return (-b + (int) Math.sqrt(b * b - 4 * a * c)) / 2 * a;
}

// Function to read a single line as a tuple of integers
public static int[] value() {
    /*
     * This function reads a single line as a tuple of integers.
     */
    String[] s = new BufferedReader(new InputStreamReader(System.in)).readLine().split(" ");
    int[] t = new int[s.length];
    for (int i = 0; i < s.length; i++) {
        t[i] = Integer.parseInt(s[i]);
    }
    return t;
}

// Function to read a single line as a list of integers
public static List<Integer> values() {
    /*
     * This function reads a single line as a list of integers.
     */
    String[] s = new BufferedReader(new InputStreamReader(System.in)).readLine().split(" ");
    List<Integer> t = new ArrayList<Integer>();
    for (int i = 0; i < s.length; i++) {
        t.add(Integer.parseInt(s[i]));
    }
    return t;
}

// Function to read a single integer
public static int inp() {
    /*
     * This function reads a single integer from the standard input.
     */
    return Integer.parseInt(new BufferedReader(new InputStreamReader(System.in)).readLine());
}

// Function to read a single integer from the standard input as a string
public static String instr() {
    /*
     * This function reads a single string from the standard input.
     */
    return new BufferedReader(new InputStreamReader(System.in)).readLine();
}

// Function to read a list of integers
public static List<Integer> inlst() {
    /*
     * This function reads a list of integers from the standard input.
     */
    String[] s = new BufferedReader(new InputStreamReader(System.in)).readLine().split(" ");
    List<Integer> t = new ArrayList<Integer>();
    for (int i = 0; i < s.length; i++) {
        t.add(Integer.parseInt(s[i]));
    }
    return t;
}

// Function to read a list of integers from the standard input
public static List<Integer> inlsts() {
    /*
     * This function reads a list of integers from the standard input.
     */
    String[] s = new BufferedReader(new InputStreamReader(System.in)).readLine().split(" ");
    List<Integer> t = new ArrayList<Integer>();
    for (int i = 0; i < s.length; i++) {
        t.add(Integer.parseInt(s[i]));
    }
    return t;
}

// Function to read a single integer from the standard input
public static int inp() {
    /*
     * This function reads a single integer from the standard input.
     */
    return Integer.parseInt(new BufferedReader(new InputStreamReader(System.in)).readLine());
}

// Function to read a single integer from the standard input
public static int inps() {
    /*
     * This function reads a single integer from the standard input.
     */
    return Integer.parseInt(new BufferedReader(new InputStreamReader(System.in)).readLine());
}

// Function to read a single string from the standard input
public static String instr() {
    /*
     * This function reads a single string from the standard input.
     */
    return new BufferedReader(new InputStreamReader(System.in)).readLine();
}

// Function to convert a string to a list
public static List<String> stlst() {
    /*
     * This function converts a string to a list.
     */
    String[] s = new BufferedReader(new InputStreamReader(System.in)).readLine().split(" ");
    List<String> t = new ArrayList<String>();
    for (int i = 0; i < s.length; i++) {
        t.add(s[i]);
    }
    return t;
}

// Main function to solve the problem
public static void solve() {
    /*
     * This function reads three strings from the standard input, generates all possible permutations of these strings,
     * and checks if the given string is present in the list of permutations. If it is, then the function prints 'ACC',
     * otherwise it prints 'WA'.
     */
    List<String> l = new ArrayList<String>();
    for (int i = 0; i < 3; i++) {
        l.add(f(new BufferedReader(new InputStreamReader(System.in)).readLine()));
    }
    List<List<String>> t = new ArrayList<List<String>>();
    for (int i = 0; i < (int) Math.pow(3, 3); i++) {
        List<String> s = new ArrayList<String>();
        for (int j = 0; j < 3; j++) {
            s.add(l.get(j).charAt(i % 3) + "");
        }
        t.add(s);
    }
    l = new ArrayList<String>();
    for (int i = 0; i < (int) Math.pow(3, 3); i++) {
        l.add("" + t.get(i).get(0) + t.get(i).get(1) + t.get(i).get(2));
    }
    for (int i = 0; i < inp(); i++) {
        if (f(instr()).equals(l.get(i))) {
            System.out.println("ACC");
        } else {
            System.out.println("WA");
        }
    }
}

// Starting the program
public static void main(String[] args) {
    solve();
}

