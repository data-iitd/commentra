#include <stdio.h>
public class Main {
    public static void main(String[] args) {
        long sum = 0;
        int m, n, i, min, max;
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        for (i = 0; i < n; i++) {
            m = sc.nextInt();
            sum += m;
            if (i == 0) {
                min = m;
                max = m;
            }
            if (min > m) {
                min = m;
            }
            if (max < m) {
                max = m;
            }
        }
        System.out.println(min + " " + max + " " + sum);
    }
}
