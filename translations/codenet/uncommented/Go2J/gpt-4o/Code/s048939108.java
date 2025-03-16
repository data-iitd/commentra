import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner();
        String S = sc.next();
        if (S.startsWith("YAKI")) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
    }

    static class Scanner {
        private BufferedReader reader;
        private String currentLine;
        private int currentIndex;

        public Scanner() {
            reader = new BufferedReader(new InputStreamReader(System.in));
        }

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

        private void pre() throws IOException {
            if (currentLine == null || currentIndex >= currentLine.length()) {
                readLine();
                currentIndex = 0;
            }
        }

        private void readLine() throws IOException {
            currentLine = reader.readLine();
            currentIndex = 0;
        }
    }
}

// <END-OF-CODE>
