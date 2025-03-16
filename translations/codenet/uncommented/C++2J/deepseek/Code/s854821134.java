import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int a = scanner.nextInt();
        int b = scanner.nextInt();
        if (a <= 8 && b <= 8) System.out.println("Yay!");
        else System.out.println(":(");
    }
}
