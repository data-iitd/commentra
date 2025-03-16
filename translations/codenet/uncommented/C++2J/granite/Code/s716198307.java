
import java.util.*;
import java.lang.*;
import java.io.*;

class s716198307 {
    public static void main (String[] args) throws java.lang.Exception {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int[] a = new int[n];
        double avg = 0;
        for(int i=0;i<n;i++){
            a[i] = in.nextInt();
            avg += a[i];
        }
        avg /= n;
        double s = Math.abs(a[0]-avg);
        int ans = 0;
        for(int i=1;i<n;i++){
            if(s>Math.abs(a[i]-avg)){
                s = Math.abs(a[i]-avg);
                ans = i;
            }
        }
        System.out.println(ans);
    }
}
