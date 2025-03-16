public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();

        int price = 700;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == 'o') {
                price += 100;
            }
        }
        System.out.println(price);
    }
}
