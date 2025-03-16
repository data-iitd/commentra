public class CubeCalculator {
    public static void main(String[] args) {
        int x, kotae;
        java.util.Scanner scanner = new java.util.Scanner(System.in);

        System.out.print("Enter an integer value for x: ");
        x = scanner.nextInt();

        kotae = x * x * x;

        System.out.printf("The cube of %d is %d.\n", x, kotae);
    }
}
