import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String str = sc.nextLine();
        str = str.substring(0, 5) + " " + str.substring(6, 14) + " " + str.substring(15);
        System.out.println(str);
    }
}
