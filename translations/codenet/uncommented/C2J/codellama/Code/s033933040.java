
public class Main {
    public static void main(String[] args) {
        int a, b, mawari, menseki;
        Scanner sc = new Scanner(System.in);
        a = sc.nextInt();
        b = sc.nextInt();
        mawari = a + a + b + b;
        menseki = a * b;
        System.out.println(menseki + " " + mawari);
    }
}

