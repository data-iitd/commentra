
import java.util.*;

public class s123678341{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int X = sc.nextInt();
        int Y = sc.nextInt();
        int Z = sc.nextInt();
        int K = sc.nextInt();
        long[] A = new long[X];
        long[] B = new long[Y];
        long[] C = new long[Z];
        for (int i = 0; i < X; i++) {
            A[i] = sc.nextLong();
        }
        for (int i = 0; i < Y; i++) {
            B[i] = sc.nextLong();
        }
        for (int i = 0; i < Z; i++) {
            C[i] = sc.nextLong();
        }
        Arrays.sort(A);
        Arrays.sort(B);
        Arrays.sort(C);
        List<Long> AB = new ArrayList<>();
        for (int i = 0; i < X; i++) {
            for (int j = 0; j < Y; j++) {
                AB.add(A[X - 1 - i] + B[Y - 1 - j]);
            }
        }
        Collections.sort(AB, Collections.reverseOrder());
        List<Long> ABC = new ArrayList<>();
        for (int i = 0; i < Math.min(K, AB.size()); i++) {
            for (int j = 0; j < Z; j++) {
                ABC.add(AB.get(i) + C[Z - 1 - j]);
            }
        }
        Collections.sort(ABC, Collections.reverseOrder());
        for (int i = 0; i < K; i++) {
            System.out.println(ABC.get(i));
        }
    }
}

