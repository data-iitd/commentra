import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int[] a = new int[n+1];
        int[] q = new int[n+1];
        int tot = 0;
        for(int i=1; i<=n; i++) a[i] = in.nextInt();
        Arrays.sort(a);
        for(int i=1; i<=n; i++) {
            if (a[i]==a[i+1]) q[++tot] = a[i];
            i++;
        }
        System.out.println(q[tot]*q[tot-1]);
    }
}

