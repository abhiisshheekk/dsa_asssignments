#include "bits/stdc++.h"

using namespace std;

template <typename T>
class glass {
    private:
        vector<T> yo;
    public:
        vector<T> mer;
        vector<T> qui;
        void add_elements(T crow) {
            yo.push_back(crow);
        }
        int size_of() {
            mer = yo;
            qui = yo;
            return yo.size();
        }
        void merge(int p,int q,int r) {
            int l[q-p+1+1],m[r-q+1];
            int inf = 1e7;
            for(int i=0;i<=q-p;i++)
                l[i] = mer[p+i];
            for(int i=0;i<=r-q-1;i++)
                m[i] = mer[q+i+1];
            l[q-p+1] = m[r-q] = inf;
            int a=0,b=0;
            for (int i=p;i<=r;i++) {
                if (l[a] < m[b]) {
                    mer[i] = l[a];
                    a+=1;
                }
                else {
                    mer[i] = m[b];
                    b+=1;
                }
            }
        }
        void merge_sort(int p,int r) {
            if (p<r) {
                int q = (p+r)/2;
                merge_sort(p,q);
                merge_sort(q+1,r);
                merge(p,q,r);
            }
        }
        int partition(int p,int r) {
            int x = qui[r];
            int i = p;
            for (int j=p;j<r;j++) {
                if (qui[j] < x) {
                    swap(qui[i],qui[j]);
                    i += 1;
                }
            }
            swap(qui[i],qui[r]);
            return i;
        }
        void quick_sort(int p,int r) {
            if (p<r) {
                int q = partition(p,r);
                quick_sort(p,q-1);
                quick_sort(q+1,r);
            }
        }
};


int main(int argc,char **argv) {
    ifstream inp(argv[1]);
    int bash;
    glass<int> obj;
    while (!(inp>>bash).eof()) {
        obj.add_elements(bash);
    }
    int siz = obj.size_of();
    obj.merge_sort(0,siz-1);
    ofstream of("mergesort.txt");
    for (int i=0;i<siz;i++) {
        of << obj.mer[i] << endl;
    }
    obj.quick_sort(0,siz-1);
    ofstream off("quicksort.txt");
    for (int i=0;i<siz;i++) {
        off << obj.qui[i] << endl;
    }
    return 0;
}
