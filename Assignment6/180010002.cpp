#include "iostream"
#include "math.h"
#include "vector"
#include "fstream"

using namespace std;

ofstream off("radix.txt");

template <typename T>
class glass {
    private:
        vector<T> yo;
        int crash;
        int size;
    public:
        void add_elements(T crown) {
            yo.push_back(crown);
        }

        int size_of(int nami) {
            crash = nami;
            size = yo.size();
            return size;
        }

        void countingSort(int n) {
            int count[10]={0};
            int output[size];
            int p = (int)pow(10,n);
            // cout << p << endl;
            for (int j=0;j<size;j++)
                count[(yo[j]/p)%10] += 1;
            for (int k=1;k<10;k++) 
                count[k] += count[k - 1];
            for (int j=size-1;j>=0;j--) {
                output[count[(yo[j]/p)%10] - 1] = yo[j]; 
                count[(yo[j]/p)%10] -= 1;
            }
            for (int k=0;k<size;k++) {
                yo[k] = output[k];
            }
        }

        void radixSort() {
            for (int i=0;i<crash;i++) {
                countingSort(i);
            }
        }

        void print_sorted() {
            for (auto i=yo.begin();i != yo.end();i++) {
                off << *i << endl;
            }
        }
};

int main(int argc, char **argv) {
    ifstream inp(argv[1]);
    int bash;
    int trash = atoi(argv[2]);
    glass<int> obj;
    while (!(inp>>bash).eof()) {
        obj.add_elements(bash);
    }
    int siz = obj.size_of(trash);
    obj.radixSort();
    obj.print_sorted();
    return 0;
}