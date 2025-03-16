
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int h1 = sc.nextInt();
        int m1 = sc.nextInt();
        int h2 = sc.nextInt();
        int m2 = sc.nextInt();
        int m2_ = (h2 * 60 + m2) - (h1 * 60 + m1);
        if (m2_ < 0) {
            m2_ += 1440;
        }
        System.out.printf("%02d:%02d", m2_ / 60, m2_ % 60);
    }
}

