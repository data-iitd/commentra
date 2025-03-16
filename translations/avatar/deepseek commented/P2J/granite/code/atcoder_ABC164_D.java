

import java.util.Scanner;

public class atcoder_ABC164_D{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.nextLine();
        int l = 2019;
        int[] m = new int[l];
        m[0] = 1;
        int a = 0, r = 0;
        for (int i = s.length() - 1; i >= 0; i--) {
            a = (a + s.charAt(i) * (int) Math.pow(10, s.length() - 1 - i)) % l;
            r += m[a];
            m[a]++;
        }
        System.out.println(r);
    }
}

Translate the above Python code to JavaScript and end with comment "