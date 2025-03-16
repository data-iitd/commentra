import java.io.BufferedReader; // Importing BufferedReader for input operations
import java.io.IOException; // Importing IOException for exception handling
import java.io.InputStreamReader; // Importing InputStreamReader for reading input stream
import java.util.*; // Importing all classes from java.util package
import java.math.*; // Importing all classes from java.math package

public class Main { // Defining the class Main
    public static void main(String[] args) throws IOException { // Main method is the entry point of the program
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in)); // Initializing BufferedReader to read input
        StringBuilder sb = new StringBuilder(); // Initializing StringBuilder to build strings efficiently
        String a = br.readLine(); // Reading a line of input from the user
        sb.append(a.replace(",", " ")); // Replacing commas with spaces in the input string and appending to StringBuilder
        System.out.println(sb); // Printing the manipulated string
    }
}
