
import java.io.*;
import java.util.*;

public class atcoder_ARC086_B{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        String[] input = br.readLine().split(" ");
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = Integer.parseInt(input[i]);
        }

        int maxVal = 0;
        int maxIndex = -1;
        int maxSign = 0;
        for (int i = 0; i < n; i++) {
            int absVal = Math.abs(a[i]);
            if (absVal > maxVal) {
                maxVal = absVal;
                maxIndex = i;
                maxSign = a[i] < 0? -1 : a[i] > 0? 1 : 0;
            }
        }

        if (maxSign == 0) {
            System.out.println(0);
        } else {
            System.out.println(2 * n - 1);
            for (int i = 0; i < n; i++) {
                System.out.println((maxIndex + 1) + " " + (i + 1));
            }
            if (maxSign == -1) {
                for (int i = n - 1; i > 0; i--) {
                    System.out.println(i + " " + (i - 1));
                }
            } else {
                for (int i = 1; i < n; i++) {
                    System.out.println(i + " " + (i - 1));
                }
            }
        }
    }
}

Translate the above Java code to C++ and end with comment "