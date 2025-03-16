import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        List<Long> A = new ArrayList<>();
        for (int i = 0; i < N; ++i) {
            A.add(scanner.nextLong());
        }
        Collections.sort(A, Collections.reverseOrder());
        long max = Long.MAX_VALUE;
        int index = -1;
        for (int i = 1; i < N; ++i) {
            long diff = Math.abs(A.get(0) - 2 * A.get(i));
            if (diff < max) {
                max = diff;
                index = i;
            }
        }
        System.out.println(A.get(0) + " " + A.get(index));
    }
}

