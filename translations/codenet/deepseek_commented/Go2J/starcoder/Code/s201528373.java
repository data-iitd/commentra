
import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int x = in.nextInt();
        int[] l = new int[n];
        for(int i = 0; i < n; i++) {
            l[i] = in.nextInt();
        }
        int tmpSum = 0;
        int rs = 0;
        for(int i = 0; i < n; i++) {
            tmpSum += l[i];
            if(tmpSum <= x) {
                rs = i + 2;
            } else if(tmpSum > x) {
                break;
            }
        }
        System.out.println(rs);
    }
}

