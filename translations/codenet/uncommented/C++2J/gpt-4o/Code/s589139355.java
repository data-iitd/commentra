import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int a = scanner.nextInt();
        int t = 0, h = 0, lt, lh, l;

        for (int i = 0; i < a; ++i) {
            String taro = scanner.next();
            String hana = scanner.next();
            lt = taro.length();
            lh = hana.length();
            l = Math.max(lt, lh);
            int tt = 0, hh = 0;

            if (taro.compareTo(hana) > 0) {
                t += 3;
            } else if (hana.compareTo(taro) > 0) {
                h += 3;
            } else if (hana.equals(taro)) {
                h += 1;
                t += 1;
            }
        }
        System.out.println(t + " " + h);
        scanner.close();
    }
}

// <END-OF-CODE>
