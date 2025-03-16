
package main;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        double n = scanner.nextDouble();
        double k = scanner.nextDouble();

        // n を k進数にした時に何桁になるか？
        //ex : 10 を 2進数 = 2^3 + 2^1 = 1010 => 4桁
        //桁数は最上位の位で決まる。この場合2^3 <= 10 < 2^4 であるため 4になった
        //抽象化すると k^x <= n < k^(x+1) を満たすxを見つけ x+1を出力する

        double x = 0.0;
        while (true) {
            double under = Math.pow(k, x);
            double upper = Math.pow(k, x + 1);

            if (under <= n && n < upper) {
                System.out.println(x + 1);
                return;
            }
            x++;
        }
    }
}

