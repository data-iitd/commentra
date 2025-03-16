
import java.util.Scanner;

public class s079891640{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.nextLine();

        for (int i = 0; i < s.length(); i++) {
            if (s.substring(i + 1).contains(String.valueOf(s.charAt(i)))) {
                System.out.println("no");
                System.exit(0);
            }
        }

        System.out.println("yes");
    }
}

