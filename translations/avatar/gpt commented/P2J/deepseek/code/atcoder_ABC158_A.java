import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.nextLine();
        String result = "No";

        if (s.contains("A") && s.contains("B")) {
            result = "Yes";
        }

        System.out.println(result);
    }
}
