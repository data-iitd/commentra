import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    // Define constants for large numbers and modulo value
    public static final int BIG_NUM  = 2000000000;
    public static final int MOD  = 1000000007;

    public static void main(String[] args) {

        // Create a BufferedReader to read input from the console
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int ans;

        // Infinite loop to continuously read input until a break condition is met
        while(true){

            try {
                // Read a line of input from the user
                String inputed = br.readLine();
                
                // Check if the input is "0", if so, exit the loop
                if(inputed.length() == 1 && inputed.equals("0")) break;

                // Initialize the answer variable to accumulate the sum of digits
                ans = 0;

                // Loop through each character in the input string
                for(int i = 0; i < inputed.length(); i++){
                    // Convert the character to its integer value and add to ans
                    ans += inputed.charAt(i) - '0';
                }

                // Print the sum of the digits
                System.out.printf("%d\n", ans);

            } catch (IOException e) {
                // Print the stack trace in case of an IOException
                e.printStackTrace();
            }
        }
    }
}
