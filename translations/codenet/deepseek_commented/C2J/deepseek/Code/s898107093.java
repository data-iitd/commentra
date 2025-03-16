public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int n = scanner.nextInt();
        String[] t = new String[n];
        String[] h = new String[n];
        int taro = 0, hanako = 0;

        for (int i = 0; i < n; i++) {
            t[i] = scanner.next();
            h[i] = scanner.next();
            int comparison = t[i].compareTo(h[i]);
            if (comparison < 0) hanako += 3;
            if (comparison > 0) taro += 3;
            if (comparison == 0) {
                taro += 1;
                hanako += 1;
            }
        }

        System.out.println(taro + " " + hanako);
    }
}
