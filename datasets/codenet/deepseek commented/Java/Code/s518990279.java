import java.io.BufferedReader; // Importing BufferedReader for input operations
import java.io.IOException; // Importing IOException for exception handling
import java.io.InputStreamReader; // Importing InputStreamReader for input stream operations

public class Main { // Defining the Main class

    public static final int BIG_NUM  = 2000000000; // Defining a large number constant
    public static final int MOD  = 1000000007; // Defining a modulo constant

    public static void main(String[] args) { // The main method, the entry point of the program

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in)); // Initializing BufferedReader to read input
        int ans; // Declaring a variable to store the sum of digits

        while(true){ // Starting an infinite loop to read input continuously

            try { // Wrapping the input operation in a try-catch block for exception handling
                String inputed = br.readLine(); // Reading a line of input from the user
                if(inputed.length() == 1 && inputed.equals("0")) break; // Breaking the loop if the input is "0"

                ans = 0; // Initializing the sum variable
                for(int i = 0; i < inputed.length(); i++){ // Iterating over each character in the input string
                    ans += inputed.charAt(i)-'0'; // Converting each character to its corresponding integer value and adding it to the sum
                }

                System.out.printf("%d\n", ans); // Printing the sum of the digits

            } catch (IOException e) { // Catching IOException and printing the stack trace
                e.printStackTrace();
            }
        }
    }
}
