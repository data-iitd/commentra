import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String[] input = scanner.nextLine().split(" ");
        int n = Integer.parseInt(input[0]);
        int a = Integer.parseInt(input[1]);
        int b = Integer.parseInt(input[2]);

        String[] listaInput = scanner.nextLine().split(" ");
        int[] lista = new int[listaInput.length];
        for (int i = 0; i < listaInput.length; i++) {
            lista[i] = Integer.parseInt(listaInput[i]);
        }

        String[] listbInput = scanner.nextLine().split(" ");
        int[] listb = new int[listbInput.length];
        for (int i = 0; i < listbInput.length; i++) {
            listb[i] = Integer.parseInt(listbInput[i]);
        }

        for (int k = 0; k < n; k++) {
            if (contains(lista, k + 1)) {
                System.out.print(1 + " ");
            } else {
                System.out.print(2 + " ");
            }
        }
    }

    public static boolean contains(int[] array, int value) {
        for (int num : array) {
            if (num == value) {
                return true;
            }
        }
        return false;
    }
}
