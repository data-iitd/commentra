import java.util.Scanner; // Importing the Scanner class for standard input
import java.io.BufferedReader; // Importing BufferedReader for fast input reading
import java.io.IOException; // Importing IOException for exception handling
import java.io.InputStreamReader; // Importing InputStreamReader to read input stream
import java.io.PrintWriter; // Importing PrintWriter for formatted output
import java.nio.charset.MalformedInputException; // Importing MalformedInputException for input validation
import java.util.StringTokenizer; // Importing StringTokenizer for tokenizing strings
import java.util.Arrays; // Importing Arrays for array operations
import java.util.HashSet; // Importing HashSet for set operations

public class Main { // Defining the main class
    public static void main(String[] args) { // Main method is the entry point
        FastScanner in = new FastScanner(); // Creating an instance of FastScanner for fast input reading
        Scanner sc = new Scanner(System.in); // Creating a Scanner object for standard input
        PrintWriter o = new PrintWriter(System.out); // Creating a PrintWriter object for output

        int n = sc.nextInt(); // Reading the first integer n from the standard input
        int s = sc.nextInt(); // Reading the second integer s from the standard input
        int max = 0; // Initializing max to store the maximum sum of f and t

        while (n-- > 0) { // Looping n times
            int f = sc.nextInt(); // Reading the first value in the loop
            int t = sc.nextInt(); // Reading the second value in the loop
            if (max < f + t) { // Checking if the sum of f and t is greater than the current max
                max = f + t; // Updating max if the condition is true
            }
        }

        o.println(Math.max(max, s)); // Printing the maximum of max and s
        o.close(); // Closing the PrintWriter
    }

    static class FastScanner { // Defining a nested static class FastScanner for fast input reading
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in)); // Creating a BufferedReader object
        StringTokenizer st = new StringTokenizer(""); // Creating a StringTokenizer object

        public String next() { // Method to read the next token
            while (!st.hasMoreElements()) { // Checking if there are more elements in the tokenizer
                try {
                    st = new StringTokenizer(br.readLine()); // Refreshing the tokenizer with the next line
                } catch (IOException e) {
                    e.printStackTrace(); // Printing the stack trace if an IOException occurs
                }
            }
            return st.nextToken(); // Returning the next token
        }

        public String nextLine() { // Method to read the next line
            String str = "";
            try {
                str = br.readLine(); // Reading the next line
            } catch (IOException e) {
                e.printStackTrace(); // Printing the stack trace if an IOException occurs
            }
            return str; // Returning the next line
        }

        byte nextByte() { // Method to read the next byte
            return Byte.parseByte(next()); // Returning the next byte parsed from a string
        }

        short nextShort() { // Method to read the next short
            return Short.parseShort(next()); // Returning the next short parsed from a string
        }

        int nextInt() { // Method to read the next int
            return Integer.parseInt(next()); // Returning the next int parsed from a string
        }

        long nextLong() { // Method to read the next long
            return Long.parseLong(next()); // Returning the next long parsed from a string
        }

        double nextDouble() { // Method to read the next double
            return Double.parseDouble(next()); // Returning the next double parsed from a string
        }
    }
}
