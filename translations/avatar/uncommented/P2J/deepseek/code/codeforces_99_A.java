import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String input = scanner.nextLine();
        String[] parts = input.split("\\.");

        String sPart = parts[0];
        String pPart = parts[1];
        int i = Integer.parseInt(pPart);

        if (sPart.charAt(sPart.length() - 1) == '9') {
            System.out.println("GOTO Vasilisa.");
        } else if (sPart.charAt(sPart.length() - 1) != '9' && i < 5) {
            System.out.println(sPart);
        } else {
            int newNumber = Integer.parseInt(sPart) + 1;
            System.out.println(newNumber);
        }
    }
}
