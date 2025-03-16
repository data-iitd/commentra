
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();

        int ret = a + b;

        if (ret < (a - b)) {
            ret = a - b;
        }
        if (ret < (a * b)) {
            ret = a * b;
        }

        System.out.println(ret);
    }
}

