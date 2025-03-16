public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        String s = scanner.next();
        String t = scanner.next();
        s += s;
        System.out.println(s.indexOf(t) != -1 ? "Yes" : "No");
    }
}
