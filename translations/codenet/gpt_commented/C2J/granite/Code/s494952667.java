
import java.util.Scanner;

public class s494952667{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String input = scanner.nextLine();
        char[] charArray = input.toCharArray();
        for (int i = charArray.length - 1; i >= 0; i--) {
            System.out.print(charArray[i]);
        }
        System.out.println();
    }
}
