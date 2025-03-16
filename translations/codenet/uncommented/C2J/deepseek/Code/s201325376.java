public class Main {
    public static void main(String[] args) {
        int a, b, c, i, count;
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        a = scanner.nextInt();
        b = scanner.nextInt();
        c = scanner.nextInt();
        count = 0;
        for (i = a; i <= b; i++) {
            if (c % i == 0)
                count++;
        }
        System.out.println(count);
    }
}
