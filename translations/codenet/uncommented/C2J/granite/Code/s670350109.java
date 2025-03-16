
import java.util.Scanner;

public class s670350109{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String str1 = sc.nextLine();
        String str2 = sc.nextLine();
        int i, j = 0, t;
        if (str1.length()!= str2.length()) {
            System.out.println("NO");
        } else {
            char[] temp = new char[str1.length()];
            i = str1.length() - 1;
            t = i - 1;
            while (str1.charAt(j)!= '\0') {
                temp[j] = str1.charAt(t);
                j++;
                t--;
            }
            t = 0;
            i = 0;
            while (temp[i]!= '\0') {
                if (temp[i] == str2.charAt(i)) {
                    t++;
                }
                i++;
            }
            if (str2.length() == t) {
                System.out.println("YES");
            } else if (str2.length()!= t) {
                System.out.println("NO");
            }
        }
    }
}
