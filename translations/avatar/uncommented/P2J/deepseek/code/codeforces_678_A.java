import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int vamshi = scanner.nextInt();
        int z = scanner.nextInt();
        System.out.println((vamshi / z + 1) * z);
    }
}
