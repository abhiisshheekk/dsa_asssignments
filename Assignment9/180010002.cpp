#include "bits/stdc++.h"

using namespace std;

ofstream off("dijkstra.txt");

class graph {
	int size;
	vector<pair<int,int>> adj_list[100000];
public:
	void add_edge(int u, int v, int w) {
		adj_list[u].emplace_back(make_pair(v,w));
	}
	void sizedef(int n) {
		this->size = n+1;
	}
	void relax(int u, int v, int w, long int *dist) {
		if (dist[v] > dist[u] + w) 
			dist[v] = dist[u] + w;
	}
	void dijkstra(int source) {
		long int dist[size];
		for (int i=0; i<size; i++) {
			dist[i] = INT_MAX;
		}
		dist[source] = 0;
		priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
		pq.emplace(make_pair(0,source));

		while (!pq.empty()) {
			auto u = pq.top();
			pq.pop();
			for (auto v : adj_list[u.second]) {
				relax(u.second,v.first,v.second,dist);
				pq.emplace(make_pair(dist[v.first],v.first));
			}
		}
		for (int i=0; i<size; i++) {
			off << i << " ";
			if (dist[i] != INT_MAX)
				off << dist[i] << endl;
			else off << -1 << endl;	
		}
	}
};

int main(int argc, char ** argv) {

	ifstream iff(argv[1]);
	int u,v,w;
	int sizze = 0;
	int source = atoi(argv[2]);
	graph dj;
	while(!(iff >> u).eof()) {
		iff >> v >> w;
		dj.add_edge(u,v,w);
		if (sizze < max(u,v))
			sizze = max(u,v);
	}
	dj.sizedef(sizze);
	dj.dijkstra(source);
	return 0;
	
}