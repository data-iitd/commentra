import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String str = sc.nextLine();
        str = str.substring(0, 5) + " " + str.substring(5, 13) + " " + str.substring(13);
        System.out.println(str);
    }
}
