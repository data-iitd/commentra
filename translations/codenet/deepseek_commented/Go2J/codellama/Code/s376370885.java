
// by syu
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;

// Initialize a BufferedReader instance to read from standard input
BufferedReader in = new BufferedReader(new InputStreamReader(System.in));

public class Main {
    public static void main(String[] args) throws IOException {
        // Read two integers, n and k, from standard input
        int n = Integer.parseInt(in.readLine());
        int k = Integer.parseInt(in.readLine());
        
        // Check if n is divisible by k
        if (n % k == 0) {
            // If n is divisible by k, print 0
            System.out.println(0);
        } else {
            // If n is not divisible by k, print 1
            System.out.println(1);
        }
    }
}

// Define a custom Scanner type to read input efficiently
class Scanner {
    // Create a new Scanner instance with a specified buffer size
    public Scanner(int max) {
        this.max = max;
    }
    
    // Read and return an integer from the input
    public int Int() throws IOException {
        return Integer.parseInt(in.readLine());
    }
    
    // Helper function to check if a byte is a space character
    private boolean isSpace(byte b) {
        return b == ' ' || b == '\n' || b == '\r' || b == '\t';
    }
    
    // Custom split function for bufio.Scanner to split input by words
    private String[] scanWords(String data, boolean atEOF) {
        int start = 0;
        while (start < data.length() && isSpace(data.charAt(start))) {
            start++;
        }
        for (int i = start; i < data.length(); i++) {
            if (isSpace(data.charAt(i))) {
                return new String[] { data.substring(start, i), data.substring(i + 1) };
            }
        }
        if (atEOF && data.length() > start) {
            return new String[] { data.substring(start) };
        }
        return new String[] { "" };
    }
    
    // Helper function to print a line of output
    private void Pln(Object... s) {
        System.out.println(s);
    }
    
    // Initialize a BufferedReader instance to read from standard input
    private BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    
    // Initialize a StringTokenizer instance to split input by words
    private StringTokenizer st = new StringTokenizer("");
    
    // Initialize a buffer size
    private int max;
}

