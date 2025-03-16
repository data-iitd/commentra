import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int w = scanner.nextInt();
        int m = scanner.nextInt();
        int k = scanner.nextInt();
        
        long lo = 0;
        long hi = (long) 1e18;
        
        while (hi - lo > 1) {
            long md = (lo + hi) / 2;
            long c = sum(m + md - 1) - sum(m - 1);
            
            if (c * k <= w) {
                lo = md;
            } else {
                hi = md;
            }
        }
        
        System.out.println(lo);
    }
    
    public static long sum(long k) {
        long ret = 0;
        long pw = 10;
        int length = 1;
        
        while (true) {
            long cur = Math.min(pw - 1, k);
            long prev = pw / 10;
            
            ret += (cur - prev + 1) * length;
            
            if (pw - 1 >= k) {
                break;
            }
            
            length++;
            pw *= 10;
        }
        
        return ret;
    }
}
