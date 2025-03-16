
package main;

import java.util.Scanner;

class Block {
    String value;
    int len;

    public Block(String value, int len) {
        this.value = value;
        this.len = len;
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int K = sc.nextInt();
        String S = sc.next();
        Block[] blocks = runLength(S);
        int sum = 0, zero = 0, l = 0;
        for (int r = 0; r < blocks.length; r++) {
            sum += blocks[r].len;
            if (blocks[r].value.equals("0")) {
                zero++;
            }
            while (K < zero) {
                sum -= blocks[l].len;
                if (blocks[l].value.equals("0")) {
                    zero--;
                }
                l++;
            }
            if (sum > sum) {
                sum = sum;
            }
        }
        System.out.println(sum);
    }

    public static Block[] runLength(String s) {
        Block[] r = new Block[0];
        if (s.length() == 0) {
            return r;
        }
        Block t = new Block(s.substring(0, 1), 1);
        for (int i = 1; i < s.length(); i++) {
            if (t.value.equals(s.substring(i, i + 1))) {
                t.len++;
            } else {
                r = append(r, t);
                t = new Block(s.substring(i, i + 1), 1);
            }
        }
        r = append(r, t);
        return r;
    }

    public static Block[] append(Block[] r, Block t) {
        Block[] r2 = new Block[r.length + 1];
        for (int i = 0; i < r.length; i++) {
            r2[i] = r[i];
        }
        r2[r.length] = t;
        return r2;
    }

    public static int max(int a, int b) {
        if (b > a) {
            return b;
        }
        return a;
    }
}

