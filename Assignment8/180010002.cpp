#include "bits/stdc++.h"

using namespace std;

ofstream off("mst.txt");
long unsigned int maxi = 1e5;

class graph {
    int size;
    vector<pair<pair<int,int>,int>> adjacency_list;
public:
    struct disjset{
        int *rank,*parent,n;

        disjset(int n) {
            this->n = n;
            rank = new int[n];
            parent = new int[n];
            for(int i=0; i<n; i++) {
                make_set(i);
            }
        }

        void make_set(int x) {
            parent[x] = x;
            rank[x] = 0;
        }

        int find_set(int u) {
            if (u != parent[u])
                parent[u] = find_set(parent[u]);
            return parent[u];
        }

        void merge(int x,int y) {
            if (rank[x] > rank[y])
                parent[y] = x;
            else {
                parent[x] = y;
                if (rank[x] == rank[y])
                    rank[y]++;
            }
        }

        void union_(int u,int v) {
            merge(find_set(u),find_set(v));
        }
    };

    void add_edge(int u, int v, int w) {
        adjacency_list.push_back(make_pair(make_pair(u,v),w));
    }

    void graphsize(int n) {
        this->size = n+1;
    }

    static bool sortbyweight(const pair<pair<int,int>,int> &a,const pair<pair<int,int>,int> &b) { 
       return (a.second < b.second); 
	} 
    
    void MST_kruskal() {
        sort(adjacency_list.begin(), adjacency_list.end(),sortbyweight);
        disjset ds(size);
        for (auto i = adjacency_list.begin(); i != adjacency_list.end(); i++) {
            int u = i->first.first;
            int v = i->first.second;
            int set_u = ds.find_set(u);
            int set_v = ds.find_set(v);

            if (set_u != set_v) {
                off << u << " " << v << " " << i->second << endl;
                ds.union_(set_u,set_v);
            }
        }
    }
};

int main(int argc, char **argv) {
    ifstream iff(argv[1]);
    int u,v,w;
    int size=0;
    graph weightGraph;
    while(!(iff>>u).eof()) {
        iff >> v >> w;
        weightGraph.add_edge(u,v,w);
        if(size<max(u,v))
            size = max(u,v);
    }
    // cout << size << endl;
    weightGraph.graphsize(size);
    weightGraph.MST_kruskal();
    return 0;
}