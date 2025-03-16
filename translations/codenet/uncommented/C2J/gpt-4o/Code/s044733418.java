import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int[] array = new int[10];

        for (int i = 0; i < 10; i++) {
            array[i] = scanner.nextInt();
        }

        Arrays.sort(array, Comparator.reverseOrder());

        for (int i = 0; i < 3; i++) {
            System.out.println(array[i]);
        }

        scanner.close();
    }
}

// <END-OF-CODE>
