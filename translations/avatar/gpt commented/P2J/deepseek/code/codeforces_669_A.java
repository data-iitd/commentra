import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int result = (n * 2 + 1) / 3;
        System.out.println(result);
    }
}
