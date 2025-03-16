import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        long a = scanner.nextLong();
        long b = scanner.nextLong();

        long result = Math.max(a + b, Math.max(a - b, a * b));
        System.out.println(result);
    }
}
