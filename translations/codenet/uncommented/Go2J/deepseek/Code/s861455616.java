public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        String s = scanner.nextLine();
        if (s.length() >= 4 && s.substring(0, 4).equals("YAKI")) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
    }
}
