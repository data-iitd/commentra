n = Integer.parseInt(sc.nextLine());
number = Arrays.stream(sc.nextLine().split(" ")).mapToInt(Integer::parseInt).toArray();
int h1 = 0, h2 = 0, x = 0;
for (int i = 0; i < n; i++) {
    if (number[i]!= 4 && number[i]!= 7) {
        System.out.println("NO");
        x++;
        break;
    }
    if (i < n / 2) {
        h1 += number[i];
    } else {
        h2 += number[i];
    }
}
if (x == 0) {
    if (h1 == h2) {
        System.out.println("YES");
    } else {
        System.out.println("NO");
    }
}

