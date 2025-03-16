
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String n = sc.nextLine();
        for (int i = 0; i < 3; i++) {
            if (n.charAt(i) == '7') {
                System.out.println("Yes");
                return;
            }
        }
        System.out.println("No");
    }
}

