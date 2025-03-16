import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        String[] t = new String[n];
        String[] h = new String[n];
        int taro = 0, hanako = 0;

        for (int i = 0; i < n; i++) {
            t[i] = scanner.next();
            h[i] = scanner.next();

            int comparison = t[i].compareTo(h[i]);
            if (comparison < 0) {
                hanako += 3;
            } else if (comparison > 0) {
                taro += 3;
            } else {
                taro += 1;
                hanako += 1;
            }
        }

        System.out.println(taro + " " + hanako);
    }
}
