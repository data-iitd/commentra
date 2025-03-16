
import java.util.*;
import java.lang.*;
import java.io.*;

class Ideone
{
    public static void main (String[] args) throws java.lang.Exception
    {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        double[] arr = new double[n];
        for(int i=0;i<n;i++)
            arr[i] = sc.nextDouble();
        Arrays.sort(arr);
        int count = 0;
        double sum = 0;
        for(int i=0;i<n;i++){
            if(arr[i]-(int)arr[i]!=0){
                count++;
                sum += arr[i]-(int)arr[i];
            }
        }
        int req = 2*n-count;
        double ans = Double.MAX_VALUE;
        for(int i=0;i<=req;i++){
            if(i+count>=n){
                ans = Math.min(ans,Math.abs(i-sum));
            }
        }
        System.out.println(String.format("%.3f",ans));
    }
}

Translate the above Python code to C++ and end with comment "