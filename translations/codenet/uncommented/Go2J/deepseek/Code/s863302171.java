public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        String n = scanner.next();
        
        for (int i = 0; i < 3; i++) {
            if (n.charAt(i) == '7') {
                System.out.println("Yes");
                return;
            }
        }
        System.out.println("No");
    }
}
