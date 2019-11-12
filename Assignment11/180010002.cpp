#include "bits/stdc++.h"

using namespace std;

pair<int,pair<int,int>> extended_euclid(int a, int b) {
    if(b == 0)
        return make_pair(a, make_pair(1, 0));
    else{
        auto half = extended_euclid(b, a%b);
        int d = half.first;
        int x = half.second.second;
        int y = half.second.first - (a/b)*(half.second.second);
        return make_pair(d, make_pair(x, y));
    }
}

int main(int argc, char **argv) {
    int a = atoi(argv[1]);
    int b = atoi(argv[2]);
    auto gcd = extended_euclid(a, b);
    cout << gcd.first << " " << gcd.second.first << " " << gcd.second.second << endl;
    return 0;
}