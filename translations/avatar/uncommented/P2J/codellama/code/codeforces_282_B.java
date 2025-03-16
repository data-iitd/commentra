Scanner scanner = new Scanner(System.in);
int firstline = scanner.nextInt();
int total = 0;
String memory = "";
for (int x = 0; x < firstline; x++) {
    int A = scanner.nextInt();
    int G = scanner.nextInt();
    if (total + A <= 500) {
        total += A;
        memory += "A";
    } else {
        total -= G;
        memory += "G";
    }
}
System.out.println(memory);
