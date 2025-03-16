import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int X = scanner.nextInt();
        int Y = scanner.nextInt();
        int Z = scanner.nextInt();
        int K = scanner.nextInt();

        List<Long> A = new ArrayList<>();
        List<Long> B = new ArrayList<>();
        List<Long> C = new ArrayList<>();

        for (int i = 0; i < X; i++) {
            A.add(scanner.nextLong());
        }
        for (int i = 0; i < Y; i++) {
            B.add(scanner.nextLong());
        }
        for (int i = 0; i < Z; i++) {
            C.add(scanner.nextLong());
        }

        Collections.sort(A, Collections.reverseOrder());
        Collections.sort(B, Collections.reverseOrder());
        Collections.sort(C, Collections.reverseOrder());

        List<Long> AB = new ArrayList<>();
        for (int i = 0; i < X; i++) {
            for (int j = 0; j < Y; j++) {
                AB.add(A.get(i) + B.get(j));
            }
        }

        Collections.sort(AB, Collections.reverseOrder());

        List<Long> ABC = new ArrayList<>();
        for (int i = 0; i < Math.min(K, AB.size()); i++) {
            for (int j = 0; j < Z; j++) {
                ABC.add(AB.get(i) + C.get(j));
            }
        }

        Collections.sort(ABC, Collections.reverseOrder());

        for (int i = 0; i < K; i++) {
            System.out.println(ABC.get(i));
        }
    }
}
