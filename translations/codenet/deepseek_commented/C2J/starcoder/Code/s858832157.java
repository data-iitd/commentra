
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int i = 1, Input;

        while (true) {
            Input = sc.nextInt();
            if (Input == 0) {
                break;
            }
            System.out.printf("Case %d: %d\n", i, Input);
            i++;
        }
    }
}

