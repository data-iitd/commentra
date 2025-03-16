import java.util.*;
import java.io.*;
public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int[] ans = new int[n];
        for(int i=0;i<n-1;i++){
            int a = in.nextInt();
            a--;
            ans[a]++;
        }
        for(int i=0;i<n;i++) System.out.println(ans[i]);
    }
}

