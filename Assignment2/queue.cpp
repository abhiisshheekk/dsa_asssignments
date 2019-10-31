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
	n+=1;
	int queue[n];
	int head=0,bash,tail=0;
	char c;
	while ((c=getc(inf)) != EOF) {
		switch(c){
			case '!' : for(int i=head;i!=tail;i=(i+1)%n) {
						   ouf << queue[i] << ' ';
					   }
					   getc(inf);
					   ouf << '\n';
					   break;
			case '+' : if(head==((tail+1)%n)){
					   	   ouf << "overflow" << endl;
					   	   fscanf(inf,"%d",&bash);
					   	   break;
					   }
					   fscanf(inf,"%d",&queue[tail]);
					   ouf << "enqueued " << queue[tail] << endl;
					   tail = (tail+1)%n;
					   break;
			case '-' : if(tail==head) {
					       ouf << "underflow" << endl;
					       fscanf(inf,"%d",&bash);
					       break;
					   }
					   fscanf(inf,"%d",&bash);
					   ouf << "dequeued " << queue[head] << endl;
					   head = (head + 1)%n;
					   break;
			case '?' : fscanf(inf,"%d",&bash);
					   bool flag=false;
					   for (int i=head;i!=tail;i=(i+1)%n) {
					       if(queue[i]==bash){
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