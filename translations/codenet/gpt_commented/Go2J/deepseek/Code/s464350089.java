import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int h = scanner.nextInt();
        int n = scanner.nextInt();
        int sum = 0;

        for (int i = 0; i < n; i++) {
            sum += scanner.nextInt();
        }

        if (h > sum) {
            System.out.println("No");
        } else {
            System.out.println("Yes");
        }
    }
}
