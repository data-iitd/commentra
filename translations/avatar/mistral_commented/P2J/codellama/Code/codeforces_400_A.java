
# Importing necessary libraries
import java.util.*;
import java.io.*;
import java.math.*;

// Function to read a single value as a tuple
public static void value() {
    Scanner sc = new Scanner(System.in);
    int a = sc.nextInt();
    int b = sc.nextInt();
    System.out.println(a + " " + b);
}

// Function to read multiple values as a tuple
public static void values() {
    Scanner sc = new Scanner(System.in);
    int a = sc.nextInt();
    int b = sc.nextInt();
    int c = sc.nextInt();
    System.out.println(a + " " + b + " " + c);
}

// Function to read a single value as a list
public static void inlst() {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int[] a = new int[n];
    for (int i = 0; i < n; i++) {
        a[i] = sc.nextInt();
    }
    for (int i = 0; i < n; i++) {
        System.out.print(a[i] + " ");
    }
    System.out.println();
}

// Function to read multiple values as a list
public static void inlsts() {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int[] a = new int[n];
    for (int i = 0; i < n; i++) {
        a[i] = sc.nextInt();
    }
    for (int i = 0; i < n; i++) {
        System.out.print(a[i] + " ");
    }
    System.out.println();
}

// Function to read a single value as an integer
public static void inp() {
    Scanner sc = new Scanner(System.in);
    int a = sc.nextInt();
    System.out.println(a);
}

// Function to read a single value as an integer from stdin
public static void inps() {
    Scanner sc = new Scanner(System.in);
    int a = sc.nextInt();
    System.out.println(a);
}

// Function to read a single line as a string
public static void instr() {
    Scanner sc = new Scanner(System.in);
    String a = sc.nextLine();
    System.out.println(a);
}

// Function to read a list of strings
public static void stlst() {
    Scanner sc = new Scanner(System.in);
    String a = sc.nextLine();
    String[] b = a.split(" ");
    for (int i = 0; i < b.length; i++) {
        System.out.print(b[i] + " ");
    }
    System.out.println();
}

// Helper function to check if a sub-array of given size exists in a list
public static boolean help(int a, int b, int[] l) {
    int[][] tot = new int[b][a];
    for (int i = 0; i < b; i++) {
        for (int j = 0; j < a; j++) {
            tot[i][j] = l[i * a + j];
        }
    }
    for (int[] i : tot) {
        if (Arrays.stream(i).sum() == b) {
            return true;
        }
    }
    return false;
}

// Main function to solve the problem
public static void solve() {
    Scanner sc = new Scanner(System.in);
    String x = sc.nextLine();
    int[] s = new int[x.length()];
    for (int i = 0; i < x.length(); i++) {
        if (x.charAt(i) == 'O') {
            s[i] = 0;
        } else {
            s[i] = 1;
        }
    }
    for (int i = 1; i <= 12; i++) {
        if (12 % i == 0) {
            if (help(i, 12 / i, s)) {
                System.out.print(12 / i + "x" + i + " ");
            }
        }
    }
    System.out.println();
}

// Main function to run the code
public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int t = sc.nextInt();
    for (int i = 0; i < t; i++) {
        solve();
    }
}

