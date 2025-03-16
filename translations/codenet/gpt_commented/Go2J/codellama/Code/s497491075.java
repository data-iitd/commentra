
import java.io.*;
import java.util.*;

public class Solution {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int D = sc.nextInt();
        int count = 0;
        for (int i = 0; i < N; i++) {
            int x = sc.nextInt();
            int y = sc.nextInt();
            double d = Math.sqrt(x * x + y * y);
            if (d <= D) {
                count++;
            }
        }
        System.out.println(count);
    }
}

