import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int M = scanner.nextInt();
        List<Shop> shops = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            int a = scanner.nextInt();
            int b = scanner.nextInt();
            shops.add(new Shop(a, b));
        }
        shops.sort(Comparator.comparingInt(shop -> shop.a));

        int total = 0;
        for (Shop shop : shops) {
            int n = Math.min(shop.b, M);
            total += n * shop.a;
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
