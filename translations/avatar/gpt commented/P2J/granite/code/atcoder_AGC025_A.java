
import java.util.Scanner;

public class atcoder_AGC025_A{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String n = scanner.nextLine();
        int sum = 0;
        for (char c : n.toCharArray()) {
            sum += c - '0';
        }
        if (n.equals("10") || n.equals("100") || n.equals("1000") || n.equals("10000") || n.equals("100000")) {
            System.out.println(10);
        } else {
            System.out.println(sum);
        }
    }
}
