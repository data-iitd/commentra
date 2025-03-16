import java.util.Scanner;

public class CaseChanger {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String txt = scanner.nextLine();
        int cu = 0;
        int cl = 0;
        
        for (char z : txt.toCharArray()) {
            if (Character.isLowerCase(z)) {
                cl++;
            } else {
                cu++;
            }
        }
        
        if (cu > cl) {
            txt = txt.toUpperCase();
        } else {
            txt = txt.toLowerCase();
        }
        
        System.out.println(txt);
    }
}
