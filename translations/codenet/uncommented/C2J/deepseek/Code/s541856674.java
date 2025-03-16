public class Main {
    public static void main(String[] args) {
        int N = 0;
        int R = 0;

        java.util.Scanner scanner = new java.util.Scanner(System.in);
        N = scanner.nextInt();
        R = scanner.nextInt();

        if(N >= 10) {
            System.out.println(R);
        } else {
            System.out.println(R + 100*(10-N));
        }
    }
}
