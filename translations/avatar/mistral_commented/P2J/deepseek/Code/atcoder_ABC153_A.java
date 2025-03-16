import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String[] input = scanner.nextLine().split(" ");
        int h = Integer.parseInt(input[0]);
        int a = Integer.parseInt(input[1]);

        int sho = h / a;
        int am = h % a;

        if (am != 0) {
            sho += 1;
        }

        System.out.println(sho);
    }
}
