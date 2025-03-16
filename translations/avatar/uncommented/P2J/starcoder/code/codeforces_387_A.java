import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int h1 = sc.nextInt();
        int m1 = sc.nextInt();
        int h2 = sc.nextInt();
        int m2 = sc.nextInt();
        int m = (h1 * 60 + m1) - (h2 * 60 + m2);
        m = m % 1440;
        System.out.printf("%02d:%02d", m / 60, m % 60);
    }
}
