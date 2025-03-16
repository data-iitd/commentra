#include <bits/stdc++.h>
using namespace std;
int main ( ) {
    int n, b;
    cin >> n >> b;
    priority_queue < pair < int, int > > remaining;
    bool running = false;
    int finish_time = 0;
    map < int, int > result;
    for ( int i = 0 ; i < n ; i++ ) {
        int time, duration;
        cin >> time >> duration;
        result [ i ] = 0;
        Task task ( time, duration, i );
        if ( task.time > finish_time && remaining.empty ( ) ) {
            running = true;
            finish_time = task.time + task.duration;
            result [ i ] = finish_time;
        } else {
            if ( task.time >= finish_time &&!remaining.empty ( ) ) {
                pair < int, int > task_to_run = remaining.top ( );
                finish_time = max ( finish_time, task_to_run.first ) + task_to_run.second;
                result [ task_to_run.third ] = finish_time;
                remaining.pop ( );
            }
            if ( remaining.size ( ) < b ) {
                remaining.push ( make_pair ( task.time, task.duration, i ) );
            } else {
                result [ i ] = -1;
            }
        }
    }
    while (!remaining.empty ( ) ) {
        pair < int, int > task_to_run = remaining.top ( );
        finish_time = max ( finish_time, task_to_run.first ) + task_to_run.second;
        result [ task_to_run.third ] = finish_time;
        remaining.pop ( );
    }
    for ( auto key : result ) {
        cout << result [ key ] << endl;
    }
    return 0;
}
