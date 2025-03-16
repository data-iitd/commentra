

#include <iostream>
#include <vector>
#include <string>

class CodeforcesTask397BSolution {
public:
    std::string result;
    int t;
    std::vector< std::vector< int > > queries;

    CodeforcesTask397BSolution() {
        read_input();
        process_task();
    }

    void read_input() {
        std::cin >> t;
        for ( int i = 0; i < t; ++i ) {
            std::vector< int > query;
            int a, b, c;
            std::cin >> a >> b >> c;
            query.push_back( a );
            query.push_back( b );
            query.push_back( c );
            queries.push_back( query );
        }
    }

    void process_task() {
        std::vector< std::string > res;
        for ( std::vector< int > query : queries ) {
            int k = query[ 0 ] / query[ 1 ];
            res.push_back( k * query[ 2 ] >= query[ 0 ]? "Yes" : "No" );
        }
        result = "";
        for ( std::string s : res ) {
            result += s + "\n";
        }
    }

    std::string get_result() {
        return result;
    }
};

int main() {
    CodeforcesTask397BSolution solution;
    std::cout << solution.get_result() << std::endl;
    return 0;
}

