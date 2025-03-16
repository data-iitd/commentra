import java.util.Scanner;
import java.util.Arrays;
import java.util.stream.Collectors;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }
        int total = Arrays.stream(a).reduce(0, (x, y) -> x ^ y);
        String result = Arrays.stream(a).mapToObj(x -> String.valueOf(x ^ total)).collect(Collectors.joining(" "));
        System.out.println(result);
    }
}

