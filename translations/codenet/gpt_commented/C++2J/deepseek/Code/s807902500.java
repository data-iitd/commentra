public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        String s = scanner.next();
        String t = scanner.next();

        s += s;

        if (s.contains(t)) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
    }
}
