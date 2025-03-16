import static java.lang.System.out; // Importing static out from System class for printing
import java.lang.Math;
import java.io.InputStream;
import java.io.IOException;
import java.util.NoSuchElementException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Collections;

public class Main {
    public static void main(String args[]) { // Main method to start the execution of the program
        new Main().run(); // Creating an instance of Main class and calling run method
    }

    MyInput in = new MyInput(); // Creating an object of MyInput class named in
    public void run() { // Method to run the program
        String Sd = in.next(); // Reading the first string from input using MyInput class
        String T = in.next(); // Reading the second string from input using MyInput class
        int count = 0; // Initializing a counter variable
        char c; // Declaring a character variable
        boolean ok = false; // Initializing a boolean variable to check if a match is found
        int first = -1; // Initializing variables to store the starting index and ending index of the pattern in the string
        int end = -1;

        for(int j = 0; j < Sd.length(); j++) { // Iterating through each character in the first string
            count = 0; // Resetting the counter for each character in the first string
            for(int i = 0; i+j < Sd.length(); i++) { // Nested loop to compare each character in the first string with the pattern string
                c = Sd.charAt(i+j); // Reading the character at the current index in the first string
                if(c == '?' || c == T.charAt(count)) { // Checking if the current character in the first string matches the pattern string or is a wildcard character '?'
                    count++; // Incrementing the counter if a match is found
                    if(count == T.length()) { // Checking if the entire pattern string has been matched
                        first = i+j - T.length() + 1; // Storing the starting index of the pattern string in the first string
                        end = i+j; // Storing the ending index of the pattern string in the first string
                        ok = true; // Setting the boolean variable to true if a match is found
                        break; // Exiting the nested loop if a match is found
                    }
                }else count = 0; // Resetting the counter if a mismatch is found

            }
        }

        if(ok) { // Checking if a match is found
            for(int i = 0; i < Sd.length(); i++) { // Iterating through each character in the first string
                if(first <= i && i <= end) { // Printing the pattern string characters in place of the matched wildcard characters in the first string
                    out.print(T.charAt(i - first));
                }else { // Printing the remaining characters of the first string which are not part of the pattern string
                    if(Sd.charAt(i) == '?') out.print("a"); // Printing 'a' for each wildcard character in the first string
                    else out.print(Sd.charAt(i)); // Printing the character in the first string which is not part of the pattern string
                }
            }
            out.println(); // Printing a newline after printing the first string
        }else {
            out.println("UNRESTORABLE"); // Printing "UNRESTORABLE" if no match is found
        }
    }

    class MyInput { // Custom Input class to read input from the standard input stream
        // ... (The rest of the MyInput class code remains the same)
    }
}
