
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s1 = sc.next();
        String s2 = sc.next();
        String s3 = sc.next();

        String s1s = s1.substring(0,1).toUpperCase() + s1.substring(1);
        String s2s = s2.substring(0,1).toUpperCase() + s2.substring(1);
        String s3s = s3.substring(0,1).toUpperCase() + s3.substring(1);

        System.out.println(s1s + s2s + s3s);
    }
}

