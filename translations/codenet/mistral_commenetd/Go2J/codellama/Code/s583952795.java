
package main;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        String[] input = reader.readLine().split(" ");
        int N = Integer.parseInt(input[0]);
        int K = Integer.parseInt(input[1]);

        String s = tenToN(N, K);

        System.out.println(s.length());
    }

    public static String tenToN(int number, int n) {
        String s = "";
        int tmp = number;

        while (tmp >= n) {
            s = tmp % n + s;
            tmp /= n;
        }

        return s;
    }
}

