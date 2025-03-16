
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String mes = sc.nextLine();
        System.out.println(mes.charAt(0) + mes.length() - 2 + mes.charAt(mes.length() - 1));
    }
}

