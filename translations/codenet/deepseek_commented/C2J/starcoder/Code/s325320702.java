import java.util.*;
import java.io.*;
import java.math.*;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        long l = in.nextLong();
        long r = in.nextLong();
        long d = in.nextLong();
        long ans = 0;
        for(long i=l;i<=r;i++){
            if(i%d==0) ans++;
        }
        System.out.println(ans);
    }
}

