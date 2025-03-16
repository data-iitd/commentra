import java.io.OutputStream; 
import java.io.IOException; 
import java.io.InputStream; 
import java.io.PrintWriter; 
import java.util.Arrays; 
import java.util.Scanner; 

public class Main { 
    public static void main(String[] args) { 
        // Set up input and output streams
        InputStream inputStream = System.in; 
        OutputStream outputStream = System.out; 
        Scanner in = new Scanner(inputStream); 
        PrintWriter out = new PrintWriter(outputStream); 
        
        // Create an instance of TaskC to solve the problem
        TaskC solver = new TaskC(); 
        // Call the solve method with test number 1
        solver.solve(1, in, out); 
        
        // Close the output stream
        out.close(); 
    } 
    
    static class TaskC { 
        public void solve(int testNumber, Scanner in, PrintWriter out) { 
            // Read the number of strings
            int n = in.nextInt(); 
            // Initialize an array to count occurrences of specific starting letters
            long[] cnt = new long[5]; 
            Arrays.fill(cnt, 0); // Fill the count array with zeros
            
            // Process each string input
            for (int i = 0; i < n; ++i) { 
                String str = in.next(); 
                // Increment the count based on the first character of the string
                if (str.charAt(0) == 'M') { 
                    cnt[0]++; 
                } else if (str.charAt(0) == 'A') { 
                    cnt[1]++; 
                } else if (str.charAt(0) == 'R') { 
                    cnt[2]++; 
                } else if (str.charAt(0) == 'C') { 
                    cnt[3]++; 
                } else if (str.charAt(0) == 'H') { 
                    cnt[4]++; 
                } 
            } 
            
            // Calculate the result based on combinations of counts
            long res = cnt[0] * cnt[1] * cnt[2] + 
                       cnt[0] * cnt[1] * cnt[3] + 
                       cnt[0] * cnt[1] * cnt[4] + 
                       cnt[0] * cnt[2] * cnt[3] + 
                       cnt[0] * cnt[2] * cnt[4] + 
                       cnt[0] * cnt[3] * cnt[4] + 
                       cnt[1] * cnt[2] * cnt[3] + 
                       cnt[1] * cnt[2] * cnt[4] + 
                       cnt[1] * cnt[3] * cnt[4] + 
                       cnt[2] * cnt[3] * cnt[4]; 
            
            // Output the result
            out.println(res); 
        } 
    } 
}
