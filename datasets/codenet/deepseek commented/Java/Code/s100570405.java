import static java.lang.System.out; // Importing the System.out println method for easy use
import java.lang.Math; // Importing Math class for mathematical operations
import java.io.InputStream; // Importing InputStream for input operations
import java.io.IOException; // Importing IOException for handling input/output exceptions
import java.util.NoSuchElementException; // Importing NoSuchElementException for handling missing elements in collections
import java.util.ArrayList; // Importing ArrayList for dynamic arrays
import java.util.Arrays; // Importing Arrays for array operations
import java.util.LinkedList; // Importing LinkedList for a list that supports element insertion and removal at both ends
import java.util.Collections; // Importing Collections for sorting and other utility methods

public class Main {
    public static void main(String args[]) { // Main method where the program execution begins
        new Main().run(); // Creating an instance of Main and calling its run method
    }

    MyInput in = new MyInput(); // Creating an instance of MyInput for input operations
    public void run() { // The run method where the main logic of the program is implemented
        String Sd = in.next(); // Reading the first input string
        String T = in.next(); // Reading the second input string
        int count = 0; // Initializing a counter for matching characters
        char c; // Declaring a character variable to store current character
        boolean ok = false; // A flag to check if a match is found
        int first = -1; // To store the starting index of the match
        int end = -1; // To store the ending index of the match
        for(int j = 0; j < Sd.length(); j++) { // Outer loop to iterate over possible starting positions
            count = 0; // Resetting the counter for each outer loop iteration
            for(int i = 0; i+j < Sd.length(); i++) { // Inner loop to check for a match
                c = Sd.charAt(i+j); // Getting the character at the current position
                if(c == '?' || c == T.charAt(count)) { // Checking if the character matches or is a '?'
                    count++; // Incrementing the counter if a match is found
                    if(count == T.length()) { // If the entire string T is matched
                        first = i+j - T.length() + 1; // Setting the starting index
                        end = i+j; // Setting the ending index
                        ok = true; // Setting the flag to true
                        break; // Breaking out of the inner loop as a match is found
                    }
                }else count = 0; // Resetting the counter if a mismatch is found
            }
        }
        if(ok) { // If a match is found
            for(int i = 0; i < Sd.length(); i++) { // Iterating over the length of Sd
                if(first <= i && i <= end) { // If the current index is within the matched range
                    out.print(T.charAt(i - first)); // Printing the corresponding character from T
                }else {
                    if(Sd.charAt(i) == '?') out.print("a"); // Replacing '?' with 'a'
                    else out.print(Sd.charAt(i)); // Printing the original character if not '?'
                }
            }
            out.println(); // Printing a newline character
        }else { // If no match is found
            out.println("UNRESTORABLE"); // Printing the result
        }
    }
}

class MyInput { // Defining a class for input operations
    private final InputStream in = System.in; // The input stream
    private final byte[] buffer = new byte[1024]; // Buffer to store input
    private int ptr= 0; // Pointer to the current position in the buffer
    private int buflen = 0; // Length of the buffer
    private boolean hasNextByte() { // Method to check if there is more input
        if(ptr < buflen) {
            return true;
        }else {
            ptr = 0;
            try {
                buflen = in.read(buffer); // Reading more input into the buffer
            } catch(IOException e) {
                e.printStackTrace();
            }
            if(buflen <= 0) {
                return false;
            }
        }
        return true;
    }

    public int readByte() { // Method to read a byte from the buffer
        if (hasNextByte()) return buffer[ptr++];
        else return -1;
    }

    private static boolean isPrintableChar(int c) { // Method to check if a character is printable
        return 33 <= c && c <=126;
    }

    private void skipUnprintable() { // Method to skip unprintable characters
        while(hasNextByte() && !isPrintableChar(buffer[ptr])) ptr++;
    }

    public boolean hasNext() { // Method to check if there is more input
        skipUnprintable();
        return hasNextByte();
    }

    public String next() { // Method to read a string
        if(!hasNext()) throw new NoSuchElementException();
        StringBuilder sb = new StringBuilder();
        int b = readByte();
        while(isPrintableChar(b)) {
            sb.appendCodePoint(b);
            b = readByte();
        }
        return sb.toString();
    }

    public long nextLong() { // Method to read a long integer
        if(!hasNext()) throw new NoSuchElementException();
        long n = 0;
        boolean minus = false;
        int b = readByte();
        if (b == '-') {
            minus = true;
            b = readByte();
        }
        if(b < '0' || '9' < b) {
            throw new NumberFormatException();
        }
        while(true) {
        if('0' <= b && b <= '9') {
            n *= 10;
            n += b - '0';
        }else if(b == -1 || !isPrintableChar(b)) {
            return minus ? -n : n;
        }else {
            throw new NumberFormatException();
        }
            b = readByte();
        }
	}

    public int nextInt() { // Method to read an integer
        long nl = nextLong();
        if(nl < Integer.MIN_VALUE || nl > Integer.MAX_VALUE) throw new NumberFormatException();
        return (int) nl;
    }

    public double nextDouble() { // Method to read a double
        return Double.parseDouble(next());
    }
}