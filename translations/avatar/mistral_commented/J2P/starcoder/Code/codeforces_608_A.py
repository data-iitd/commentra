
import java.util.Scanner; // Importing Scanner class for reading input from the standard input
import java.io.BufferedReader; // Importing BufferedReader class for reading lines from the input stream
import java.io.IOException; // Importing IOException for handling input/output errors
import java.io.InputStreamReader; // Importing InputStreamReader class for reading input from the input stream
import java.io.PrintWriter; // Importing PrintWriter class for writing output to the standard output
import java.nio.charset.MalformedInputException; // Importing MalformedInputException for handling invalid input character encoding
import java.util.StringTokenizer; // Importing StringTokenizer class for tokenizing strings
import java.util.Arrays; // Importing Arrays class for array manipulation
import java.util.HashSet; // Importing HashSet class for set manipulation

public class Main {
    // Main method is the entry point of the program
    public static void main(String[] args) {
        FastScanner in = new FastScanner(); // Creating an instance of FastScanner class for reading input
        Scanner sc = new Scanner(System.in); // Creating an instance of Scanner class for reading input from the standard input
        PrintWriter o = new PrintWriter(System.out); // Creating an instance of PrintWriter class for writing output to the standard output

        int n = sc.nextInt(); // Reading the number of test cases

        while (n-- > 0) { // Processing each test case
            int f = sc.nextInt(); // Reading the first number
            int t = sc.nextInt(); // Reading the second number

            int max = 0; // Initializing the maximum sum to zero

            if (max < f + t) { // Checking if the sum of the current numbers is greater than the current maximum sum
                max = f + t; // Updating the maximum sum if it is
            }
        }

        o.println(Math.max(max, s)); // Writing the maximum of the maximum sum and the given sum to the output
        o.close(); // Closing the PrintWriter instance
    }

    static class FastScanner {
        BufferedReader br; // Declaring a BufferedReader instance for reading lines from the input stream
        StringTokenizer st; // Declaring a StringTokenizer instance for tokenizing strings

        public String next() { // Method for reading the next token from the input
            while (!st.hasMoreElements()) { // If there are no more tokens, read a line from the input
                try {
                    st = new StringTokenizer(br.readLine()); // Creating a new StringTokenizer instance with the read line
                } catch (IOException e) { // Handling input/output errors
                    e.printStackTrace();
                }
            }
            return st.nextToken(); // Returning the next token
        }

        public String nextLine() { // Method for reading the next line from the input
            String str = ""; // Initializing an empty string for storing the line

            try {
                str = br.readLine(); // Reading a line from the input
            } catch (IOException e) { // Handling input/output errors
                e.printStackTrace();
            }

            return str; // Returning the read line
        }

        byte nextByte() { // Method for reading the next byte from the input
            return Byte.parseByte(next()); // Parsing the next token as a byte and returning it
        }

        short nextShort() { // Method for reading the next short from the input
            return Short.parseShort(next()); // Parsing the next token as a short and returning it
        }

        int nextInt() { // Method for reading the next integer from the input
            return Integer.parseInt(next()); // Parsing the next token as an integer and returning it
        }

        long nextLong() { // Method for reading the next long from the input
            return java.lang.Long.parseLong(next()); // Parsing the next token as a long and returning it
        }

        double nextDouble() { // Method for reading the next double from the input
            return Double.parseDouble(next()); // Parsing the next token as a double and returning it
        }
    }
}

I hope these comments help you understand the code better. Let me know if you have any questions or need further clarification.

