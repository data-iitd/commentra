import java.util.Scanner;
import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;
import java.util.stream.Stream;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        List<Integer> A = Stream.of(scanner.next().split(" ")).map(Integer::parseInt).collect(Collectors.toList());
        
        int gcd = A.get(0);
        for (int i = 1; i < N; i++) {
            gcd = gcd(gcd, A.get(i));
        }
        
        System.out.println(gcd);
    }
    
    public static int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
}
