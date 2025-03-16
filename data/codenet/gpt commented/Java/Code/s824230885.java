import java.util.*; 
import java.io.*; 
import java.math.*;

public class Main {
    // Don't have to see. start------------------------------------------
    
    // Class to handle input reading from standard input
    static class InputIterator {
        ArrayList<String> inputLine = new ArrayList<String>(1024); // List to store input lines
        int index = 0; // Current index for reading input
        int max; // Maximum number of input lines
        String read; // Variable to hold each line read

        // Constructor to initialize the InputIterator and read all input lines
        InputIterator() {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            try {
                // Read lines until end of input
                while ((read = br.readLine()) != null) {
                    inputLine.add(read);
                }
            } catch (IOException e) {}
            max = inputLine.size(); // Set max to the number of lines read
        }

        // Check if there are more lines to read
        boolean hasNext() {
            return (index < max);
        }

        // Get the next line of input
        String next() {
            if (hasNext()) {
                return inputLine.get(index++);
            } else {
                throw new IndexOutOfBoundsException("There is no more input");
            }
        }
    }

    // HashMap to store conversion strings for different delimiters
    static HashMap<Integer, String> CONVSTR = new HashMap<Integer, String>();
    static InputIterator ii = new InputIterator(); // Instance of InputIterator for reading input
    static PrintWriter out = new PrintWriter(System.out); // PrintWriter for output
    static void flush() {
        out.flush(); // Flush the output stream
    }

    // Custom output methods
    static void myout(Object t) {
        out.println(t); // Print output
    }

    static void myerr(Object t) {
        System.err.print("debug:"); // Print debug information to stderr
        System.err.println(t);
    }

    // Input reading methods
    static String next() {
        return ii.next(); // Get the next line of input
    }

    static boolean hasNext() {
        return ii.hasNext(); // Check if there are more lines to read
    }

    static int nextInt() {
        return Integer.parseInt(next()); // Parse the next line as an integer
    }

    static long nextLong() {
        return Long.parseLong(next()); // Parse the next line as a long
    }

    static double nextDouble() {
        return Double.parseDouble(next()); // Parse the next line as a double
    }

    // Methods to read arrays of different types
    static ArrayList<String> nextStrArray() {
        return myconv(next(), 8); // Convert the next input line into a String array
    }

    static ArrayList<String> nextCharArray() {
        return myconv(next(), 0); // Convert the next input line into a character array
    }

    static ArrayList<Integer> nextIntArray() {
        ArrayList<String> input = nextStrArray(); // Read the next string array
        ArrayList<Integer> ret = new ArrayList<Integer>(input.size()); // Prepare an integer list
        for (int i = 0; i < input.size(); i++) {
            ret.add(Integer.parseInt(input.get(i))); // Parse each string to integer and add to list
        }
        return ret; // Return the list of integers
    }

    static ArrayList<Long> nextLongArray() {
        ArrayList<String> input = nextStrArray(); // Read the next string array
        ArrayList<Long> ret = new ArrayList<Long>(input.size()); // Prepare a long list
        for (int i = 0; i < input.size(); i++) {
            ret.add(Long.parseLong(input.get(i))); // Parse each string to long and add to list
        }
        return ret; // Return the list of longs
    }

    // Method to join elements of a list into a string
    static String myconv(Object list, int no) { // only join
        String joinString = CONVSTR.get(no); // Get the delimiter based on the provided number
        if (list instanceof String[]) {
            return String.join(joinString, (String[]) list); // Join string array
        } else if (list instanceof ArrayList) {
            return String.join(joinString, (ArrayList) list); // Join ArrayList
        } else {
            throw new ClassCastException("Don't join"); // Handle invalid type
        }
    }

    // Method to split a string into a list based on a delimiter
    static ArrayList<String> myconv(String str, int no) { // only split
        String splitString = CONVSTR.get(no); // Get the delimiter based on the provided number
        return new ArrayList<String>(Arrays.asList(str.split(splitString))); // Split and return as ArrayList
    }

    public static void main(String[] args) {
        // Initialize conversion strings for different delimiters
        CONVSTR.put(8, " "); 
        CONVSTR.put(9, "\n"); 
        CONVSTR.put(0, "");

        // Call the main solving function
        solve();
        flush(); // Flush the output after solving
    }
    // Don't have to see. end------------------------------------------

    // Main function to solve the problem
    static void solve() { 
        int N = nextInt(); // Read the number of elements
        ArrayList<Integer> list = nextIntArray(); // Read the list of integers
        int max = 0; // Variable to track the maximum value found
        int output = 0; // Variable to count how many times a new maximum is found

        // Loop through the list to find the number of new maximums
        for (int i = 0; i < N; i++) {
            if (max <= list.get(i)) { // Check if the current element is greater than or equal to max
                max = list.get(i); // Update max
                output++; // Increment the count of new maximums
            }
        }
        myout(output); // Output the result
    }
    // Method addition frame start

    // Method addition frame end
}
