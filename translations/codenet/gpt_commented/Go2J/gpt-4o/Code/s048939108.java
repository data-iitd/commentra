import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        // Create a new scanner to read input
        Scanner sc = new Scanner();
        
        // Read a string from the input
        String S = sc.next();
        
        // Check if the string starts with "YAKI" and print the corresponding response
        if (S.startsWith("YAKI")) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
    }

    // Scanner class to handle buffered input reading
    static class Scanner {
        private BufferedReader reader;
        private String currentLine;
        private int currentIndex;

        // Constructor to initialize the scanner
        public Scanner() {
            reader = new BufferedReader(new InputStreamReader(System.in));
            currentLine = "";
            currentIndex = 0;
        }

        // Reads the next word from the input
        public String next() throws IOException {
            pre();
            StringBuilder word = new StringBuilder();
            while (currentIndex < currentLine.length() && currentLine.charAt(currentIndex) != ' ') {
                word.append(currentLine.charAt(currentIndex));
                currentIndex++;
            }
            currentIndex++; // Move past the space
            return word.toString();
        }

        // Prepares the next line for reading
        private void pre() throws IOException {
            if (currentIndex >= currentLine.length()) {
                readLine();
                currentIndex = 0;
            }
        }

        // Reads a line from the input and fills the current line
        private void readLine() throws IOException {
            currentLine = reader.readLine();
            if (currentLine == null) {
                currentLine = ""; // Handle end of input
            }
        }
    }
}

// <END-OF-CODE>
