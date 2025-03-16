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
        int total = 0;
        for (int i = 0; i < N; i++) {
            total ^= a[i];
        }
        System.out.println(Arrays.stream(a).mapToObj(i -> Integer.toString(i ^ total)).collect(Collectors.joining(" ")));
    }
}
