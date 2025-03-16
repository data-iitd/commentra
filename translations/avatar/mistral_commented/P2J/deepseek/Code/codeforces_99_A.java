import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String input = scanner.nextLine();
        
        String[] parts = input.split("\\.");
        
        String s = parts[0];
        String p = parts[1];
        
        char lastChar = s.charAt(s.length() - 1);
        
        if (lastChar == '9') {
            System.out.println("GOTO Vasilisa.");
        } else if (lastChar != '9' && Integer.parseInt(p.substring(0, 1)) < 5) {
            System.out.println(s);
        } else {
            int newNumber = Integer.parseInt(s) + 1;
            System.out.println(newNumber);
        }
    }
}
