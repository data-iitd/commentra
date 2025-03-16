import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int sum = 0;
        int m = n;

        for (int i = 0; i < 9; i++) {
            sum += m % 10;
            m /= 10;
        }

        if (m % sum == 0) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
    }
}
