
import java.util.*;
import java.io.*;

public class atcoder_ABC171_E{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        String[] input = br.readLine().split(" ");
        int[] a = new int[N];
        for (int i = 0; i < N; i++) {
            a[i] = Integer.parseInt(input[i]);
        }
        int total = 0;
        for (int i = 0; i < N; i++) {
            total ^= a[i];
        }
        for (int i = 0; i < N; i++) {
            System.out.print((a[i] ^ total) + " ");
        }
        System.out.println();
    }
}

Translate the above Java code to C++ and end with comment "