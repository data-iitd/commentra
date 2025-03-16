
import java.io.*;
import java.util.*;
import java.math.*;

// Function to check if the given indices (i, j) are within the bounds of a grid of size n x m
boolean valid(int i, int j, int n, int m) {
    if (i < n && i >= 0 && j >= 0 && j < m) {
        return true;
    }
    return false;
}

// Function to calculate the sum of integers from i to n using the formula for the sum of an arithmetic series
int sumn(int i, int n) {
    return (n - i) * (i + n) / 2;
}

// Function to solve a quadratic equation ax^2 + bx + c = 0 and return one of its roots
double sqfun(double a, double b, double c) {
    return (-b + Math.sqrt(b * b - 4 * a * c)) / (2 * a);
}

// Function to read a single line of input and return it as a tuple of integers
int[] value() {
    String[] s = instr().split(" ");
    int[] t = new int[s.length];
    for (int i = 0; i < s.length; i++) {
        t[i] = Integer.parseInt(s[i]);
    }
    return t;
}

// Function to read a single line of input from stdin and return it as a tuple of integers
int[] values() {
    String[] s = instr().split(" ");
    int[] t = new int[s.length];
    for (int i = 0; i < s.length; i++) {
        t[i] = Integer.parseInt(s[i]);
    }
    return t;
}

// Function to read a single line of input and return it as a list of integers
ArrayList<Integer> inlst() {
    String[] s = instr().split(" ");
    ArrayList<Integer> t = new ArrayList<Integer>();
    for (int i = 0; i < s.length; i++) {
        t.add(Integer.parseInt(s[i]));
    }
    return t;
}

// Function to read a single line of input from stdin and return it as a list of integers
ArrayList<Integer> inlsts() {
    String[] s = instr().split(" ");
    ArrayList<Integer> t = new ArrayList<Integer>();
    for (int i = 0; i < s.length; i++) {
        t.add(Integer.parseInt(s[i]));
    }
    return t;
}

// Function to read a single integer from input
int inp() {
    return Integer.parseInt(instr());
}

// Function to read a single integer from stdin
int inps() {
    return Integer.parseInt(instr());
}

// Function to read a single line of input and return it as a string
String instr() {
    return new BufferedReader(new InputStreamReader(System.in)).readLine();
}

// Function to read a single line of input and return it as a list of strings
ArrayList<String> stlst() {
    String[] s = instr().split(" ");
    ArrayList<String> t = new ArrayList<String>();
    for (int i = 0; i < s.length; i++) {
        t.add(s[i]);
    }
    return t;
}

// Function to process a string by removing specific characters and converting it to lowercase
String f(String s) {
    String r = "";
    for (int i = 0; i < s.length(); i++) {
        if (s.charAt(i) != '-' && s.charAt(i) != ';' && s.charAt(i) != '_') {
            r += s.charAt(i);
        }
    }
    return r.toLowerCase();
}

// Main function to solve the problem
void solve() {
    ArrayList<String> l = new ArrayList<String>();
    // Read three lines of input, process them, and store the results in a list
    for (int i = 0; i < 3; i++) {
        l.add(f(instr()));
    }
    
    // Generate all permutations of the processed strings
    ArrayList<String> t = new ArrayList<String>();
    for (int i = 0; i < l.size(); i++) {
        for (int j = 0; j < l.size(); j++) {
            for (int k = 0; k < l.size(); k++) {
                if (i != j && j != k && k != i) {
                    t.add(l.get(i) + l.get(j) + l.get(k));
                }
            }
        }
    }
    
    // Read the number of test cases and check if the processed input is in the list of permutations
    for (int i = 0; i < inp(); i++) {
        if (f(instr()).equals(t.get(i))) {
            System.out.println("ACC");  // Accepted
        } else {
            System.out.println("WA");   // Wrong Answer
        }
    }
}

// Entry point of the program
public static void main(String[] args) {
    solve();
}

