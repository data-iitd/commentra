import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String a = scanner.nextLine();

        // Print the result based on the input
        if (a.replace(" ", "").replace("0", "").length() == 0) {
            System.out.println(0);
        } else {
            String[] parts = a.replace(" ", "").split("1");
            int result = 1;
            for (String part : parts) {
                result *= (part.length() + 1);
            }
            System.out.println(result);
        }
    }
}
