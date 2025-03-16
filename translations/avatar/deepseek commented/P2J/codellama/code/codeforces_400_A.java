
import java.io.*;
import java.util.*;
import java.math.*;

// Function to read a single value from input
public static void value() {
    Scanner sc = new Scanner(System.in);
    int a = sc.nextInt();
    int b = sc.nextInt();
    System.out.println(a + " " + b);
}

// Function to read multiple values from input
public static void values() {
    Scanner sc = new Scanner(System.in);
    int a = sc.nextInt();
    int b = sc.nextInt();
    int c = sc.nextInt();
    System.out.println(a + " " + b + " " + c);
}

// Function to read a list of integers from input
public static void inlst() {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int[] arr = new int[n];
    for (int i = 0; i < n; i++) {
        arr[i] = sc.nextInt();
    }
    for (int i = 0; i < n; i++) {
        System.out.print(arr[i] + " ");
    }
}

// Function to read a list of integers from stdin
public static void inlsts() {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int[] arr = new int[n];
    for (int i = 0; i < n; i++) {
        arr[i] = sc.nextInt();
    }
    for (int i = 0; i < n; i++) {
        System.out.print(arr[i] + " ");
    }
}

// Function to read a single integer from input
public static void inp() {
    Scanner sc = new Scanner(System.in);
    int a = sc.nextInt();
    System.out.println(a);
}

// Function to read a single integer from stdin
public static void inps() {
    Scanner sc = new Scanner(System.in);
    int a = sc.nextInt();
    System.out.println(a);
}

// Function to read a single string from input
public static void instr() {
    Scanner sc = new Scanner(System.in);
    String a = sc.next();
    System.out.println(a);
}

// Function to read a list of strings from input
public static void stlst() {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    String[] arr = new String[n];
    for (int i = 0; i < n; i++) {
        arr[i] = sc.next();
    }
    for (int i = 0; i < n; i++) {
        System.out.print(arr[i] + " ");
    }
}

// Helper function to check if a grid of given dimensions can be formed
public static boolean help(int a, int b, int[] l) {
    int[][] tot = new int[b][a];
    for (int i = 0; i < b; i++) {
        for (int j = 0; j < a; j++) {
            tot[i][j] = l[i * a + j];
        }
    }
    for (int i = 0; i < a; i++) {
        int sum = 0;
        for (int j = 0; j < b; j++) {
            sum += tot[j][i];
        }
        if (sum == b) {
            return true;
        }
    }
    return false;
}

// Main solving function
public static void solve() {
    int[] s = new int[12];
    Scanner sc = new Scanner(System.in);
    String x = sc.next();
    for (int i = 0; i < 12; i++) {
        if (x.charAt(i) == 'O') {
            s[i] = 0;
        } else {
            s[i] = 1;
        }
    }
    int[][] tot = new int[12][12];
    for (int i = 1; i <= 12; i++) {
        if (12 % i == 0) {
            if (help(i, 12 / i, s)) {
                tot[i][12 / i] = 1;
            }
        }
    }
    System.out.println(tot.length);
    for (int i = 0; i < tot.length; i++) {
        for (int j = 0; j < tot[i].length; j++) {
            if (tot[i][j] == 1) {
                System.out.print(i + "x" + j + " ");
            }
        }
    }
}

// Main execution block
public static void main(String[] args) {
    for (int i = 0; i < inp(); i++) {
        solve();
    }
}

