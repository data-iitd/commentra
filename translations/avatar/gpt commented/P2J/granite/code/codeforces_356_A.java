
import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class codeforces_356_A{

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int m = in.nextInt();
        int[] out = new int[n];
        int[] comp = new int[n];
        for(int comp_i=0; comp_i < n; comp_i++){
            comp[comp_i] = comp_i+2;
        }
        for(int a0 = 0; a0 < m; a0++){
            int l = in.nextInt();
            int r = in.nextInt();
            int x = in.nextInt();
            int t = l;
            while(t <= r){
                int next_val = comp[t-1];
                if(out[t-1] == 0 && t!= x){
                    out[t-1] = x;
                }
                comp[t-1] = r+1;
                if(t >= x){
                    comp[t-1] = x;
                }
                t = next_val;
            }
        }
        for(int i = 0; i < n; i++){
            System.out.print(out[i] + (i!= n-1? " " : "\n"));
        }
    }
}
