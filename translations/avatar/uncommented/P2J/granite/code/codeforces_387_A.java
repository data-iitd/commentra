
Scanner in = new Scanner ( System.in );
int h1 = in.nextInt ( );
int m1 = in.nextInt ( );
m1 += h1 * 60;
int h2 = in.nextInt ( );
int m2 = in.nextInt ( );
m2 += h2 * 60;
m2 = m1 - m2;
m2 %= 1440;
System.out.printf ( "%02d:%02d", m2 / 60, m2 % 60 );
