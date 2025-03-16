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

        shops.sort(Comparator.comparingInt(shop -> shop.a));

        long total = 0;
        for (Shop shop : shops) {
            int n = Math.min(shop.b, M);
            total += (long) n * shop.a;
            M -= n;
            if (M == 0) {
                break;
            }
        }

        System.out.println(total);
    }

    static class Shop {
        int a;
        int b;

        Shop(int a, int b) {
            this.a = a;
            this.b = b;
        }
    }
}
