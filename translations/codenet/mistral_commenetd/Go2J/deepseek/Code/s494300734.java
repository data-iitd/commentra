import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.nextLine();

        String ans = "No";

        int firstC = s.indexOf("C");
        int lastF = s.lastIndexOf("F");

        if (firstC >= 0 && firstC < lastF) {
            ans = "Yes";
        }

        System.out.println(ans);
    }
}
