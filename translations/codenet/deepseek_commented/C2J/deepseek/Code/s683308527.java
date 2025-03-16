public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int n = scanner.nextInt();
        scanner.nextLine();  // Consume the newline character
        while (n-- > 0) {
            String s = scanner.nextLine();
            while (s.contains("Hoshino")) {
                s = s.replaceFirst("Hoshino", "Hoshina");
            }
            System.out.println(s);
        }
    }
}
