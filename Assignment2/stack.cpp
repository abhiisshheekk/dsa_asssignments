#include "bits/stdc++.h"

using namespace std;

int main(int argc, char **argv)
{
	if(argc < 3) {
		cout << "Not enough arguments given!" << endl;
		return 0;
	}
	FILE *inf;
	inf = fopen(argv[1],"r");
	ofstream ouf("output.txt",ios_base::out);
	int n = stoi(argv[2]);
	int stack[n];
	int head=0,bash,tail=0;
	char c;
	while ((c=getc(inf)) != EOF) {
		switch(c){
			case '!' : for(int i=tail-1;i>=head;i--) {
						   ouf << stack[i] << ' ';
					   }
					   getc(inf);
					   ouf << '\n';
					   break;
			case '+' : if(tail==n){
					   	   ouf << "overflow" << endl;
					   	   fscanf(inf,"%d",&bash);
					   	   break;
					   }
					   fscanf(inf,"%d",&stack[tail]);
					   ouf << "pushed " << stack[tail] << endl;
					   tail++;
					   break;
			case '-' : if(tail==0) {
					       ouf << "underflow" << endl;
					       fscanf(inf,"%d",&bash);
					       break;
					   }
					   fscanf(inf,"%d",&bash);
					   ouf << "popped " << stack[tail-1] << endl;
					   tail--;
					   break;
			case '?' : fscanf(inf,"%d",&bash);
					   bool flag=false;
					   for (int i=head;i<tail;i++) {
					       if(stack[i]==bash){
					       	   ouf << "found " << bash << endl;
					       	   flag=true;
					       	   break;
					       }
					   }
					   if(flag==false)
					   	   ouf << "not found " << bash << endl;
					   break;
		}
	}

	return 0;
}