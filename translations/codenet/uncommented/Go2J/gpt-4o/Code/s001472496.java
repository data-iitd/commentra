import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.nextLine();

        int maxTmp = 0;
        int max = 0;
        for (int i = 0; i < s.length(); i++) {
            boolean flag = false;
            char currentChar = s.charAt(i);
            switch (currentChar) {
                case 'A':
                case 'C':
                case 'T':
                case 'G':
                    maxTmp++;
                    break;
                default:
                    flag = true;
            }

            if (i == s.length() - 1) {
                flag = true;
            }
            if (flag) {
                if (max < maxTmp) {
                    max = maxTmp;
                }
                maxTmp = 0;
            }
        }
        System.out.println(max);
    }
}
// <END-OF-CODE>
