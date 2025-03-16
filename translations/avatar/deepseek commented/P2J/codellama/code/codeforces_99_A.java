
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String input = sc.nextLine();
        String[] parts = input.split("\\.");
        String[] firstPart = parts[0].split("");
        String[] secondPart = parts[1].split("");
        int secondPartInt = Integer.parseInt(secondPart[0]);

        if (firstPart[firstPart.length - 1].equals("9")) {
            System.out.println("GOTO Vasilisa.");
        } else if (!firstPart[firstPart.length - 1].equals("9") && secondPartInt < 5) {
            System.out.println(parts[0]);
        } else {
            int firstPartInt = Integer.parseInt(parts[0]);
            System.out.println(firstPartInt + 1);
        }
    }
}

