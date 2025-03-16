
import java.util.*;
import java.io.*;

class s343280137 {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        int n = Integer.parseInt(input[0]);
        int c = Integer.parseInt(input[1]);
        int[] x = new int[n+1];
        int[] v = new int[n+1];
        for(int i = 1; i < n+1; i++){
            input = br.readLine().split(" ");
            x[i] = Integer.parseInt(input[0]);
            v[i] = Integer.parseInt(input[1]);
        }
        long[] lefttotal = new long[n+1];
        long[] maxlefttotal = new long[n+1];
        for(int i = 1; i < n+1; i++){
            lefttotal[i] = lefttotal[i-1] + v[i];
            maxlefttotal[i] = Math.max(maxlefttotal[i-1],lefttotal[i]-x[i]);
        }
        long[] righttotal = new long[n+1];
        long[] maxrighttotal = new long[n+1];
        for(int i = 1; i < n+1; i++){
            righttotal[i] = righttotal[i-1] + v[n-i+1];
            maxrighttotal[i] = Math.max(maxrighttotal[i-1],righttotal[i] -(c - x[n+1-i]));
        }
        long ans = 0;
        for(int i = 1; i < n+1; i++){
            ans = Math.max(ans,lefttotal[i]-x[i]);
            ans = Math.max(ans,lefttotal[i]-2*x[i]+maxrighttotal[n-i]);
            ans = Math.max(ans,righttotal[i]-(c -x[n+1-i]));
            ans = Math.max(ans,righttotal[i]-2*(c-x[n+1-i])+maxlefttotal[n-i]);
        }
        System.out.println(ans);
    }
}
