n = Integer.parseInt(input());
for (int i = n; i > 0; i--) {
    if (n % i == 0) {
        n = i;
        System.out.print(i + " ");
    }
}

