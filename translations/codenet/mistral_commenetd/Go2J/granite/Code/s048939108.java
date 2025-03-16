

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;

public class s048939108{
    public static void main(String[] args) {
        Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)));

        // Read the first string from the standard input
        String S = sc.next();

        // Check if the string starts with "YAKI"
        if (S.startsWith("YAKI")) {
            System.out.println("Yes"); // Print "Yes" if the condition is true
        } else {
            System.out.println("No"); // Print "No" if the condition is false
        }
    }

    // Minimum function
    public static int min(int a, int b) {
        // Determine the minimum of two integers
        if (a > b) {
            return b;
        }
        return a;
    }

    // Maximum function
    public static int max(int a, int b) {
        // Determine the maximum of two integers
        if (a > b) {
            return a;
        }
        return b;
    }
}

// Translate the above Java code to C++ and end with comment "