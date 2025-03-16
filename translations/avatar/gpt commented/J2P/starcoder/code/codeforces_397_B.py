import java.io.*; 
import java.util.*; 

public class Main { 
    public static void main(String[] args) { 
        Scanner in = new Scanner(System.in); 
        PrintWriter out = new PrintWriter(System.out); 
        
        int t = in.nextInt(); 
        while (t-- > 0) { 
            long n = in.nextLong(); 
            long a = in.nextLong(); 
            long b = in.nextLong(); 
            
            if (n < a) { 
                out.println("No"); 
                continue; 
            } 
            
            if (a == b) { 
                if (n % a == 0) { 
                    out.println("Yes"); 
                } else { 
                    out.println("No"); 
                } 
                continue; 
            } 
            
            long x = b / (b - a); 
            if (n > x * a) { 
                out.println("Yes"); 
                continue; 
            } 
            
            long low = 1; 
            long high = x + 1; 
            long ans = 1; 
            while (low <= high) { 
                long mid = (low + high) / 2; 
                if (mid * a < n) { 
                    low = mid + 1; 
                } else { 
                    ans = mid; 
                    high = mid - 1; 
                } 
            } 
            
            if (n > (ans - 1) * b && n < ans * a) { 
                out.println("No"); 
            } else { 
                out.println("Yes"); 
            } 
        } 
        
        out.close(); 
    } 
}

