import java.util.*;
import java.io.*;
import java.math.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        int q = Integer.parseInt(st.nextToken());
        int h = Integer.parseInt(st.nextToken());
        int s = Integer.parseInt(st.nextToken());
        int d = Integer.parseInt(st.nextToken());
        int n = Integer.parseInt(br.readLine());
        
        // Calculating the best price for single liters
        int best1L = Math.min(q * 4, Math.min(h * 2, s));
        
        // Calculating the best price for double liters
        int best2L = Math.min(d, best1L * 2);
        
        // Checking if the quantity n is even or odd and printing the total cost accordingly
        if (n % 2 == 0) {
            System.out.println(best2L * (n / 2));
        } else {
            System.out.println(best2L * (n / 2) + best1L);
        }
    }
}
