
import java.util.*;
import java.lang.*;
import java.io.*;

class Main {
    public static void main (String[] args) {
        // Initialize answer to 0
        long ans = 0;
        
        // Read input for number of nodes n
        int n = Integer.parseInt(args[0]);
        
        // Calculate contribution of each node to the answer
        for (int i=1;i<=n;i++) {
            // Contribution of i-th node is i * (n-i+1)
            ans += i * (n-i+1);
        }
        
        // Subtract contribution of edges
        for (int i=1;i<n;i++) {
            // Read input for two nodes u and v
            int u = Integer.parseInt(args[i*2-1]);
            int v = Integer.parseInt(args[i*2]);
            
            // Find maximum and minimum of u and v
            int a = Math.max(u,v);
            int b = Math.min(u,v);
            
            // Subtract contribution of edge (u,v) from the answer
            ans -= b * (n-a+1);
        }
        
        // Print the answer
        System.out.println(ans);
    }
}

