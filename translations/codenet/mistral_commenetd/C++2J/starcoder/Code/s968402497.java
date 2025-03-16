import java.util.*;
import java.io.*;
import java.math.*;

public class Main {
    public static void main(String[] args) {
        // Read input
        Scanner sc=new Scanner(System.in);
        int tc=sc.nextInt();
        int n=sc.nextInt();
        int m=sc.nextInt();
        // Check if 'n' is greater than'm' and swap them if necessary
        if(n>m) swap(n,m);
        // Iterate through each possible value of 'i' from 1 to'm'
        for(int i=1;i<=m;i++){
            // Check if 'i' multiplied by 'tc' is within the range of 'n' to'm'
            if(i*tc>=n&&i*tc<=m){
                // If so, print "OK" and break out of the loop since we have found the answer
                System.out.println("OK");
                break;
            }
        }
        // If the loop has not been broken out of, print "NG"
        if(i>m) System.out.println("NG");
    }
}

