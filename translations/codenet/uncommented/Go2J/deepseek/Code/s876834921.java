public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        String s = scanner.nextLine();
        s = s.replace("dream", "D");
        s = s.replace("erase", "E");
        s = s.replace("Der", "");
        s = s.replace("Er", "");
        s = s.replace("D", "");
        s = s.replace("E", "");
        s = s.trim();

        if (s.isEmpty()) {
            System.out.println("YES");
        } else {
            System.out.println("NO");
        }
    }
}
