#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX_SIZE 100000
#define MAX_NODES 100000
#define MAX_EDGES 100000
#define MAX_LINE 100000

typedef struct {
    int nodes;
    int edges;
} Graph;

int readInts ( ) {
    char line [ MAX_LINE ];
    fgets ( line , MAX_LINE , stdin );
    int i = 0;
    int n = 0;
    while ( line [ i ] != '\n' ) {
        if ( line [ i ] != ' ' ) {
            n = n * 10 + line [ i ] - '0';
        }
        i++;
    }
    return n;
}

void dfs ( Graph g [ ] , int seen [ ] , int i ) {
    if ( seen [ i ] ) {
        return;
    }
    seen [ i ] = 1;
    int nodes = 1;
    int edges = g [ i ].edges;
    for ( int j = 0 ; j < g [ i ].nodes ; j++ ) {
        dfs ( g , seen , g [ i ].adj [ j ] );
        nodes += g [ g [ i ].adj [ j ] ].nodes;
        edges += g [ g [ i ].adj [ j ] ].edges;
    }
    g [ i ].nodes = nodes;
    g [ i ].edges = edges;
}

int solve ( ) {
    int n = readInts ( );
    int m = readInts ( );
    Graph g [ MAX_NODES ];
    int seen [ MAX_NODES ];
    memset ( seen , 0 , sizeof ( seen ) );
    for ( int i = 0 ; i < MAX_NODES ; i++ ) {
        g [ i ].nodes = 0;
        g [ i ].edges = 0;
        g [ i ].adj = ( int * ) malloc ( MAX_SIZE * sizeof ( int ) );
    }
    for ( int i = 0 ; i < m ; i++ ) {
        int a = readInts ( );
        int b = readInts ( );
        g [ a ].adj [ g [ a ].nodes ] = b;
        g [ a ].nodes++;
        g [ b ].adj [ g [ b ].nodes ] = a;
        g [ b ].nodes++;
    }
    int ans = 0;
    for ( int i = 1 ; i <= n ; i++ ) {
        if ( !seen [ i ] ) {
            dfs ( g , seen , i );
            if ( g [ i ].nodes > 1 && g [ i ].nodes % 2 == 1 && 2 * g [ i ].nodes == g [ i ].edges ) {
                ans++;
            }
        }
    }
    if ( ( n - ans ) % 2 == 1 ) {
        ans++;
    }
    printf ( "%d\n" , ans );
    return 1;
}

int main ( ) {
    while ( solve ( ) ) {
    }
    return 0;
}

