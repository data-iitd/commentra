
import java.util.Scanner;

public class s858832157{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int i = 1;
        while (true) {
            int input = scanner.nextInt();
            if (input == 0) {
                break;
            }
            System.out.printf("Case %d: %d\n", i, input);
            i++;
        }
    }
}
// 