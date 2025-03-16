public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        String mes = scanner.nextLine();
        System.out.println(mes.charAt(0) + "" + (mes.length() - 2) + mes.charAt(mes.length() - 1));
    }
}
