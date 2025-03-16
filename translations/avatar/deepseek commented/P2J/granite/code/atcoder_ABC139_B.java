

Scanner scanner = new Scanner ( System.in );
// Creating a `Scanner` object to read input from the user.
int a = scanner.nextInt ( );
// Taking an integer input, `a`.
int b = scanner.nextInt ( );
// Taking another integer input, `b`.
int hole = 1;
// Initializing `hole` to 1.
int i = 0;
// Initializing `i` to 0.
boolean check = true;
// Setting a boolean variable `check` to `true`.
while ( check ) {
// The `while` loop runs as long as `check` is `true`.
if ( hole >= b ) {
// Checking if `hole` is greater than or equal to `b`.
check = false;
// If so, set `check` to `false` to exit the loop.
} else {
hole = a * ( i + 1 ) - i;
// If `hole` is less than `b`, update `hole` to `a * (i + 1) - i`.
i += 1;
// Increment `i` by 1.
}
}
System.out.println ( i );
// Finally, print the value of `i` after the loop exits.
