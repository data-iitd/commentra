import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int[] v = new int[N];

        for (int i = 1; i < N; i++) {
            int a = scanner.nextInt();
            v[a - 1]++;
        }

        for (int e : v) {
            System.out.println(e);
        }
    }
}

