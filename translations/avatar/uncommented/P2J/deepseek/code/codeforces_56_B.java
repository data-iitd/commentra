import java.util.Scanner;
import java.util.ArrayList;
import java.util.Collections;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        ArrayList<Integer> A = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            A.add(scanner.nextInt());
        }
        
        int mn = N + 1, mx = -1;
        for (int i = 0; i < N; i++) {
            if (i + 1 != A.get(i)) {
                mn = Math.min(mn, i);
                mx = Math.max(mx, i);
            }
        }
        
        if (mx == -1) {
            System.out.println("0 0");
        } else {
            Collections.reverse(A.subList(mn, mx + 1));
            if (isSorted(A)) {
                System.out.println((mn + 1) + " " + (mx + 1));
            } else {
                System.out.println("0 0");
            }
        }
    }
    
    public static boolean isSorted(ArrayList<Integer> A) {
        ArrayList<Integer> sortedA = new ArrayList<>(A);
        Collections.sort(sortedA);
        return sortedA.equals(A);
    }
}
