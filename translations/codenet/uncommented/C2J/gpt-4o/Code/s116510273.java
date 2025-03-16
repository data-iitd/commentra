import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String mes = scanner.next();
        System.out.printf("%c%d%c\n", mes.charAt(0), mes.length() - 2, mes.charAt(mes.length() - 1));
        scanner.close();
    }
}

// <END-OF-CODE>
