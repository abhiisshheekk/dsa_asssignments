#include "bits/stdc++.h"

using namespace std;

int main() {

    priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
		for (int i=0; i<10; i++) {
			if(i == 2)
				pq.emplace(make_pair(0,i));
			else pq.emplace(make_pair(INT_MAX,i));
		}
        cout << pq.top().first << " " << pq.top().second << endl;
}