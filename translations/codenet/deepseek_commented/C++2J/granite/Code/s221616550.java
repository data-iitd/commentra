
import java.util.Scanner;

public class s221616550{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.nextLine();
        boolean isPalindrome = true;
        for (int i = 0; i < s.length() / 2; i++) {
            if (s.charAt(i)!= s.charAt(s.length() - 1 - i)) {
                isPalindrome = false;
                break;
            }
        }
        if (isPalindrome) {
            String firstHalf = s.substring(0, s.length() / 2);
            boolean isFirstHalfPalindrome = true;
            for (int i = 0; i < firstHalf.length() / 2; i++) {
                if (firstHalf.charAt(i)!= firstHalf.charAt(firstHalf.length() - 1 - i)) {
                    isFirstHalfPalindrome = false;
                    break;
                }
            }
            if (isFirstHalfPalindrome) {
                System.out.println("Yes");
            } else {
                System.out.println("No");
            }
        } else {
            System.out.println("No");
        }
    }
}
