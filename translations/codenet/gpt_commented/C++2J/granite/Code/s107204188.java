
import java.util.Scanner;
import java.util.Vector;

public class s107204188{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int t = scanner.nextInt();
        Vector<Integer> A = new Vector<>();
        for (int i = 0; i < n; i++) {
            A.add(scanner.nextInt());
        }
        int minA = Integer.MAX_VALUE;
        int num = 0;
        int f = 0;
        for (int i = 0; i < n; i++) {
            if (minA > A.get(i)) {
                minA = A.get(i);
            } else {
                if (f == A.get(i) - minA) {
                    num++;
                } else if (f < A.get(i) - minA) {
                    num = 1;
                    f = A.get(i) - minA;
                }
            }
        }
        System.out.println(num);
    }
}
