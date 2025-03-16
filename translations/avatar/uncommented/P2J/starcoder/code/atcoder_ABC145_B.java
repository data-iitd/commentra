n = Integer.parseInt(input());
s = input();
if (n % 2!= 0) {
    System.out.println("No");
} else if (s.substring(0, n / 2).equals(s.substring(n / 2, n))) {
    System.out.println("Yes");
} else {
    System.out.println("No");
}

