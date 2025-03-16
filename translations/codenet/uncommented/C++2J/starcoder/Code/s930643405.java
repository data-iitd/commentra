
import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int k = in.nextInt();
        boolean[] d = new boolean[10];
        for(int i=0;i<k;++i){
            int a = in.nextInt();
            d[a] = true;
        }
        while(true){
            int x = n;
            boolean hantei = true;
            while(x>0){
                if(d[x%10]){
                    hantei = false;
                    break;
                }
                x /= 10;
            }
            if(hantei){
                System.out.println(n);
                break;
            }
            n++;
        }
    }
}

