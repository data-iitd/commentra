// Package main contains the entry point of the program.
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

// Main class contains the entry point of the program.
public class Main {
    // Main method is the entry point of the program.
    public static void main(String[] args) throws IOException {
        // Initialize a new Scanner object named sc.
        Scanner sc = new Scanner();
        // Read the height H, width W, and number of obstacles N from the standard input.
        int H = sc.nextInt();
        int W = sc.nextInt();
        int N = sc.nextInt();
        // Calculate the maximum dimension A between H and W.
        int A = Math.max(H, W);
        // Print the result, which is the number of rows or columns needed to place all obstacles without overlapping.
        System.out.println((N + A - 1) / A);
    }
}

// Scanner class represents the input reader.
class Scanner {
    // BufferedReader field r is used for reading from the standard input.
    private BufferedReader r;
    // StringTokenizer field tokenizer is used for tokenizing input.
    private StringTokenizer tokenizer;

    // Constructor initializes a new Scanner object with the standard input.
    public Scanner() {
        r = new BufferedReader(new InputStreamReader(System.in));
    }

    // Next method reads the next token from the input and returns it as a string.
    public String next() throws IOException {
        // If tokenizer is null or has no more tokens, read a new line and create a new tokenizer.
        if (tokenizer == null || !tokenizer.hasMoreTokens()) {
            String line = r.readLine();
            tokenizer = new StringTokenizer(line);
        }
        // Return the next token.
        return tokenizer.nextToken();
    }

    // NextInt method reads an integer from the input and returns it.
    public int nextInt() throws IOException {
        // Read the next token as a string and parse it as an integer.
        return Integer.parseInt(next());
    }

    // NextInt64 method reads a 64-bit integer from the input and returns it.
    public long nextInt64() throws IOException {
        // Read the next token as a string and parse it as a long.
        return Long.parseLong(next());
    }

    // NextFloat method reads a floating-point number from the input and returns it.
    public float nextFloat() throws IOException {
        // Read the next token as a string and parse it as a float.
        return Float.parseFloat(next());
    }

    // NextIntArray method reads an array of integers from the input and returns it.
    public int[] nextIntArray() throws IOException {
        // Read the next line as a string.
        String line = r.readLine();
        // Split the line into tokens using spaces as delimiters.
        String[] tokens = line.split(" ");
        // Parse each token as an integer and store it in an array.
        int[] result = new int[tokens.length];
        for (int i = 0; i < tokens.length; i++) {
            result[i] = Integer.parseInt(tokens[i]);
        }
        // Return the result.
        return result;
    }

    // NextInt64Array method reads an array of 64-bit integers from the input and returns it.
    public long[] nextInt64Array() throws IOException {
        // Read the next line as a string.
        String line = r.readLine();
        // Split the line into tokens using spaces as delimiters.
        String[] tokens = line.split(" ");
        // Parse each token as a long and store it in an array.
        long[] result = new long[tokens.length];
        for (int i = 0; i < tokens.length; i++) {
            result[i] = Long.parseLong(tokens[i]);
        }
        // Return the result.
        return result;
    }

    // NextMap method reads a map from the input and returns it.
    public java.util.Map<Integer, Boolean> nextMap() throws IOException {
        // Read the next line as a string.
        String line = r.readLine();
        // Split the line into tokens using spaces as delimiters.
        String[] tokens = line.split(" ");
        // Create a map to store the key-value pairs.
        java.util.Map<Integer, Boolean> map = new java.util.HashMap<>();
        for (String token : tokens) {
            int key = Integer.parseInt(token.split(":")[0]);
            map.put(key, true);
        }
        // Return the result.
        return map;
    }
}

// <END-OF-CODE>
