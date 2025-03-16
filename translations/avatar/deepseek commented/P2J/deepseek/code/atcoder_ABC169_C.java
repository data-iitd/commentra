import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        // Set the recursion limit to avoid infinite recursion
        // (This is not necessary in Java, as it handles recursion differently)

        // Debugging function to print debug information if TERM_PROGRAM is in environ
        // (This is not necessary in Java, as it handles debugging differently)

        // Function to read input from stdin without trailing whitespace
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        String[] saSb = input.readLine().trim().split(" ");
        int a = Integer.parseInt(saSb[0]);
        int b = (int) (Double.parseDouble(saSb[1]) * 100 + 0.1);

        // Perform the calculation and print the result
        System.out.println(a * b / 100);
    }
}

