import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.nextLine();
        String result = "Yes";
        if (!(s.contains("A") && s.contains("B"))) {
            result = "No";
        }
        System.out.println(result);
    }
}
