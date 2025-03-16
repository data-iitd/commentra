
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int inp = sc.nextInt();
        int[] lista = new int[inp];
        for (int i = 0; i < inp; i++) {
            lista[i] = sc.nextInt();
        }
        for (int i = 0; i < inp; i++) {
            if (i == 0) {
                System.out.println(lista[i + 1] - lista[i] + " " + lista[inp - 1] - lista[i]);
                continue;
            }
            if (i == inp - 1) {
                System.out.println(lista[inp - 1] - lista[inp - 2] + " " + lista[inp - 1] - lista[0]);
                continue;
            }
            if (lista[i] - lista[i - 1] > lista[i + 1] - lista[i]) {
                System.out.print(lista[i + 1] - lista[i] + " ");
            } else {
                System.out.print(lista[i] - lista[i - 1] + " ");
            }
            if (lista[inp - 1] - lista[i] > lista[i] - lista[0]) {
                System.out.println(lista[inp - 1] - lista[i]);
            } else {
                System.out.println(lista[i] - lista[0]);
            }
        }
    }
}

