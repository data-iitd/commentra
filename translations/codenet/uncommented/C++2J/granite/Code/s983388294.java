
import java.util.*;
import java.io.*;

public class s983388294{
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        String[] input = br.readLine().split(" ");
        int[] a = new int[n];
        for(int i=0; i<n; i++) {
            a[i] = Integer.parseInt(input[i]);
        }
        int curr = 0;
        for(int i=0; i<n; i++) {
            if(a[i]==curr+1) curr++;
        }
        if(curr>0) {
            System.out.println(n-curr);
        }
        else {
            System.out.println(-1);
        }
    }
}

