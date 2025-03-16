import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String[] s1 = sc.nextLine().split(" ");
        int v1 = Integer.parseInt(s1[0]);
        int v2 = Integer.parseInt(s1[1]);
        String[] s2 = sc.nextLine().split(" ");
        int t = Integer.parseInt(s2[0]);
        int d = Integer.parseInt(s2[1]);
        int a = 1;
        int v = v1;
        int distance = 0;
        for (int i = 0; i < t; i++) {
            if (v - v2 > (t - i - 1) * d) {
                a *= -1;
                v = (t - i - 1) * d + v2;
            }
            distance += v;
            v += a * d;
        }
        System.out.println(distance);
    }
}

