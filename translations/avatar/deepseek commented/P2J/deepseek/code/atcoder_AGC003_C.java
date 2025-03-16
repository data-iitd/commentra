import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        ArrayList<Integer> A = new ArrayList<>();

        for (int i = 0; i < N; i++) {
            int input = scanner.nextInt();
            A.add(input * N + i);
        }

        Collections.sort(A);

        int cnt = 0;

        for (int i = 0; i < N; i++) {
            int d = (A.get(i) % N) % 2;
            if (d % 2 != i % 2) {
                cnt++;
            }
        }

        System.out.println(cnt / 2);
    }
}

