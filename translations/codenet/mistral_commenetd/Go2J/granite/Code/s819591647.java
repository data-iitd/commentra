
//problem_b.java
// This is the main file for problem B solution

import java.util.*;
import java.io.*;

public class s819591647{

    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        PrintWriter wr = new PrintWriter(System.out);

        int n = sc.nextInt();
        int m = sc.nextInt();
        int[] a = new int[n];
        int sum = 0;
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
            sum += a[i];
        }

        int count = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] >= (sum / (4 * m))) {
                count++;
            }
        }

        if (count >= m) {
            wr.println("Yes");
        } else {
            wr.println("No");
        }

        wr.flush();
    }
}

