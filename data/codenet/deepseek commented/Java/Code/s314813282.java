
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        // Create a Scanner object to read input from the user
        Scanner scan = new Scanner(System.in);
        
        // Read four integers from the user: m, n, x, and y
        int m = scan.nextInt();
        int n = scan.nextInt();
        int x = scan.nextInt();
        int y = scan.nextInt();
        
        // Read m elements into array a
        int[] a = new int[m];
        for(int i=0; i<a.length; i++) {
            a[i] = scan.nextInt();
        }
        
        // Read n elements into array b
        int[] b = new int[n];
        for(int i=0; i<b.length; i++) {
            b[i] = scan.nextInt();
        }
        
        // Find the maximum value in array a
        int x_max = MaxInt(x, a);
        
        // Find the minimum value in array b
        int y_min = MinInt(y, b);
        
        // Check if there is a war based on the values found
        CheckWar(x_max, y_min);
    }
    
    // Helper method to find the maximum value in an array compared to a given number
    static int MaxInt(int x, int[] a) {
        int bignum = x;
        for(int i = 0; i < a.length; i++) {
            bignum = Math.max(bignum, a[i]);
        }
        return bignum;
    }
    
    // Helper method to find the minimum value in an array compared to a given number
    static int MinInt(int y, int[] b) {
        int smallnum = y;
        for(int i = 0; i < b.length; i++) {
            smallnum = Math.min(smallnum, b[i]);
        }
        return smallnum;
    }
    
    // Method to check if there is a war based on the maximum value in array a and the minimum value in array b
    static void CheckWar(int a, int b) {
        if(a >= b) {
            System.out.println("War");
        } else {
            System.out.println("No War");
        }
    }
}

