
import java.util.*;
import java.io.*;

class s970719454 {
    public static void main(String[] args) throws IOException {
        // Infinite loop to continuously process input until a termination condition is met
        while(true){
            int n = Integer.parseInt(br.readLine());
            if(n == 0) break;
            
            // Initialize arrays to zero for the current test case
            int[] here = new int[100001];
            int[] dp1 = new int[100001];
            int[] dp2 = new int[100001];
            boolean dpflg = false;
            
            // Read m numbers and mark their presence
            String[] str = br.readLine().split(" ");
            for(String s : str){
                int a = Integer.parseInt(s);
                if(a == 0) dpflg = true;
                here[a] = 1;
            }
            
            // Variables to track the maximum lengths of sequences
            int maxi1 = 0;
            int maxi2 = 0;
            
            // Calculate the longest sequence of present numbers without a zero
            for(int i = 1; i <= n; i++){
                if(here[i] == 1) dp1[i] = dp1[i - 1] + 1; // Increment if present
                maxi1 = Math.max(dp1[i], maxi1); // Update maximum length
            }
            
            // Calculate the longest sequence of present numbers considering the presence of a zero
            for(int i = 1; i <= n; i++){
                if(here[i] == 1) dp2[i] = dp2[i - 1] + 1; // Increment if present
                else dp2[i] = dp1[i - 1] + 1; // Reset if zero is encountered
                maxi2 = Math.max(dp2[i], maxi2); // Update maximum length
            }
            
            // Output the result based on whether a zero was encountered
            if(!dpflg){
                System.out.println(maxi1); // Print the maximum length without zero
            } else {
                System.out.println(maxi2); // Print the maximum length considering zero
            }
        }
    }
}

