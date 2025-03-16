import java.util.Scanner;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }
        int total = IntStream.of(a).reduce(0, (x, y) -> x ^ y);
        for (int i = 0; i < n; i++) {
            System.out.print(a[i] ^ total + " ");
        }
        sc.close();
    }
}

