#include "bits/stdc++.h"

using namespace std;


int hashing(string s, int n) {
    int len = s.length();
    int sum = 0;
    for(int i=0; i<len; i++)
        sum += s[i];
    int value = sum % n;
    // cout << s << " " << sum << " " << value << endl;
    return value;
}

int main(int argc, char ** argv){
    ifstream if1(argv[1]);
    ifstream if2(argv[3]);
    ofstream off("anagrams.txt");
    int size = atoi(argv[2]);
    vector<list<string>> hash(size);
    string word;
    while(!(if1 >> word).eof()) {
        int key = hashing(word, size);
        hash[key].emplace_front(word);
    }
    while(!(if2 >> word).eof()) {
        int source = hashing(word, size);
        if(!hash[source].empty()){
            for (auto i = hash[source].begin(); i != hash[source].end(); i++) {
                string str = *i;
                if((str.length() == word.length()) && is_permutation (str.begin(), str.end(), word.begin()))
                    off << str << " ";
            }
            off << endl;
        }
        else {
            off << endl;
        }
    }
    return 0;
}