import java.io.BufferedReader; // Importing BufferedReader for reading input
import java.io.IOException; // Importing IOException for handling input/output exceptions
import java.io.InputStreamReader; // Importing InputStreamReader for reading input from the console

public class Main {
    public static void main(String[] subhani) throws IOException {
        // Creating a BufferedReader object to read input from the console
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        // Reading an integer input from the user
        int n = Integer.parseInt(br.readLine());
        
        // Calling the solve method with the input integer
        solve(n);
    }

    public static void solve(int n) {
        // Calculating and printing the result based on the input integer n
        // The formula calculates (n / 3) * 2 and adds 1 if n is not divisible by 3
        System.out.println((n / 3) * 2 + (n % 3 == 0 ? 0 : 1));
    }
}
