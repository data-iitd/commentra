package com.company;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        // Declare a variable to hold the input string
        String s;

        // Read input from the user and store it in the variable's'
        Scanner sc = new Scanner(System.in);
        s = sc.next();

        // Check if the length of the string is at least 4 characters 
        // and if the first four characters are "YAKI"
        if (s.length() >= 4 && s.substring(0, 4).equals("YAKI")) {
            // If the condition is true, print "Yes"
            System.out.println("Yes");
        } else {
            // If the condition is false, print "No"
            System.out.println("No");
        }
    }
}

