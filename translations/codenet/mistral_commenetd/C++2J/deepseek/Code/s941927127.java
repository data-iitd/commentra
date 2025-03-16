import java.util.Scanner;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String W = scanner.next();

        char[] charArray = W.toCharArray();
        Arrays.sort(charArray);

        boolean isAllSame = true;
        for (int i = 0; i < charArray.length - 1; i++) {
            if (charArray[i] != charArray[i + 1]) {
                isAllSame = false;
                break;
            }
        }

        if (isAllSame) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
    }
}

