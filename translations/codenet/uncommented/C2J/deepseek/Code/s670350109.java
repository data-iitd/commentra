import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String str1 = scanner.nextLine();
        String str2 = scanner.nextLine();
        if (str1.length() != str2.length()) {
            System.out.println("NO");
        } else {
            char[] temp = new char[100];
            int i = str1.length() - 1;
            int j = 0;
            while (i >= 0) {
                temp[j] = str1.charAt(i);
                j++;
                i--;
            }
            i = 0;
            int t = 0;
            while (i < str2.length()) {
                if (temp[i] == str2.charAt(i)) {
                    t++;
                }
                i++;
            }
            if (str2.length() == t) {
                System.out.println("YES");
            } else {
                System.out.println("NO");
            }
        }
    }
}
