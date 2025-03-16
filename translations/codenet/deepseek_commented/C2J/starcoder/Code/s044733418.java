import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int[] array = new int[10];
        for (int i = 0; i < 10; i++) {
            array[i] = sc.nextInt();
        }
        Arrays.sort(array, (a, b) -> b - a);
        for (int i = 0; i < 3; i++) {
            System.out.println(array[i]);
        }
    }
}
