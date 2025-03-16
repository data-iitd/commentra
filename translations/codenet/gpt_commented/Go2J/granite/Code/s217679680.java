
import java.util.Scanner;

public class s217679680{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String[] input = scanner.nextLine().split(" ");
        int[] arr = new int[input.length];
        for (int i = 0; i < input.length; i++) {
            arr[i] = Integer.parseInt(input[i]);
        }
        int a = arr[0];
        int b = arr[1];
        int tap = 0;
        int consent = 1;
        while (consent < b) {
            consent = consent + a - 1;
            tap++;
        }
        System.out.println(tap);
    }
}

// 