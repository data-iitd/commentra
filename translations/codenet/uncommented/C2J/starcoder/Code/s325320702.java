
import java.util.*;
import java.io.*;
import java.math.*;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int l,r,d;
        l=in.nextInt();
        r=in.nextInt();
        d=in.nextInt();
        int ans=0;
        for(int i=l;i<=r;i++){
            if(i%d==0) ans++;
        }
        System.out.println(ans);
    }
}

