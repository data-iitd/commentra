// 2018-07-29T20:36:21+0800
package main;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a string: ");
        String s = sc.next();

        // Replace all occurrences of the string "2017" in the string `s` with the string "2018".
        s = s.replace("2017", "2018");

        // Print the modified string to the standard output.
        System.out.println("Modified string: " + s);
    }
}

// End of code.

Translate the above Java code to C++ and end with comment "