

import java.util.Scanner;

public class codeforces_617_B{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int a = scanner.nextInt();
        int result = 0;
        if (a == 0) {
            result = 0;
        } else {
            String[] split = String.valueOf(a).replaceAll("0", "").split("1");
            int count = 0;
            for (String s : split) {
                count += s.length() + 1;
            }
            result = count;
        }
        System.out.println(result);
    }
}



Translate the above Python code to JavaScript and end with comment "