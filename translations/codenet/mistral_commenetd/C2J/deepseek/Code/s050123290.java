public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        while (true) {
            String su = scanner.nextLine();
            if (su.charAt(0) == '0') break;
            int susum = 0;
            for (int j = 0; j < su.length(); j++) {
                susum += su.charAt(j) - '0';
            }
            System.out.println(susum);
        }
    }
}
