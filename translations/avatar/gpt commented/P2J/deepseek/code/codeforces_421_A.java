import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read three integers from input: n (number of elements), a, and b
        int n = scanner.nextInt();
        int a = scanner.nextInt();
        int b = scanner.nextInt();

        // Read a list of integers from input and store it in lista
        int[] lista = new int[a];
        for (int i = 0; i < a; i++) {
            lista[i] = scanner.nextInt();
        }

        // Read another list of integers from input and store it in listb
        int[] listb = new int[b];
        for (int i = 0; i < b; i++) {
            listb[i] = scanner.nextInt();
        }

        // Iterate through the range of n (from 0 to n-1)
        for (int k = 0; k < n; k++) {
            // Check if the current index + 1 is present in lista
            if (isPresent(lista, k + 1)) {
                // If present, print 1 followed by a space
                System.out.print(1 + " ");
            } else {
                // If not present, print 2 followed by a space
                System.out.print(2 + " ");
            }
        }
    }

    // Helper method to check if a number is present in an array
    public static boolean isPresent(int[] array, int num) {
        for (int i : array) {
            if (i == num) {
                return true;
            }
        }
        return false;
    }
}
