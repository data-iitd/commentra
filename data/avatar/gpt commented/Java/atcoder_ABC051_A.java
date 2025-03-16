import java.io.BufferedReader; // Importing BufferedReader for reading input
import java.io.IOException; // Importing IOException for handling input/output exceptions
import java.io.InputStreamReader; // Importing InputStreamReader for reading bytes and decoding them into characters
import java.util.*; // Importing all utility classes
import java.math.*; // Importing all math classes

public class Main {
    public static void main(String[] args) throws IOException {
        // Creating a BufferedReader to read input from the console
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        // Using StringBuilder to efficiently build the output string
        StringBuilder sb = new StringBuilder();
        
        // Reading a line of input from the user
        String a = br.readLine();
        
        // Replacing commas in the input string with spaces and appending to StringBuilder
        sb.append(a.replace(",", " "));
        
        // Printing the modified string to the console
        System.out.println(sb);
    }
}
