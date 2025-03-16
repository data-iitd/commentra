import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int a;

        a = scanner.nextInt();

        System.out.println(a / (60 * 60) + ":" + (a % (60 * 60)) / 60 + ":" + (a % (60 * 60)) % 60);

        scanner.close();
    }
}

// <END-OF-CODE>
