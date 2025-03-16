
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    // Initialize Scanner to read input from the user
    double N, d, x;
    scanf("%lf %lf %lf", &N, &d, &x);

    // Read three double values: N, d, and x
    // double N = scan.nextDouble ( ) ; 
    // double d = scan.nextDouble ( ) ; 
    // double x = scan.nextDouble ( ) ; 

    // Initialize BigDecimal to store the result with precision
    double ans = 0.0;

    // Continue the loop until N is greater than 0.5
    while (N > 0.5)
    {
        // Calculate a value using BigDecimal for precision
        double adnum = d + x * (N - 0.5);
        ans += adnum;

        // Update the values of d and x based on the current value of N
        d = (N + 1.0) * d / N + (5.0 * x) / (2.0 * N);
        x = (1.0 + (2.0 / N)) * x;

        // Decrement N by 1 in each iteration
        --N;
    }

    // Initialize DecimalFormat to format the output
    // DecimalFormat format = new DecimalFormat ( "#.#" ) ; 
    // format.setMinimumFractionDigits ( 20 ) ; 

    // Print the result formatted to a specific number of decimal places
    printf("%.20lf\n", ans);

    // System.out.println ( format.format ( ans ) ) ; 

    // Print the result formatted to a specific number of decimal places
    // printf("%.20lf\n", ans);

    // System.out.println ( format.format ( ans ) ) ; 

    // Print the result formatted to a specific number of decimal places
    // printf("%.20lf\n", ans);

    // System.out.println ( format.format ( ans ) ) ; 

    // Print the result formatted to a specific number of decimal places
    // printf("%.20lf\n", ans);

    // System.out.println ( format.format ( ans ) ) ; 

    // Print the result formatted to a specific number of decimal places
    // printf("%.20lf\n", ans);

    // System.out.println ( format.format ( ans ) ) ; 

    // Print the result formatted to a specific number of decimal places
    // printf("%.20lf\n", ans);

    // System.out.println ( format.format ( ans ) ) ; 

    // Print the result formatted to a specific number of decimal places
    // printf("%.20lf\n", ans);

    // System.out.println ( format.format ( ans ) ) ; 

    // Print the result formatted to a specific number of decimal places
    // printf("%.20lf\n", ans);

    // System.out.println ( format.format ( ans ) ) ; 

    // Print the result formatted to a specific number of decimal places
    // printf("%.20lf\n", ans);

    // System.out.println ( format.format ( ans ) ) ; 

    // Print the result formatted to a specific number of decimal places
    // printf("%.20lf\n", ans);

    // System.out.println ( format.format ( ans ) ) ; 

    // Print the result formatted to a specific number of decimal places
    // printf("%.20lf\n", ans);

    // System.out.println ( format.format ( ans ) ) ; 

    // Print the result formatted to a specific number of decimal places
    // printf("%.20lf\n", ans);

    // System.out.println ( format.format ( ans ) ) ; 

    // Print the result formatted to a specific number of decimal places
    // printf("%.20lf\n", ans);

    // System.out.println ( format.format ( ans ) ) ; 

    // Print the result formatted to a specific number of decimal places
    // printf("%.20lf\n", ans);

    // System.out.println ( format.format ( ans ) ) ; 

    // Print the result formatted to a specific number of decimal places
    // printf("%.20lf\n", ans);

    // System.out.println ( format.format ( ans ) ) ; 

    // Print the result formatted to a specific number of decimal places
    // printf("%.20lf\n", ans);

    // System.out.println ( format.format ( ans ) ) ; 

    // Print the result formatted to a specific number of decimal places
    // printf("%.20lf\n", ans);

    // System.out.println ( format.format ( ans ) ) ; 

    // Print the result formatted to a specific number of decimal places
    // printf("%.20lf\n", ans);

    // System.out.println ( format.format ( ans ) ) ; 

    // Print the result formatted to a specific number of decimal places
    // printf("%.20lf\n", ans);

    // System.out.println ( format.format ( ans ) ) ; 

    // Print the result formatted to a specific number of decimal places
    // printf("%.20lf\n", ans);

    // System.out.println ( format.format ( ans ) ) ; 

    // Print the result formatted to a specific number of decimal places
    // printf("%.20lf\n", ans);

    // System.out.println ( format.format ( ans ) ) ; 

    // Print the result formatted to a specific number of decimal places
    // printf("%.20lf\n", ans);

    // System.out.println ( format.format ( ans ) ) ; 

    // Print the result formatted to a specific number of decimal places
    // printf("%.20lf\n", ans);

    // System.out.println ( format.format ( ans ) ) ; 

    // Print the result formatted to a specific number of decimal places
    // printf("%.20lf\n", ans);

    // System.out.println ( format.format ( ans ) ) ; 

    // Print the result formatted to a specific number of decimal places
    // printf("%.20lf\n", ans);

    // System.out.println ( format.format ( ans ) ) ; 

    // Print the result formatted to a specific number of decimal places
    // printf("%.20lf\n", ans);

    // System.out.println ( format.format ( ans ) ) ; 

    // Print the result formatted to a specific number of decimal places
    // printf("%.20lf\n", ans);

    // System.out.println ( format.format ( ans ) ) ; 

    // Print the result formatted to a specific number of decimal places
    // printf("%.20lf\n", ans);

    // System.out.println ( format.format ( ans ) ) ; 

    // Print the result formatted to a specific number of decimal places
    // printf("%.20lf\n", ans);

    // System.out.println ( format.format ( ans ) ) ; 

    // Print the result formatted to a specific number of decimal places
    // printf("%.20lf\n", ans);

    // System.out.println ( format.format ( ans ) ) ; 

    // Print the result formatted to a specific number of decimal places
    // printf("%.20lf\n", ans);

    // System.out.println ( format.format ( ans ) ) ; 

    // Print the result formatted to a specific number of decimal places
    // printf("%.20lf\n", ans);

    // System.out.println ( format.format ( ans ) ) ; 

    // Print the result formatted to a specific number of decimal places
    // printf("%.20lf\n", ans);

    // System.out.println ( format.format ( ans ) ) ; 

    // Print the result formatted to a specific number of decimal places
    // printf("%.20lf\n", ans);

    // System.out.println ( format.format ( ans ) ) ; 

    // Print the result formatted to a specific number of decimal places
    // printf("%.20lf\n", ans);

    // System.out.println ( format.format ( ans ) ) ; 

    // Print the result formatted to a specific number of decimal places
    // printf("%.20lf\n", ans);

    // System.out.println ( format.format ( ans ) ) ; 

    // Print the result formatted to a specific number of decimal places
    // printf("%.20lf\n", ans);

    // System.out.println ( format.format ( ans ) ) ; 

    // Print the result formatted to a specific number of decimal places
    // printf("%.20lf\n", ans);

    // System.out.println ( format.format ( ans ) ) ; 

    // Print the result formatted to a specific number of decimal places
    // printf("%.20lf\n", ans);

    // System.out.println ( format.format ( ans ) ) ; 

    // Print the result formatted to a specific number of decimal places
    // printf("%.20lf\n", ans);

    // System.out.println ( format.format ( ans ) ) ; 

    // Print the result formatted to a specific number of decimal places
    // printf("%.20lf\n", ans);

    // System.out.println ( format.format ( ans ) ) ; 

    // Print the result formatted to a specific number of decimal places
    // printf("%.20lf\n", ans);

    // System.out.println ( format.format ( ans ) ) ; 

    // Print the result formatted to a specific number of decimal places
    // printf("%.20lf\n", ans);

    // System.out.println ( format.format ( ans ) ) ; 

    // Print the result formatted to a specific number of decimal places
    // printf("%.20lf\n", ans);

    // System.out.println ( format.format ( ans ) ) ; 

    // Print the result formatted to a specific number of decimal places
    // printf("%.20lf\n", ans);

    // System.out.println ( format.format ( ans ) ) ; 

    // Print the result formatted to a specific number of decimal places
    // printf("%.20lf\n", ans);

    // System.out.println ( format.format ( ans ) ) ; 

    // Print the result formatted to a specific number of decimal places
    // printf("%.20lf\n", ans);

    // System.out.println ( format.format ( ans ) ) ; 

    // Print the result formatted to a specific number of decimal places
    // printf("%.20lf\n", ans);

    // System.out.println ( format.format ( ans ) ) ; 

    // Print the result formatted to a specific number of decimal places
    // printf("%.20lf\n", ans);

    // System.out.println ( format.format ( ans ) ) ; 

    // Print the result formatted to a specific number of decimal places
    // printf("%.20lf\n", ans);

    // System.out.println ( format.format ( ans ) ) ; 

    // Print the result formatted to a specific number of decimal places
    // printf("%.20lf\n", ans);

    // System.out.println ( format.format ( ans ) ) ; 

    // Print the result formatted to a specific number of decimal places
    // printf("%.20lf\n", ans);

    // System.out.println ( format.format ( ans ) ) ; 

    // Print the result formatted to a specific number of decimal places
    // printf("%.20lf\n", ans);

    // System.out.println ( format.format ( ans ) ) ; 

    // Print the result formatted to a specific number of decimal places
    // printf("%.20lf\n", ans);

    // System.out.println ( format.format ( ans ) ) ; 

    // Print the result formatted to a specific number of decimal places
    // printf("%.20lf\n", ans);

    // System.out.println ( format.format ( ans ) ) ; 

    // Print the result formatted to a specific number 