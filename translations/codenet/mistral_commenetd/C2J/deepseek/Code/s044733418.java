import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        int[] array = new int[10];
        Scanner scanner = new Scanner(System.in);

        for (int i = 0; i < 10; i++) {
            array[i] = scanner.nextInt();
        }

        Arrays.sort(array);
        for (int i = 0; i < 3; i++) {
            System.out.println(array[i]);
        }
    }
}

