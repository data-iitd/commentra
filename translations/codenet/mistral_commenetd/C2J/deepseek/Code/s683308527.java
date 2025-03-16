import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        scanner.nextLine(); // Consume the newline character

        while (n-- > 0) {
            String s = scanner.nextLine();

            while (s.contains("Hoshino")) {
                int index = s.indexOf("Hoshino");
                s = s.substring(0, index) + "aana" + s.substring(index + 7);
            }

            System.out.println(s);
        }

        scanner.close();
    }
}

