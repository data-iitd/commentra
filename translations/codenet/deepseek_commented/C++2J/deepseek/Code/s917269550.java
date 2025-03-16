import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        long x = scanner.nextLong();
        long y = scanner.nextLong();
        if (Math.abs(x - y) <= 1) {
            System.out.println("Brown");
        } else {
            System.out.println("Alice");
        }
    }
}
