public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int s = scanner.nextInt();
        java.util.Set<Integer> a = new java.util.HashSet<>();
        a.add(s);
        int d = 2;

        while (true) {
            if (s % 2 == 0) {
                int x = s / 2;
                if (a.contains(x)) {
                    System.out.println(d);
                    return;
                }
                a.add(x);
            } else {
                int x = 3 * s + 1;
                if (a.contains(x)) {
                    System.out.println(d);
                    return;
                }
                a.add(x);
            }
            s = x;
            d++;
        }
    }
}
