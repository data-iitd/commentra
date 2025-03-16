
package main;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare a string variable 'a' to store user input
        String a;

        // Read user input using Scanner class and store it in variable 'a'
        Scanner sc = new Scanner(System.in);
        a = sc.next();

        // Initialize a string variable 'ans' with value "Good"
        String ans = "Good";

        // Loop through each character in the string 'a' for 3 times
        for (int i = 0; i < 3; i++) {
            // Check if the current character is same as next character
            if (a.charAt(i) == a.charAt(i+1)) {
                // Update the value of 'ans' if current and next character are same
                ans = "Bad";
            }
        }

        // Print the final value of 'ans'
        System.out.println(ans);
    }
}

