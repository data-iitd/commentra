
package com.company;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String S = sc.next();
        if (S.startsWith("YAKI")) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
    }

    public static class Scanner {
        BufferedReader br;
        StringTokenizer st;

        public Scanner(InputStreamReader isr) {
            br = new BufferedReader(isr);
        }

        public String next() {
            while (st == null || !st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public int[] nextIntArray() {
            String[] strArr = next().split(" ");
            int[] intArr = new int[strArr.length];
            for (int i = 0; i < strArr.length; i++) {
                intArr[i] = Integer.parseInt(strArr[i]);
            }
            return intArr;
        }
    }
}

