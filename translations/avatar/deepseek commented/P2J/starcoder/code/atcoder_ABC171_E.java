import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int[] a = new int[N];
        for (int i = 0; i < N; i++) {
            a[i] = sc.nextInt();
        }
        int total = Arrays.stream(a).reduce(0, (x, y) -> x ^ y);
        System.out.println(Arrays.stream(a).mapToObj(x -> x ^ total).collect(Collectors.joining(" ")));
    }
}

