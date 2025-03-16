public class Main {
    public static void main(String[] args) {
        int a, b, mawari, menseki;
        
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        a = scanner.nextInt();
        b = scanner.nextInt();
        
        mawari = a + a + b + b;
        menseki = a * b;
        
        System.out.println(menseki + " " + mawari);
    }
}
