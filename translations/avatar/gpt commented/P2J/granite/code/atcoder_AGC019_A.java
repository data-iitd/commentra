
import java.util.*;
import java.io.*;

public class atcoder_AGC019_A{
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        int q = Integer.parseInt(input[0]);
        int h = Integer.parseInt(input[1]);
        int s = Integer.parseInt(input[2]);
        int d = Integer.parseInt(input[3]);
        int n = Integer.parseInt(br.readLine());
        int oneLiterCost = Math.min(q * 4, Math.min(h * 2, s));
        int twoLiterCost = Math.min(d, oneLiterCost * 2);
        int totalCost = 0;
        if (n % 2 == 0) {
            totalCost = twoLiterCost * (n / 2);
        } else {
            totalCost = twoLiterCost * (n / 2) + oneLiterCost;
        }
        System.out.println(totalCost);
    }
}

Translate the above Java code to C++ and end with comment "