#include "bits/stdc++.h"

using namespace std;

void stackit(char* file,int n);
void queueit(char* file,int n);
void dllit(char* file);

void insertit(int n);
void printit();
void deleteit(int n);

struct node {
		int strange;
		struct node* next;
		struct node* prev;
};

struct node* searchit(int n);

struct node* head = NULL;
ofstream ot("dll1.txt",ios_base::out);

int main(int argc, char **argv)
{
	if(argc < 3) {
		cout << "Not enough arguments given!" << endl;
		return 0;
	}
	char* file = argv[1];
	int n = stoi(argv[2]);
	stackit(file,n);
	queueit(file,n);
	dllit(file);
	return 0;
}

void stackit(char* file,int n) {
	FILE *inf;
	inf = fopen(file,"r");
	ofstream ouf("stack1.txt",ios_base::out);
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
			case '+' : if(tail==n){												//Condition to check if stack if already full
					   	   ouf << "overflow" << endl;
					   	   fscanf(inf,"%d",&bash);								//To move pointer to next line in the input file
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
}

void queueit(char* file,int n) {
	FILE *inf;
	inf = fopen(file,"r");
	ofstream ouf("queue1.txt",ios_base::out);
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
}

void dllit(char* file) {
	FILE *inf;
	inf = fopen(file,"r");
	char c;
	int hash;
	while ((c=getc(inf)) != EOF) {
		switch(c){
			case '!' : printit();
					   break;
			case '+' : fscanf(inf,"%d",&hash);
					   insertit(hash);
					   ot << "inserted " << hash << endl;
					   break;
			case '-' : fscanf(inf,"%d",&hash);
					   deleteit(hash);
					   break;
			case '?' : fscanf(inf,"%d",&hash);
					   struct node* kaal;
					   kaal = searchit(hash);
					   if(kaal != NULL) {
						   ot << "found " << hash << endl;
					   }
					   else
					   	   ot << "not found " << hash << endl;
					  break;
		}
	}
}

void insertit(int n) {
	node* _node = (struct node*) malloc(sizeof(struct node));
	_node->strange = n;
	_node->next = head;
	_node->prev = NULL;
	if(head != NULL) {
		head->prev = _node;
	}
	head = _node;
}

void printit() {
	struct node* nod;
	nod = head;
	while(nod != NULL){
		ot << nod->strange << ' ';
		nod = nod->next;
	}
	ot << '\n';
}

struct node* searchit(int n) {
	struct node* nal;
	nal = head;
	while(nal!=NULL) {
		if((nal->strange) == n) {
			break;
		}
		nal = nal->next;
	}
	return nal;
}

void deleteit(int n) {
	struct node* nun;
	nun = searchit(n);
	if(nun == NULL) {
		ot << "cannot delete " << n << endl;
		return;
	}
	if((nun->strange == head->strange) && (nun->next == NULL)) {
		head = NULL;
		ot << "deleted " << n << endl;
	}
	else if(nun->strange == head->strange) {
		nun->next->prev = NULL;
		head = nun->next;
		ot << "deleted " << n << endl;
	}
	else if(nun->next == NULL) {
		nun->prev->next == NULL;
		ot << "deleted " << n << endl;
	}
	else {
		nun->next->prev = nun->prev;
		nun->prev->next = nun->next;
		ot << "deleted " << n << endl;
	}
}