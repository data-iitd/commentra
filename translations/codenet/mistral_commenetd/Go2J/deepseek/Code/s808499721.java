import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int x = scanner.nextInt();
        int ans = 0;

        if (x >= 400 && x <= 599) {
            ans = 8;
        } else if (x >= 600 && x <= 799) {
            ans = 7;
        } else if (x >= 800 && x <= 999) {
            ans = 6;
        } else if (x >= 1000 && x <= 1199) {
            ans = 5;
        } else if (x >= 1200 && x <= 1399) {
            ans = 4;
        } else if (x >= 1400 && x <= 1599) {
            ans = 3;
        } else if (x >= 1600 && x <= 1799) {
            ans = 2;
        } else if (x >= 1800 && x <= 9999) {
            ans = 1;
        }

        System.out.println(ans);
    }
}
