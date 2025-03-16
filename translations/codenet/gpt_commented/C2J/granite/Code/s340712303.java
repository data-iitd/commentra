
import java.util.Scanner;

public class s340712303{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int num1 = scanner.nextInt();
        int[] math = new int[2001];
        math[0] = 1;
        int sum = 0;
        for (int i = 0; i < num1; i++) {
            int a = scanner.nextInt();
            sum += a;
            for (int j = sum - a; j >= 0; j--) {
                if (math[j] == 1) {
                    math[j + a] = 1;
                }
            }
        }
        int num2 = scanner.nextInt();
        for (int i = 0; i < num2; i++) {
            int ans = scanner.nextInt();
            if (math[ans] == 1) {
                System.out.println("yes");
            } else {
                System.out.println("no");
            }
        }
    }
}
