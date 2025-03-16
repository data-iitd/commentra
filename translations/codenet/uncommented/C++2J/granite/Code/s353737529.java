
/*
これを入れて実行
javac code.java
java code
 */

import java.util.*;
import java.io.*;

class s353737529 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        if (n == 0) {
            System.out.println(0);
            return;
        }
        StringBuilder sb = new StringBuilder();
        while (n!= 0) {
            if (n % 2 == 0) {
                sb.append(0);
            } else {
                sb.append(1);
            }
            n -= Math.abs(n % 2);
            n /= -2;
        }
        System.out.println(sb.reverse().toString());
    }
}

