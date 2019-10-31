#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv) {
	ifstream ist;
	if(argc<2) {
		cout << "No Input file name given." << endl;
		exit(0);
	}
	ist.open(argv[1], ios::in);
	// cout << "fdk" << endl;
	ofstream ost;
	ost.open("output.txt", ios::out);
	int n;
	long long int sum=0;
	vector<int> v;
	while(ist >> n) {
		v.push_back(n);
	}
	if(v.size() != 0) {
		sort(v.begin(),v.end());

		for(auto i : v) {
			sum+=i;
		}

		double avg = (float) sum/v.size();

		ost << v.size() << "\n" << v.front() << "\n" << v.back() << "\n" << sum << "\n" << fixed << setprecision(2) << avg << endl;
	}
	else {
		cout << "File is Empty" << endl;
	}
	return 0;
}