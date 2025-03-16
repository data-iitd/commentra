import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] list = new int[n];
        for (int i = 0; i < n; i++) {
            list[i] = sc.nextInt();
        }
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (list[i] % 2 == 1) {
                count++;
            }
        }
        if (count == 1) {
            for (int i = 0; i < n; i++) {
                if (list[i] % 2 == 1) {
                    System.out.println(i + 1);
                    break;
                }
            }
        } else {
            for (int i = 0; i < n; i++) {
                if (list[i] % 2 == 0) {
                    System.out.println(i + 1);
                    break;
                }
            }
        }
    }
}
