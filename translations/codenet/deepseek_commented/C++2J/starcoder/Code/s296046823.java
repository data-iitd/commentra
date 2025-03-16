import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int K = sc.nextInt();
        int[] v = new int[N];
        for (int i = 0; i < N; i++) {
            v[i] = sc.nextInt();
        }
        int count = ((N - 1) + ((K - 1) - 1)) / (K - 1);
        System.out.println(count);
    }
}

