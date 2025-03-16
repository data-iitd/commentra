
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int vamshi = sc.nextInt();
        int z = sc.nextInt();
        int result = (vamshi / z + 1) * z;
        System.out.println(result);
    }
}

