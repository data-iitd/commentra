package main;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        // Declare a variable to hold the input string
        String s;
        
        // Read input from the user and store it in the variable's'
        Scanner sc = new Scanner(System.in);
        s = sc.next();
        
        // Check if the first three characters are the same or the last three characters are the same
        if (s.charAt(0) == s.charAt(1) && s.charAt(1) == s.charAt(2)) || (s.charAt(1) == s.charAt(2) && s.charAt(2) == s.charAt(3)) {
            // If the condition is true, print "Yes"
            System.out.println("Yes");
        } else {
            // If the condition is false, print "No"
            System.out.println("No");
        }
    }
}

