
import java.util.Scanner;

public class s503150457{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s1 = scanner.next();
        String s2 = scanner.next();
        String s3 = scanner.next();

        String[] s1s = s1.split("");
        String[] s2s = s2.split("");
        String[] s3s = s3.split("");

        System.out.println(s1s[0].toUpperCase() + s2s[0].toUpperCase() + s3s[0].toUpperCase());
    }
}
