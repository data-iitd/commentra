import static java.lang.System.out;
import java.lang.Math;
import java.io.InputStream;
import java.io.IOException;
import java.util.NoSuchElementException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Collections;

public class Main {
    public static void main(String args[]) {
        // Start the program by creating an instance of Main and calling the run method
        new Main().run();
    }

    // Create an instance of MyInput to handle input
    MyInput in = new MyInput();

    public void run() {
        // Read two strings from input: Sd (the string with '?' characters) and T (the target string)
        String Sd = in.next();
        String T = in.next();
        
        // Initialize variables for processing
        int count = 0; // To count matched characters in T
        char c; // To hold the current character from Sd
        boolean ok = false; // Flag to indicate if a match was found
        int first = -1; // To store the starting index of the match
        int end = -1; // To store the ending index of the match

        // Iterate through each character in Sd to find a match for T
        for(int j = 0; j < Sd.length(); j++) {
            count = 0; // Reset count for each starting position
            for(int i = 0; i+j < Sd.length(); i++) {
                c = Sd.charAt(i+j); // Get the current character from Sd
                // Check if the character is a '?' or matches the current character in T
                if(c == '?' || c == T.charAt(count)) {
                    count++; // Increment the count of matched characters
                    // If all characters in T are matched
                    if(count == T.length()) {
                        // Record the start and end indices of the match
                        first = i+j - T.length() + 1;
                        end = i+j;
                        ok = true; // Set the flag to true indicating a match was found
                        break; // Exit the inner loop as we found a match
                    }
                } else {
                    count = 0; // Reset count if there is no match
                }
            }
        }

        // If a match was found, reconstruct the output string
        if(ok) {
            for(int i = 0; i < Sd.length(); i++) {
                // If the current index is within the matched range, print the corresponding character from T
                if(first <= i && i <= end) {
                    out.print(T.charAt(i - first));
                } else {
                    // If the character in Sd is '?', replace it with 'a'
                    if(Sd.charAt(i) == '?') out.print("a");
                    else out.print(Sd.charAt(i)); // Otherwise, print the original character
                }
            }
            out.println(); // Print a newline after the output
        } else {
            // If no match was found, print "UNRESTORABLE"
            out.println("UNRESTORABLE");
        }
    }
}

// Class to handle input operations
class MyInput {
    private final InputStream in = System.in; // Input stream for reading data
    private final byte[] buffer = new byte[1024]; // Buffer for reading bytes
    private int ptr = 0; // Pointer for the current position in the buffer
    private int buflen = 0; // Length of the buffer filled with data

    // Check if there is a next byte available to read
    private boolean hasNextByte() {
        if(ptr < buflen) {
            return true; // Return true if there are bytes left in the buffer
        } else {
            ptr = 0; // Reset pointer
            try {
                buflen = in.read(buffer); // Read new data into the buffer
            } catch(IOException e) {
                e.printStackTrace(); // Handle any IO exceptions
            }
            if(buflen <= 0) {
                return false; // Return false if no bytes were read
            }
        }
        return true; // Return true if there are bytes available
    }

    // Read the next byte from the input
    public int readByte() {
        if (hasNextByte()) return buffer[ptr++]; // Return the current byte and increment the pointer
        else return -1; // Return -1 if no byte is available
    }

    // Check if a character is printable
    private static boolean isPrintableChar(int c) {
        return 33 <= c && c <= 126; // Printable ASCII characters range
    }

    // Skip unprintable characters in the input
    private void skipUnprintable() {
        while(hasNextByte() && !isPrintableChar(buffer[ptr])) ptr++; // Move pointer past unprintable characters
    }

    // Check if there is a next printable token available
    public boolean hasNext() {
        skipUnprintable(); // Skip any unprintable characters
        return hasNextByte(); // Check for the next byte
    }

    // Read the next printable string from input
    public String next() {
        if(!hasNext()) throw new NoSuchElementException(); // Throw exception if no next token is available
        StringBuilder sb = new StringBuilder(); // StringBuilder to construct the output string
        int b = readByte(); // Read the first byte
        // Continue reading bytes while they are printable
        while(isPrintableChar(b)) {
            sb.appendCodePoint(b); // Append the printable character to the StringBuilder
            b = readByte(); // Read the next byte
        }
        return sb.toString(); // Return the constructed string
    }

    // Read the next long integer from input
    public long nextLong() {
        if(!hasNext()) throw new NoSuchElementException(); // Throw exception if no next token is available
        long n = 0; // Variable to store the number
        boolean minus = false; // Flag to indicate if the number is negative
        int b = readByte(); // Read the first byte
        // Check for a negative sign
        if (b == '-') {
            minus = true; // Set the flag for negative
            b = readByte(); // Read the next byte
        }
        // Validate the first character
        if(b < '0' || '9' < b) {
            throw new NumberFormatException(); // Throw exception if the first character is not a digit
        }
        // Read the digits of the number
        while(true) {
            if('0' <= b && b <= '9') {
                n *= 10; // Shift left by one decimal place
                n += b - '0'; // Add the current digit to the number
            } else if(b == -1 || !isPrintableChar(b)) {
                return minus ? -n : n; // Return the number, negated if necessary
            } else {
                throw new NumberFormatException(); // Throw exception for invalid characters
            }
            b = readByte(); // Read the next byte
        }
    }

    // Read the next integer from input
    public int nextInt() {
        long nl = nextLong(); // Read a long and cast it to int
        // Check for integer overflow
        if(nl < Integer.MIN_VALUE || nl > Integer.MAX_VALUE) throw new NumberFormatException();
        return (int) nl; // Return the integer value
    }

    // Read the next double from input
    public double nextDouble() {
        return Double.parseDouble(next()); // Parse and return the next string as a double
    }
}
