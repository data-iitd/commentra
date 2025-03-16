n = Integer.parseInt(input());
for (int i = 0; i < n; i++) {
    int a = Integer.parseInt(input());
    if (a < 2) {
        System.out.println(0);
    } else {
        System.out.println(a - 2);
    }
}

