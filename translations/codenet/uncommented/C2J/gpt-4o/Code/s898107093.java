import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n, taro = 0, hanako = 0;
        n = scanner.nextInt();
        String[] t = new String[n];
        String[] h = new String[n];

        for (int i = 0; i < n; i++) {
            t[i] = scanner.next();
            h[i] = scanner.next();
            if (t[i].compareTo(h[i]) < 0) {
                hanako += 3;
            }
            if (t[i].compareTo(h[i]) > 0) {
                taro += 3;
            }
            if (t[i].compareTo(h[i]) == 0) {
                taro += 1;
                hanako += 1;
            }
        }
        System.out.println(taro + " " + hanako);
        scanner.close();
    }
}

// <END-OF-CODE>
