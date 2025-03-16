
import java.util.Scanner;

public class s278875041{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String a = scanner.nextLine();
        String tmp = a.replaceAll("1", "0");
        String b = tmp.replaceAll("9", "1");
        String ans = b.replaceAll("0", "9");
        System.out.println(ans);
    }
}

