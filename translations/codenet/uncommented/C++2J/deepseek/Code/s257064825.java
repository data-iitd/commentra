import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String str = scanner.nextLine();
        int sum = 0;
        for (char x : str.toCharArray()) {
            sum += (x - '0');
        }
        if (sum % 9 == 0) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
    }
}
