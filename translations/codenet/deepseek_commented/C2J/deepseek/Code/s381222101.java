public class TrapezoidArea {
    public static void main(String[] args) {
        int a, b, h;
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        
        a = scanner.nextInt();
        b = scanner.nextInt();
        h = scanner.nextInt();
        
        System.out.println((a + b) * h / 2);
    }
}
