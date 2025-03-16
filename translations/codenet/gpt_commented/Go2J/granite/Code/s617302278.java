
import java.util.Scanner;

public class s617302278{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int x = scanner.nextInt();
        int i = 1;
        int sum = 0;
        while (sum < x) {
            sum += i;
            i++;
        }
        System.out.println(i);
    }
}
