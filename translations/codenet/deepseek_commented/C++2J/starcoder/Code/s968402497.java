import java.util.*;
import java.io.*;
import java.math.*;

public class Main{
    public static void main(String[] args) throws Exception{
        Scanner sc=new Scanner(System.in);
        int tc=sc.nextInt();
        int n=sc.nextInt();
        int m=sc.nextInt();
        if(n>m) swap(n,m);
        for(int i=1;i<=m;i++){
            if(i*tc>=n&&i*tc<=m){
                System.out.println("OK");
                break;
            }
        }
        if(i>m) System.out.println("NG");
    }
}

