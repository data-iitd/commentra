import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int a = scanner.nextInt();
        int b = scanner.nextInt();
        int c = scanner.nextInt();
        int d = scanner.nextInt();
        
        int result = Math.max(Math.max(a * c, b * d), Math.max(a * d, b * c));
        System.out.println(result);
    }
}
