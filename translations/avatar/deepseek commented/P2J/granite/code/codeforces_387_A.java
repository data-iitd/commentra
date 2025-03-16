

import java.util.Scanner;

public class codeforces_387_A{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String[] time1 = scanner.nextLine().split(":");
        String[] time2 = scanner.nextLine().split(":");
        int h1 = Integer.parseInt(time1[0]);
        int m1 = Integer.parseInt(time1[1]);
        int h2 = Integer.parseInt(time2[0]);
        int m2 = Integer.parseInt(time2[1]);
        m1 += h1 * 60;
        m2 += h2 * 60;
        int m2_total = m1 - m2;
        m2_total %= 1440;
        System.out.printf("%02d:%02d", m2_total / 60, m2_total % 60);
    }
}

