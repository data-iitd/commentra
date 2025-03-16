public class Main {
    public static void main(String[] args) {
        int sheep;
        int wolf;

        java.util.Scanner scanner = new java.util.Scanner(System.in);
        sheep = scanner.nextInt();
        wolf = scanner.nextInt();

        if(wolf >= sheep) {
            System.out.println("unsafe");
        } else {
            System.out.println("safe");
        }
    }
}
