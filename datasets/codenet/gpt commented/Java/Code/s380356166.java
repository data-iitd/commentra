import java.io.BufferedReader;
import static java.util.Comparator.*;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.lang.reflect.Array;
import java.math.BigDecimal;
import java.util.AbstractMap;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;
import java.util.LinkedHashMap;
import java.util.List;
import java.util.Map;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.Set;
import java.util.TreeMap;
import java.util.TreeSet;
import static java.util.Comparator.*;

public class Main {
	
	public static void main(String[] args) {
        // Set up input and output streams
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        MyInput in = new MyInput(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        
        // Create an instance of Solver and execute the solve method
        Solver solver = new Solver();
        solver.solve(1, in, out);
        
        // Close the output stream
        out.close();
    }
    
    // ======================================================================
    // Solver class to handle the problem logic
    // The problem is to find the number of non-negative integer solutions (X, Y, Z)
    // such that X + Y + Z = S, with constraints on the values of X, Y, and Z.
    static class Solver {
    	
		public void solve(int testNumber, MyInput in, PrintWriter out) {
			int ans = 0; // Variable to store the count of valid (X, Y, Z) combinations
			int K = in.nextInt(); // Read the upper limit for X, Y, Z
			int S = in.nextInt(); // Read the target sum S
			int wk = 0; // Temporary variable to hold the value of Z

			// Iterate over all possible values of X and Y
			for(int x = 0; x <= K; x++) {
				for(int y = 0; y <= K; y++) {
					// Calculate Z based on the current values of X and Y
					wk = S - x - y;
					// Check if Z is within the valid range [0, K]
					if(wk >= 0 && wk <= K) {
						ans++; // Increment the count of valid combinations
					}
				}
			}
			// Output the total count of valid combinations
			out.println(ans);
        }
    }
    // ======================================================================
    
    // Pair class to hold a key-value pair
    static class Pair<K, V> extends AbstractMap.SimpleEntry<K, V> {
        /** serialVersionUID. */
        private static final long serialVersionUID = 6411527075103472113L;

        // Constructor to initialize the Pair with key and value
        public Pair(final K key, final V value) {
            super(key, value);
        }

        // Method to return a string representation of the Pair
        public String getString() {
            return "[" + getKey() + "] [" + getValue() + "]";
        }
     }    

    // MyInput class for efficient input handling
    static class MyInput {
        private final BufferedReader in; // BufferedReader for reading input
        private static int pos; // Current position in the buffer
        private static int readLen; // Number of characters read into the buffer
        private static final char[] buffer = new char[1024 * 8]; // Input buffer
        private static char[] str = new char[500 * 8 * 2]; // Temporary character array for reading strings
        private static boolean[] isDigit = new boolean[256]; // Array to check if a character is a digit
        private static boolean[] isSpace = new boolean[256]; // Array to check if a character is whitespace
        private static boolean[] isLineSep = new boolean[256]; // Array to check if a character is a line separator

        // Static block to initialize character arrays
        static {
            for (int i = 0; i < 10; i++) {
                isDigit['0' + i] = true; // Mark digits as true
            }
            isDigit['-'] = true; // Mark '-' as a valid character
            isSpace[' '] = isSpace['\r'] = isSpace['\n'] = isSpace['\t'] = true; // Mark whitespace characters
            isLineSep['\r'] = isLineSep['\n'] = true; // Mark line separators
        }
 
        // Constructor to initialize MyInput with an InputStream
        public MyInput(InputStream is) {
            in = new BufferedReader(new InputStreamReader(is));
        }
 
        // Method to read a single character from the input
        public int read() {
            if (pos >= readLen) {
                pos = 0; // Reset position if end of buffer is reached
                try {
                    readLen = in.read(buffer); // Read into the buffer
                } catch (IOException e) {
                    throw new RuntimeException(); // Handle IOException
                }
                if (readLen <= 0) {
                    throw new MyInput.EndOfFileRuntimeException(); // Handle end of file
                }
            }
            return buffer[pos++]; // Return the next character
        }
 
        // Method to read the next integer from input
        public int nextInt() {
            int len = 0; // Length of the number string
            str[len++] = nextChar(); // Read the first character
            len = reads(len, isSpace); // Read until a space character is found
            int i = 0; // Index for parsing the number
            int ret = 0; // Resulting integer
            if (str[0] == '-') {
                i = 1; // Handle negative numbers
            }
            for (; i < len; i++) ret = ret * 10 + str[i] - '0'; // Convert character array to integer
            if (str[0] == '-') {
                ret = -ret; // Negate if the number is negative
            }
            return ret; // Return the parsed integer
        }
 
        // Method to read the next long integer from input
        public long nextLong() {
            int len = 0; // Length of the number string
            str[len++] = nextChar(); // Read the first character
            len = reads(len, isSpace); // Read until a space character is found
            int i = 0; // Index for parsing the number
            long ret = 0L; // Resulting long integer
            if (str[0] == '-') {
                i = 1; // Handle negative numbers
            }
            for (; i < len; i++) ret = ret * 10 + str[i] - '0'; // Convert character array to long
            if (str[0] == '-') {
                ret = -ret; // Negate if the number is negative
            }
            return ret; // Return the parsed long integer
        }
 
        // Method to read the next string from input
        public String nextString() {
        	String ret = new String(nextDChar()).trim(); // Read and trim the string
            return ret; // Return the trimmed string
        }
 
        // Method to read a delimited character array from input
        public char[] nextDChar() {
            int len = 0; // Length of the character array
            len = reads(len, isSpace); // Read until a space character is found
            char[] ret = new char[len + 1]; // Create a new character array
            for (int i = 0; i < len; i++) ret[i] = str[i]; // Copy characters to the new array
            ret[len] = 0x00; // Null-terminate the character array
            return ret; // Return the character array
        }
 
        // Method to read the next non-space character
        public char nextChar() {
            while (true) {
                final int c = read(); // Read a character
                if (!isSpace[c]) { // Check if it is not a space
                    return (char) c; // Return the character
                }
            }
        }
 
        // Method to read characters until a specified condition is met
        int reads(int len, boolean[] accept) {
            try {
                while (true) {
                    final int c = read(); // Read a character
                    if (accept[c]) { // Check if it is accepted
                        break; // Exit loop if accepted
                    }
                    // Resize the character array if necessary
                    if (str.length == len) {
                        char[] rep = new char[str.length * 3 / 2];
                        System.arraycopy(str, 0, rep, 0, str.length);
                        str = rep; // Update the reference to the new array
                    }
                    str[len++] = (char) c; // Add the character to the array
                }
            } catch (MyInput.EndOfFileRuntimeException e) {
            }
            return len; // Return the length of the read characters
        }
 
        // Custom exception for end of file
        static class EndOfFileRuntimeException extends RuntimeException {
        }
    }
}
