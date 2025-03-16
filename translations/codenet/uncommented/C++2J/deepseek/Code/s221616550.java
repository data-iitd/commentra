public class PalindromeChecker {
    public static boolean isPalindrome(String s) {
        for (int i = 0; i < s.length() / 2; i++) {
            if (s.charAt(i) == s.charAt(s.length() - 1 - i)) {
                continue;
            } else {
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        String s = scanner.nextLine();
        if (isPalindrome(s) && isPalindrome(s.substring(0, s.length() / 2))) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
    }
}
