
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int a = sc.nextInt();
        int b = sc.nextInt();
        int[] lista = new int[n];
        for (int i = 0; i < n; i++) {
            lista[i] = sc.nextInt();
        }
        int[] listb = new int[n];
        for (int i = 0; i < n; i++) {
            listb[i] = sc.nextInt();
        }
        for (int k = 0; k < n; k++) {
            if (k + 1 == lista[k]) {
                System.out.print(1 + " ");
            } else {
                System.out.print(2 + " ");
            }
        }
    }
}

