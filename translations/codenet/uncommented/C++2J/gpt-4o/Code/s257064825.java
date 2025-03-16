import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String str = scanner.next();
        long sum = 0;

        for (char x : str.toCharArray()) {
            sum += (x - '0');
        }

        if (sum % 9 == 0) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }

        scanner.close();
    }
}
// <END-OF-CODE>
