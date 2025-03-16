public class Main {
    public static void main(String[] args) {
        int a, b;
        
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        a = scanner.nextInt();
        
        System.out.println(a/(60*60) + ":" + a%(60*60)/60 + ":" + a%(60*60)%60);
    }
}
