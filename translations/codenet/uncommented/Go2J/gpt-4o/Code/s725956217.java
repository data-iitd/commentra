import java.util.*;

public class Main {
    static Scanner sc = new Scanner(System.in);

    static class Shop {
        int a, b;

        Shop(int a, int b) {
            this.a = a;
            this.b = b;
        }
    }

    public static void main(String[] args) {
        int N = sc.nextInt();
        int M = sc.nextInt();
        List<Shop> shops = new ArrayList<>();

        for (int i = 0; i < N; i++) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            shops.add(new Shop(a, b));
        }

        // Sort shops based on the price (a)
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
}

// <END-OF-CODE>
