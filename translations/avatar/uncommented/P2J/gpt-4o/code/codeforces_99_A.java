import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String l = scanner.nextLine();
        String[] parts = l.split("\\.");
        char[] s = parts[0].toCharArray();
        char[] p = parts[1].toCharArray();
        int i = Character.getNumericValue(p[0]);

        if (s[s.length - 1] == '9') {
            System.out.println("GOTO Vasilisa.");
        } else if (s[s.length - 1] != '9' && i < 5) {
            System.out.println(new String(s));
        } else {
            String sStr = new String(s);
            int incrementedValue = Integer.parseInt(sStr) + 1;
            System.out.println(incrementedValue);
        }
        
        scanner.close();
    }
}
// <END-OF-CODE>
