
import java.util.Scanner;

public class codeforces_421_A{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int a = scanner.nextInt();
        int b = scanner.nextInt();
        int[] lista = new int[a];
        for (int i = 0; i < a; i++) {
            lista[i] = scanner.nextInt();
        }
        int[] listb = new int[b];
        for (int i = 0; i < b; i++) {
            listb[i] = scanner.nextInt();
        }
        for (int k = 0; k < n; k++) {
            if (k + 1 < lista.length && lista[k + 1]!= 0) {
                System.out.print(1 + " ");
            } else {
                System.out.print(2 + " ");
            }
        }
    }
}
