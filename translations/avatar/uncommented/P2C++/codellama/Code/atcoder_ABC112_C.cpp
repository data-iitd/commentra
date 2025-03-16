#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
struct Point {
    int x, y, h;
    Point ( int x = 0 , int y = 0 , int h = 0 ) : x ( x ) , y ( y ) , h ( h ) { }
};
bool operator < ( const Point & p1 , const Point & p2 ) {
    return p1.h < p2.h;
}
int main ( ) {
    int n;
    cin >> n;
    vector < Point > ls_xyh ( n );
    for ( int i = 0 ; i < n ; i ++ ) {
        cin >> ls_xyh [ i ].x >> ls_xyh [ i ].y >> ls_xyh [ i ].h;
    }
    int x0 = 0 , y0 = 0 , h0 = 0;
    for ( int i = 0 ; i < n ; i ++ ) {
        if ( ls_xyh [ i ].h > 0 ) {
            x0 = ls_xyh [ i ].x;
            y0 = ls_xyh [ i ].y;
            h0 = ls_xyh [ i ].h;
            break;
        }
    }
    vector < Point > cands;
    for ( int i = 0 ; i < 101 ; i ++ ) {
        for ( int j = 0 ; j < 101 ; j ++ ) {
            cands.push_back ( Point ( i , j , h0 + abs ( i - x0 ) + abs ( j - y0 ) ) );
        }
    }
    for ( int i = 0 ; i < n ; i ++ ) {
        int x = ls_xyh [ i ].x , y = ls_xyh [ i ].y , h = ls_xyh [ i ].h;
        cands.erase ( remove_if ( cands.begin ( ) , cands.end ( ) , [ & ] ( const Point & p ) {
            return max ( p.h - abs ( p.x - x ) - abs ( p.y - y ) , 0 ) != h;
        } ) , cands.end ( ) );
    }
    sort ( cands.begin ( ) , cands.end ( ) );
    cout << cands [ 0 ].x << ' ' << cands [ 0 ].y << ' ' << cands [ 0 ].h << endl;
    return 0;
}
// 