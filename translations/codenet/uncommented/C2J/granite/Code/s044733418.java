
import java.util.Arrays;
import java.util.Scanner;

public class s044733418{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int[] array = new int[10];
        for (int i = 0; i < 10; i++) {
            array[i] = scanner.nextInt();
        }
        Arrays.sort(array);
        for (int i = 0; i < 3; i++) {
            System.out.println(array[i]);
        }
    }
}

