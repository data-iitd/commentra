
import java.util.Arrays;
import java.util.Scanner;

public class s725956217{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int M = scanner.nextInt();
        Shop[] shops = new Shop[N];
        for (int i = 0; i < N; i++) {
            int a = scanner.nextInt();
            int b = scanner.nextInt();
            shops[i] = new Shop(a, b);
        }
        Arrays.sort(shops);
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

    static class Shop implements Comparable<Shop> {
        int a;
        int b;

        public Shop(int a, int b) {
            this.a = a;
            this.b = b;
        }

        @Override
        public int compareTo(Shop o) {
            return this.a - o.a;
        }
    }
}

// END-OF-CODE