#include "bits/stdc++.h"

using namespace std;

ofstream of("sd.txt");
ofstream off("ts.txt");

class graph {
	int v;
	vector<int> *adjacency_list;
public:
	int time = 0;
	graph(int size){
		this->v = size;
		adjacency_list = new vector<int>[v];
	}

	void add_edge(int u, int n) {
		adjacency_list[u].emplace_back(n);
	}

	void bfs(int s,int resiz) {
		vector <int> bfs;
		// this->v = resiz+1;
		for (int i=0;i<=resiz;i++) {
			bfs.emplace_back(-1);
		}
		bool visited[v] = {false};
		queue < pair <int,int> > temp;
		auto x = make_pair(s,0);
		visited[s] = true;
		temp.push(x);
		while(!temp.empty()) {
			auto bash = temp.front();
			temp.pop();
			bfs[bash.first] = bash.second;
			for (auto i : adjacency_list[bash.first]) {
				if(visited[i] == false) {
					auto y = make_pair(i,bash.second+1);
					visited[i] = true;
					temp.push(y);
				}
			}
		}
		for (int i=0;i<bfs.size();i++) {
			of << i << " " << bfs[i] << endl;
		}
	}

	void dfs_visit(bool dfs_visited[],int n,vector<int> &visit,vector<pair<int,int>> &finish) {
		dfs_visited[n] = true;
		time += 1;
		visit[n] = time;
		for (auto i : adjacency_list[n]) {
			if(dfs_visited[i] == false)
				dfs_visit(dfs_visited,i,visit,finish);
		}
		time += 1;
		finish.emplace_back( make_pair(n,time) );
	}

	vector<pair<int,int>> dfs(int resiz) {
		bool visit_dfs[resiz] = {false};
		vector<int> visit_time(resiz);
		vector<pair<int,int>> finish_time;
		for (int i=0;i<resiz;i++) {
			if(visit_dfs[i] == false)
				dfs_visit(visit_dfs,i,visit_time,finish_time);
		}
		return finish_time;
	}

	static bool sortinrev(const pair<int,int> &a,const pair<int,int> &b) { 
       return (a.second > b.second); 
	} 

	void topological_sort(int resiz) {
		vector<pair<int,int>> ts = dfs(resiz);
		sort(ts.begin(),ts.end(),sortinrev);
		for(int i=0;i<ts.size();i++) {
			off << ts[i].first << endl;
		}
	}
};

int main(int argc,char **argv) {
	ifstream inf(argv[1]);
	int source = atoi(argv[2]), n_edges = 1e4;
	int size=0;
	graph savgraph(n_edges);
	int u,v;
	while(!(inf>>u).eof()) {
		inf>>v;
		savgraph.add_edge(u,v);
		if(size<max(u,v))
			size = max(u,v);
	}
	// cout << size << endl;
	savgraph.bfs(source,size);
	savgraph.topological_sort(size+1);
}