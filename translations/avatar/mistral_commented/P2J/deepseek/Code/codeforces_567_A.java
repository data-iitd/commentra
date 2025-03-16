public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int inp = scanner.nextInt();
        int[] lista = new int[inp];
        for (int i = 0; i < inp; i++) {
            lista[i] = scanner.nextInt();
        }
        for (int i = 0; i < lista.length; i++) {
            if (i == 0) {
                System.out.println((lista[i + 1] - lista[i]) + " " + (lista[lista.length - 1] - lista[i]));
                continue;
            }
            if (i == lista.length - 1) {
                System.out.println((lista[lista.length - 1] - lista[lista.length - 2]) + " " + (lista[lista.length - 1] - lista[0]));
                continue;
            }
            if (lista[i] - lista[i - 1] > lista[i + 1] - lista[i]) {
                System.out.print((lista[i + 1] - lista[i]) + " ");
            } else {
                System.out.print((lista[i] - lista[i - 1]) + " " + (lista[i] - lista[0]) + " ");
                if (lista[lista.length - 1] - lista[i] > lista[i] - lista[0]) {
                    System.out.println(lista[lista.length - 1] - lista[i]);
                } else {
                    System.out.println(lista[i] - lista[0]);
                }
            }
        }
    }
}
