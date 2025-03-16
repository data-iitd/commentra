
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int[] A = new int[N];
        for (int i = 0; i < N; i++) {
            A[i] = sc.nextInt() * N + i;
        }
        int cnt = 0;
        for (int i = 0; i < N; i++) {
            if ((A[i] % N) % 2 != i % 2) {
                cnt++;
            }
        }
        System.out.println(cnt / 2);
    }
}

