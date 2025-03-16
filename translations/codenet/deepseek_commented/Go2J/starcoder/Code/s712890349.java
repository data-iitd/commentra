
import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int K = sc.nextInt();
        String S = sc.next();
        Block[] blocks = RunLength(S);
        int sum = 0, zero = 0, l = 0;
        for (int r = 0; r < blocks.length; r++) {
            sum += blocks[r].len;
            if (blocks[r].value.equals("0")) {
                zero++;
            }
            for (int k = K; k < zero; k++) {
                sum -= blocks[l].len;
                if (blocks[l].value.equals("0")) {
                    zero--;
                }
                l++;
            }
            System.out.println(Math.max(ans, sum));
        }
    }

    // RunLength performs run-length encoding on the input string
    public static Block[] RunLength(String s) {
        Block[] r = new Block[0];
        if (s.length() == 0) {
            return r;
        }
        Block t = new Block(s.charAt(0), 1);
        for (int i = 1; i < s.length(); i++) {
            if (t.value.equals(s.charAt(i))) {
                t.len++;
            } else {
                r = append(r, t);
                t = new Block(s.charAt(i), 1);
            }
        }
        r = append(r, t);
        return r;
    }

    // Block represents a run-length encoded block of characters
    public static class Block {
        public String value;
        public int len;

        public Block(char value, int len) {
            this.value = String.valueOf(value);
            this.len = len;
        }
    }

    // append appends a block to a slice of blocks
    public static Block[] append(Block[] blocks, Block block) {
        Block[] r = new Block[blocks.length + 1];
        for (int i = 0; i < blocks.length; i++) {
            r[i] = blocks[i];
        }
        r[blocks.length] = block;
        return r;
    }
}

