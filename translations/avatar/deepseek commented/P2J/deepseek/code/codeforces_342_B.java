import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        int s = scanner.nextInt();
        int f = scanner.nextInt();

        // Determine the direction and character based on the starting and finishing points
        int d = s < f ? 1 : -1;
        char c = d == 1 ? 'R' : 'L';

        StringBuilder res = new StringBuilder();
        int i = 1;
        int j = s;
        int t, l, r;
        int k = 1;

        // Loop until the current position reaches the finishing point
        while (j != f) {
            if (i > t && k < m) {
                t = scanner.nextInt();
                l = scanner.nextInt();
                r = scanner.nextInt();
                k++;
            }

            if (i == t && (l <= j && j <= r || l <= j + d && j + d <= r)) {
                res.append('X');
            } else {
                res.append(c);
                j += d;
            }
            i++;
        }

        System.out.println(res.toString());
    }
}

