import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int M = sc.nextInt();
        List<Shop> shops = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            shops.add(new Shop(a, b));
        }
        Collections.sort(shops, (s1, s2) -> Integer.compare(s1.a, s2.a));

        int total = 0;
        for (Shop e : shops) {
            int n = Math.min(e.b, M);
            total += n * e.a;
            M -= n;
            if (M == 0) {
                break;
            }
        }
        System.out.println(total);
    }

    static class Shop {
        int a, b;

        Shop(int a, int b) {
            this.a = a;
            this.b = b;
        }
    }
}
