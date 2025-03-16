
import java.util.Scanner;

public class s235491884{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.nextLine();

        int n = countOs(s);
        System.out.println(700 + n * 100);
    }

    private static int countOs(String s) {
        int count = 0;
        for (char c : s.toCharArray()) {
            if (c == 'o') {
                count++;
            }
        }
        return count;
    }
}

