
package main;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        System.out.println(solution(n, m));
    }

    public static int solution(int n, int m) {
        n = n - 2;
        m = m - 2;
        if (n < 0) {
            n = 1;
        }
        if (m < 0) {
            m = 1;
        }
        return n * m;
    }
}

