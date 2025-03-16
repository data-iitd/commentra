
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_N 100000

int n, k, a[MAX_N], height_from_leaf, cut_count;

void dfs ( int links[MAX_N][MAX_N], int v, int p ) {
    height_from_leaf = 0;
    cut_count = 0;
    for ( int u = 0 ; u < n ; u++ ) {
        if ( links [ v ][u] == 0 ) continue;
        if ( u == 0 ) continue;
        dfs ( links, u, v );
        height_from_leaf = max ( height_from_leaf, height_from_leaf + 1 );
        cut_count += cut_count;
    }
    height_from_leaf++;
    if ( p!= 0 && height_from_leaf == k ) {
        height_from_leaf = 0;
        cut_count++;
    }
}

int main ( ) {
    scanf ( "%d%d", &n, &k );
    for ( int i = 0 ; i < n ; i++ ) {
        scanf ( "%d", &a[i] );
        a[i]--;
    }
    for ( int i = 0 ; i < n ; i++ ) {
        for ( int j = 0 ; j < n ; j++ ) {
            if ( a[i] == a[j] ) {
                a[i] = 0;
                break;
            }
        }
    }
    for ( int i = 0 ; i < n ; i++ ) {
        for ( int j = 0 ; j < n ; j++ ) {
            if ( a[i] == a[j] ) {
                a[i] = 0;
                break;
            }
        }
    }
    for ( int i = 0 ; i < n ; i++ ) {
        for ( int j = 0 ; j < n ; j++ ) {
            if ( a[i] == a[j] ) {
                a[i] = 0;
                break;
            }
        }
    }
    for ( int i = 0 ; i < n ; i++ ) {
        for ( int j = 0 ; j < n ; j++ ) {
            if ( a[i] == a[j] ) {
                a[i] = 0;
                break;
            }
        }
    }
    for ( int i = 0 ; i < n ; i++ ) {
        for ( int j = 0 ; j < n ; j++ ) {
            if ( a[i] == a[j] ) {
                a[i] = 0;
                break;
            }
        }
    }
    for ( int i = 0 ; i < n ; i++ ) {
        for ( int j = 0 ; j < n ; j++ ) {
            if ( a[i] == a[j] ) {
                a[i] = 0;
                break;
            }
        }
    }
    for ( int i = 0 ; i < n ; i++ ) {
        for ( int j = 0 ; j < n ; j++ ) {
            if ( a[i] == a[j] ) {
                a[i] = 0;
                break;
            }
        }
    }
    for ( int i = 0 ; i < n ; i++ ) {
        for ( int j = 0 ; j < n ; j++ ) {
            if ( a[i] == a[j] ) {
                a[i] = 0;
                break;
            }
        }
    }
    for ( int i = 0 ; i < n ; i++ ) {
        for ( int j = 0 ; j < n ; j++ ) {
            if ( a[i] == a[j] ) {
                a[i] = 0;
                break;
            }
        }
    }
    for ( int i = 0 ; i < n ; i++ ) {
        for ( int j = 0 ; j < n ; j++ ) {
            if ( a[i] == a[j] ) {
                a[i] = 0;
                break;
            }
        }
    }
    for ( int i = 0 ; i < n ; i++ ) {
        for ( int j = 0 ; j < n ; j++ ) {
            if ( a[i] == a[j] ) {
                a[i] = 0;
                break;
            }
        }
    }
    for ( int i = 0 ; i < n ; i++ ) {
        for ( int j = 0 ; j < n ; j++ ) {
            if ( a[i] == a[j] ) {
                a[i] = 0;
                break;
            }
        }
    }
    for ( int i = 0 ; i < n ; i++ ) {
        for ( int j = 0 ; j < n ; j++ ) {
            if ( a[i] == a[j] ) {
                a[i] = 0;
                break;
            }
        }
    }
    for ( int i = 0 ; i < n ; i++ ) {
        for ( int j = 0 ; j < n ; j++ ) {
            if ( a[i] == a[j] ) {
                a[i] = 0;
                break;
            }
        }
    }
    for ( int i = 0 ; i < n ; i++ ) {
        for ( int j = 0 ; j < n ; j++ ) {
            if ( a[i] == a[j] ) {
                a[i] = 0;
                break;
            }
        }
    }
    for ( int i = 0 ; i < n ; i++ ) {
        for ( int j = 0 ; j < n ; j++ ) {
            if ( a[i] == a[j] ) {
                a[i] = 0;
                break;
            }
        }
    }
    for ( int i = 0 ; i < n ; i++ ) {
        for ( int j = 0 ; j < n ; j++ ) {
            if ( a[i] == a[j] ) {
                a[i] = 0;
                break;
            }
        }
    }
    for ( int i = 0 ; i < n ; i++ ) {
        for ( int j = 0 ; j < n ; j++ ) {
            if ( a[i] == a[j] ) {
                a[i] = 0;
                break;
            }
        }
    }
    for ( int i = 0 ; i < n ; i++ ) {
        for ( int j = 0 ; j < n ; j++ ) {
            if ( a[i] == a[j] ) {
                a[i] = 0;
                break;
            }
        }
    }
    for ( int i = 0 ; i < n ; i++ ) {
        for ( int j = 0 ; j < n ; j++ ) {
            if ( a[i] == a[j] ) {
                a[i] = 0;
                break;
            }
        }
    }
    for ( int i = 0 ; i < n ; i++ ) {
        for ( int j = 0 ; j < n ; j++ ) {
            if ( a[i] == a[j] ) {
                a[i] = 0;
                break;
            }
        }
    }
    for ( int i = 0 ; i < n ; i++ ) {
        for ( int j = 0 ; j < n ; j++ ) {
            if ( a[i] == a[j] ) {
                a[i] = 0;
                break;
            }
        }
    }
    for ( int i = 0 ; i < n ; i++ ) {
        for ( int j = 0 ; j < n ; j++ ) {
            if ( a[i] == a[j] ) {
                a[i] = 0;
                break;
            }
        }
    }
    for ( int i = 0 ; i < n ; i++ ) {
        for ( int j = 0 ; j < n ; j++ ) {
            if ( a[i] == a[j] ) {
                a[i] = 0;
                break;
            }
        }
    }
    for ( int i = 0 ; i < n ; i++ ) {
        for ( int j = 0 ; j < n ; j++ ) {
            if ( a[i] == a[j] ) {
                a[i] = 0;
                break;
            }
        }
    }
    for ( int i = 0 ; i < n ; i++ ) {
        for ( int j = 0 ; j < n ; j++ ) {
            if ( a[i] == a[j] ) {
                a[i] = 0;
                break;
            }
        }
    }
    for ( int i = 0 ; i < n ; i++ ) {
        for ( int j = 0 ; j < n ; j++ ) {
            if ( a[i] == a[j] ) {
                a[i] = 0;
                break;
            }
        }
    }
    for ( int i = 0 ; i < n ; i++ ) {
        for ( int j = 0 ; j < n ; j++ ) {
            if ( a[i] == a[j] ) {
                a[i] = 0;
                break;
            }
        }
    }
    for ( int i = 0 ; i < n ; i++ ) {
        for ( int j = 0 ; j < n ; j++ ) {
            if ( a[i] == a[j] ) {
                a[i] = 0;
                break;
            }
        }
    }
    for ( int i = 0 ; i < n ; i++ ) {
        for ( int j = 0 ; j < n ; j++ ) {
            if ( a[i] == a[j] ) {
                a[i] = 0;
                break;
            }
        }
    }
    for ( int i = 0 ; i < n ; i++ ) {
        for ( int j = 0 ; j < n ; j++ ) {
            if ( a[i] == a[j] ) {
                a[i] = 0;
                break;
            }
        }
    }
    for ( int i = 0 ; i < n ; i++ ) {
        for ( int j = 0 ; j < n ; j++ ) {
            if ( a[i] == a[j] ) {
                a[i] = 0;
                break;
            }
        }
    }
    for ( int i = 0 ; i < n ; i++ ) {
        for ( int j = 0 ; j < n ; j++ ) {
            if ( a[i] == a[j] ) {
                a[i] = 0;
                break;
            }
        }
    }
    for ( int i = 0 ; i < n ; i++ ) {
        for ( int j = 0 ; j < n ; j++ ) {
            if ( a[i] == a[j] ) {
                a[i] = 0;
                break;
            }
        }
    }
    for ( int i = 0 ; i < n ; i++ ) {
        for ( int j = 0 ; j < n ; j++ ) {
            if ( a[i] == a[j] ) {
                a[i] = 0;
                break;
            }
        }
    }
    for ( int i = 0 ; i < n ; i++ ) {
        for ( int j = 0 ; j < n ; j++ ) {
            if ( a[i] == a[j] ) {
                a[i] = 0;
                break;
            }
        }
    }
    for ( int i = 0 ; i < n ; i++ ) {
        for ( int j = 0 ; j < n ; j++ ) {
            if ( a[i] == a[j] ) {
                a[i] = 0;
                break;
            }
        }
    }
    for ( int i = 0 ; i < n ; i++ ) {
        for ( int j = 0 ; j < n ; j++ ) {
            if ( a[i] == a[j] ) {
                a[i] = 0;
                break;
            }
        }
    }
    for ( int i = 0 ; i < n ; i++ ) {
        for ( int j = 0 ; j < n ; j++ ) {
            if ( a[i] == a[j] ) {
                a[i] = 0;
                break;
            }
        }
    }
    for ( int i = 0 ; i < n ; i++ ) {
        for ( int j = 0 ; j < n ; j++ ) {
            if ( a[i] == a[j] ) {
                a[i] = 0;
                break;
            }
        }
    }
    for ( int i = 0 ; i < n ; i++ ) {
        for ( int j = 0 ; j < n ; j++ ) {
            if ( a[i] == a[j] ) {
                a[i] = 0;
                break;
            }
        }
    }
    for ( int i = 0 ; i < n ; i++ ) {
        for ( int j = 0 ; j < n ; j++ ) {
            if ( a[i] == a[j] ) {
                a[i] = 0;
                break;
            }
        }
    }
    for ( int i = 0 ; i < n ; i++ ) {
        for ( int j = 0 ; j < n ; j++ ) {
            if ( a[i] == a[j] ) {
                a[i] = 0;
                break;
            }
        }
    }
    for ( int i = 0 ; i < n ; i++ ) {
        for ( int j = 0 ; j < n ; j++ ) {
            if ( a[i] == a[j] ) {
                a[i] = 0;
                break;
            }
        }
    }
    for ( int i = 0 ; i < n ; i++ ) {
        for ( int j = 0 ; j < n ; j++ ) {
            if ( a[i] == a[j] ) {
                a[i] = 0;
                break;
            }
        }
    }
    for ( int i = 0 ; i < n ; i++ ) {
        for ( int j = 0 ; j < n ; j++ ) {
            if ( a[i] == a[j] ) {
                a[i] = 0;
                break;
            }
        }
    }
    for ( int i = 0 ; i < n ; i++ ) {
        for ( int j = 0 ; j < n ; j++ ) {
            if ( a[i] == a[j] ) {
                a[i] = 0;
                break;
            }
        }
    }
    for ( int i = 0 ; i < n ; i++ ) {
        for ( int j = 0 ; j < n ; j++ ) {
            if ( a[i] == a[j] ) {
                a[i] =