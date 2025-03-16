import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String str1 = scanner.nextLine();
        String str2 = scanner.nextLine();
        
        int i = str1.length();
        int t = i - 1;
        
        if (str1.length() != str2.length()) {
            System.out.println("NO");
        } else {
            char[] temp = new char[i];
            int j = 0;
            
            while (j < str1.length()) {
                temp[j] = str1.charAt(t);
                j++;
                t--;
            }
            
            t = 0;
            i = 0;
            int matchCount = 0;
            
            while (i < temp.length) {
                if (temp[i] == str2.charAt(i)) {
                    matchCount++;
                }
                i++;
            }
            
            if (str2.length() == matchCount) {
                System.out.println("YES");
            } else {
                System.out.println("NO");
            }
        }
        
        scanner.close();
    }
}

// <END-OF-CODE>
