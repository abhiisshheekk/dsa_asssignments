#include "bits/stdc++.h"

using namespace std;

vector<int> v;
vector<int> tem;
ofstream ouf("out.txt");

int parent(int i);
int l_child(int i);
int r_child(int i);
void max_heap_insert(int n);
bool increase_key(int i,int key);
// void build_max_heap();
int maximum();
int extract_max();
void max_heapify(int i);
void heap_sort();
void max_heapify_temp(int i);

int main(int argc, char **argv) {
    ifstream inp(argv[1]);
    int bash;
    string command;
    while (!(inp>>command).eof()) {
        if (command == "insert") {
            inp>>bash;
            max_heap_insert(bash);
            ouf << bash << " inserted" << endl;
        }
        else if (command == "maximum") {
            int max = maximum();
            if (max != -1)
                ouf << max << endl;
            else ouf << endl;
        }
        else if (command == "extract-max") {
            int max = extract_max();
            if (max != -1)
                ouf << max << endl;
            else ouf << endl;
        }
        else if (command == "increase-key") {
            int key;
            inp >> key >> bash;
            // cout << key << " " << bash << " " << v[key] << endl;
            bool what = increase_key(key,bash);
            if (what) 
                ouf << "Key at " << key << " changed to " << bash << endl;
        }
        else if (command == "sort") {
            heap_sort();
        }
        //build_max_heap();
    }
    return 0;
}

int parent(int i) {
    return floor((i-1)/2);
}

int l_child(int i) {
    return 2*i+1;
}

int r_child(int i) {
    return 2*i+2;
}

void max_heap_insert(int n) {
    v.push_back(-1);
    int size = v.size();
    // v[size-1] = -1;
    increase_key(size-1,n);
}

bool increase_key(int i,int key) {
    if (key < v[i]) {
        ouf << key << " is less than the current key at " << i << endl;
        return false;
    }
    v[i] = key;
    while (i>0 && (v[parent(i)] < v[i])) {
        swap(v[i],v[parent(i)]);
        i = parent(i);
    }
    return true;
}

int maximum() {
    if (!v.empty())
        return v[0];
    return -1;
}

int extract_max() {
    if (!v.empty()) {
        int max = v[0];
        int size = v.size();
        v[0] = v[size-1];
        v.pop_back();
        max_heapify(0);
        return max;
    }
    return -1;
}

void max_heapify(int i) {
    int l = l_child(i);
    int r = r_child(i);
    int size = v.size();
    int largest = i;
    if ((l < size) && (v[l] > v[i]))
        largest = l;
    if ((r < size) && (v[r] > v[largest])) 
        largest = r;
    if (largest != i) {
        swap(v[i],v[largest]);
        max_heapify(largest);
    }
}

// void build_max_heap() {
//     int size = v.size();
//     for (int i = parent(size-1);i>=0;i--)
//         max_heapify(i);
// }

void heap_sort() {
    tem = v;
    int size;
    while ((size=tem.size()) > 1) {
        swap(tem[0],tem[size-1]);
        tem.pop_back();
        max_heapify_temp(0);
    }
    for (int i=0;i!=v.size();i++)
        ouf << tem[i] << " ";
    ouf << endl;
}

void max_heapify_temp(int i) {
    int l = l_child(i);
    int r = r_child(i);
    int size = tem.size();
    int largest = i;
    if ((l < size) && (tem[l] > tem[largest]))
        largest = l;
    if ((r < size) && (tem[r] > tem[largest])) 
        largest = r;
    if (largest != i) {
        swap(tem[i],tem[largest]);
        max_heapify_temp(largest);
    }
}