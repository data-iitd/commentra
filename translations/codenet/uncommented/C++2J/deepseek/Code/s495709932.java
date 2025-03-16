import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        List<Long> A = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            A.add(scanner.nextLong());
        }

        long answer = 0;
        for (int i = 0; i < N - 1; i++) {
            for (int j = i + 1; j < N; j++) {
                long diff = Math.abs(A.get(i) - A.get(j));
                answer = Math.max(answer, diff);
            }
        }
        System.out.println(answer);
    }
}
