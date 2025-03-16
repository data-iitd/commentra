import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n, tmp;
        long min = 1000000, max = -1000000, sum = 0;

        n = scanner.nextInt();

        for (int i = 0; i < n; i++) {
            tmp = scanner.nextInt();
            if (min > tmp) min = tmp;
            if (max < tmp) max = tmp;
            sum += tmp;
        }

        System.out.printf("%d %d %d\n", min, max, sum);
        scanner.close();
    }
}

// <END-OF-CODE>
