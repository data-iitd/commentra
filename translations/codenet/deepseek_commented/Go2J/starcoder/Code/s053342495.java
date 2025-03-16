package com.company;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        // Declare a variable to store the day of Christmas
        int day;
        // Read an integer input from the user
        Scanner scanner = new Scanner(System.in);
        day = scanner.nextInt();

        // Use a switch statement to determine the day of Christmas
        switch (day) {
            case 25:
                // If the day is Christmas (December 25), print "Christmas"
                System.out.println("Christmas");
                break;
            case 24:
                // If the day is Christmas Eve (December 24), print "Christmas Eve"
                System.out.println("Christmas Eve");
                break;
            case 23:
                // If the day is Christmas Eve Eve (December 23), print "Christmas Eve Eve"
                System.out.println("Christmas Eve Eve");
                break;
            case 22:
                // If the day is Christmas Eve Eve Eve (December 22), print "Christmas Eve Eve Eve"
                System.out.println("Christmas Eve Eve Eve");
                break;
        }
    }
}

