import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = Integer.parseInt(scanner.nextLine());
        int[] A = Arrays.stream(scanner.nextLine().split(" "))
                        .mapToInt(Integer::parseInt)
                        .toArray();
        
        int mn = N + 1, mx = -1;
        for (int i = 0; i < N; i++) {
            if (i + 1 != A[i]) {
                mn = Math.min(mn, i);
                mx = Math.max(mx, i);
            }
        }
        
        if (mx == -1) {
            System.out.println("0 0");
        } else {
            int[] newA = new int[N];
            System.arraycopy(A, 0, newA, 0, mn);
            for (int i = 0; i <= mx - mn; i++) {
                newA[mn + i] = A[mx - i];
            }
            System.arraycopy(A, mx + 1, newA, mx + 1, N - (mx + 1));
            
            if (isSorted(newA)) {
                System.out.println((mn + 1) + " " + (mx + 1));
            } else {
                System.out.println("0 0");
            }
        }
    }

    private static boolean isSorted(int[] array) {
        for (int i = 1; i < array.length; i++) {
            if (array[i] < array[i - 1]) {
                return false;
            }
        }
        return true;
    }
}
//<END-OF-CODE>
