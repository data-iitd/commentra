import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

// Main class
public class Main {
    // Main method starts here
    public static void main(String[] args) throws IOException {
        // Initialize a new scanner to read input
        Scanner sc = new Scanner();
        // Read the next string from the scanner
        String S = sc.next();
        // Check if the string S starts with the prefix "YAKI"
        if (S.startsWith("YAKI")) {
            // If it does, print "Yes"
            System.out.println("Yes");
        } else {
            // Otherwise, print "No"
            System.out.println("No");
        }
    }
}

// Custom scanner class to handle input reading
class Scanner {
    private BufferedReader reader;
    private String currentLine;
    private int currentIndex;

    // Constructor to create a new scanner instance
    public Scanner() {
        reader = new BufferedReader(new InputStreamReader(System.in));
        currentLine = "";
        currentIndex = 0;
    }

    // Method to read the next word from the input
    public String next() throws IOException {
        pre();
        int start = currentIndex;
        while (currentIndex < currentLine.length() && currentLine.charAt(currentIndex) != ' ') {
            currentIndex++;
        }
        String result = currentLine.substring(start, currentIndex);
        currentIndex++;
        return result;
    }

    // Method to read the next line from the input
    public String nextLine() throws IOException {
        pre();
        String result = currentLine.substring(currentIndex);
        currentIndex = currentLine.length();
        return result;
    }

    // Method to read the next integer from the input
    public int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    // Method to read the next array of integers from the input
    public List<Integer> nextIntArray() throws IOException {
        pre();
        List<Integer> result = new ArrayList<>();
        int start = currentIndex;
        while (currentIndex < currentLine.length() + 1) {
            if (currentIndex == currentLine.length() || currentLine.charAt(currentIndex) == ' ') {
                int v = Integer.parseInt(currentLine.substring(start, currentIndex));
                result.add(v);
                start = currentIndex + 1;
            }
            currentIndex++;
        }
        return result;
    }

    // Method to preprocess the buffer before reading
    private void pre() throws IOException {
        if (currentIndex >= currentLine.length()) {
            readLine();
            currentIndex = 0;
        }
    }

    // Method to read a line from the input and update the buffer
    private void readLine() throws IOException {
        currentLine = reader.readLine();
    }
}

// <END-OF-CODE>
