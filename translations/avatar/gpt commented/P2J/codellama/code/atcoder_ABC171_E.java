import java.util.Scanner;
import java.util.stream.Collectors;
import java.util.stream.Stream;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int[] a = Stream.of(sc.nextLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        int total = 0;
        for (int i = 0; i < a.length; i++) {
            total ^= a[i];
        }
        for (int i = 0; i < a.length; i++) {
            System.out.print(a[i] ^ total + " ");
        }
        System.out.println();
        sc.close();
    }
}

