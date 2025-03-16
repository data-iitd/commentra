import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        scanner.nextLine(); // Consume the newline character
        Map<String, Boolean> T = new HashMap<>();

        for (int i = 0; i < n; i++) {
            String com = scanner.next();
            String str = scanner.next();
            if (com.charAt(0) == 'i') {
                T.put(str, true);
            } else {
                if (T.getOrDefault(str, false)) {
                    System.out.println("yes");
                } else {
                    System.out.println("no");
                }
            }
        }
        scanner.close();
    }
}

// <END-OF-CODE>
