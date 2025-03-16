import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner();

        // Read the first string from the standard input
        String S = sc.next();

        // Check if the string starts with "YAKI"
        if (S.startsWith("YAKI")) {
            System.out.println("Yes"); // Print "Yes" if the condition is true
        } else {
            System.out.println("No"); // Print "No" if the condition is false
        }
    }

    // Scanner class definition
    static class Scanner {
        private BufferedReader reader;
        private String currentLine;
        private int currentIndex;

        // Initialize a new scanner instance
        public Scanner() {
            reader = new BufferedReader(new InputStreamReader(System.in));
            currentLine = "";
            currentIndex = 0;
        }

        // Next function to read the next token as a string
        public String next() throws IOException {
            pre();
            StringBuilder result = new StringBuilder();
            while (currentIndex < currentLine.length() && currentLine.charAt(currentIndex) != ' ') {
                result.append(currentLine.charAt(currentIndex));
                currentIndex++;
            }
            currentIndex++; // Move past the space
            return result.toString();
        }

        // Pre function to prepare the scanner for reading the next token
        private void pre() throws IOException {
            if (currentIndex >= currentLine.length()) {
                readLine();
                currentIndex = 0;
            }
        }

        // ReadLine function to read a line from the standard input
        private void readLine() throws IOException {
            currentLine = reader.readLine();
            if (currentLine == null) {
                currentLine = ""; // Handle end of input
            }
        }
    }
}

// <END-OF-CODE>
