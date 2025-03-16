
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String str1 = sc.nextLine();
        String str2 = sc.nextLine();
        String temp = "";
        int i = 0, j = 0, t = 0;

        if (str1.length() != str2.length()) {
            System.out.println("NO");
        } else {
            while (i < str1.length()) {
                temp = str1.charAt(str1.length() - i - 1) + temp;
                i++;
            }

            i = 0;
            while (i < str2.length()) {
                if (temp.charAt(i) == str2.charAt(i)) {
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

