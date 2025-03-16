import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        String[] inputs = scanner.nextLine().split(" ");
        int v1 = Integer.parseInt(inputs[0]);
        int v2 = Integer.parseInt(inputs[1]);
        int t = Integer.parseInt(scanner.nextLine());
        int d = Integer.parseInt(scanner.nextLine());
        
        int a = 1;
        int v = v1;
        int distance = 0;
        
        for (int i = 0; i < t; i++) {
            if (v - v2 > (t - i - 1) * d) {
                a *= -1;
                v = (t - i - 1) * d + v2;
            }
            distance += v;
            v += a * d;
        }
        
        System.out.println(distance);
    }
}
