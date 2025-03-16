
package main;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayDeque;
import java.util.Deque;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter w = new BufferedWriter(new OutputStreamWriter(System.out));

        String S = r.readLine();
        int Q = Integer.parseInt(r.readLine());
        int[] sum = new int[Q + 1];
        for (int i = Q - 1; i >= 1; i--) {
            if (r.readLine().equals("1")) {
                sum[i - 1] = sum[i] + 1;
            } else {
                sum[i - 1] = sum[i];
            }
        }
        if (sum[0] % 2 == 1) {
            S = new StringBuilder(S).reverse().toString();
        }
        Deque<Character> deq = new ArrayDeque<>();
        for (int i = 0; i < Q; i++) {
            String[] s = r.readLine().split(" ");
            if (s[0].equals("1")) {
                if (sum[i] % 2 == 1) {
                    deq.addFirst(s[1].charAt(0));
                } else {
                    deq.addLast(s[1].charAt(0));
                }
            } else {
                if (s[1].equals("1")) {
                    if (sum[i] % 2 == 1) {
                        deq.addLast(s[2].charAt(0));
                    } else {
                        deq.addFirst(s[2].charAt(0));
                    }
                } else {
                    if (sum[i] % 2 == 1) {
                        deq.addFirst(s[2].charAt(0));
                    } else {
                        deq.addLast(s[2].charAt(0));
                    }
                }
            }
        }
        for (int i = S.length() - 1; i >= 0; i--) {
            w.write(S.charAt(i));
        }
        for (Character c : deq) {
            w.write(c);
        }
        w.write("\n");
        w.flush();
    }
}

