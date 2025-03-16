import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        String result = "Yes";
        if (s.contains("A") && s.contains("B")) {
            result = "Yes";
        } else {
            result = "No";
        }
        System.out.println(result);
    }
}
