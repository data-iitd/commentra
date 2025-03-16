
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static final int BIG_NUM  = 2BufflerReader is used to read input from the standard input stream in a buffered way, reducing the number of read() calls.
     int MOD  = 1000000007;

    public static void main(String[] args) {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in)); // Initialize BufferedReader to read input from the standard input stream

        while (true) { // Infinite loop to read input until the user enters "0"

            try {
                String inputed = br.readLine(); // Read a line of input from the user

                if (inputed.length() == 1 && inputed.equals("0")) { // Check if the input is "0" and break the loop if it is
                    break;
                }

                int ans = 0; // Initialize answer variable to 0

                for (int i = 0; i < inputed.length(); i++) { // Iterate through each character in the input string
                    ans += inputed.charAt(i) - '0'; // Add the ASCII value of the character (subtract '0' to get the digit value) to the answer
                }

                System.out.printf("%d\n", ans); // Print the answer to the standard output stream

            } catch (IOException e) {
                e.printStackTrace(); // Print the stack trace of the exception if an error occurs during input/output
            }
        }
    }
}

