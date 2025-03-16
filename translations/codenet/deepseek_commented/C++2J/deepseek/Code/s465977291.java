import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int d = scanner.nextInt();

        double a = d * 2 + 1;
        System.out.println((int) Math.ceil(n / a));
    }
}
