import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int t = 0;

        for (int i = 0; i < n; i++) {
            if ((i + 1) % 2 == 1) {
                t += 1;
            }
        }

        System.out.println((double) t / n);
        scanner.close();
    }
}
// <END-OF-CODE>
