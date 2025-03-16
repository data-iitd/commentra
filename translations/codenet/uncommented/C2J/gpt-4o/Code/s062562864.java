import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int a = scanner.nextInt();
        int b = scanner.nextInt();
        int c = scanner.nextInt();
        int d = scanner.nextInt();

        int i = a * b;
        int j = c * d;

        if (i > j) {
            System.out.println(i);
        } else {
            System.out.println(j);
        }

        scanner.close();
    }
}

// <END-OF-CODE>
