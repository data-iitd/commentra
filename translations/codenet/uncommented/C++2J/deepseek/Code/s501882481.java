public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        String S = scanner.nextLine();
        if (S.equals("Sunny")) {
            System.out.println("Cloudy");
        } else if (S.equals("Cloudy")) {
            System.out.println("Rainy");
        } else {
            System.out.println("Sunny");
        }
    }
}
