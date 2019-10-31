#include "bits/stdc++.h"

using namespace std;

void stackit(char* file,int n);
void queueit(char* file,int n);
void dllit(char* file);

void insertit(long long int n);
void printit();
void deleteit(long long int n);

// structure definition for doubly linked list
struct node {
		long long int strange;
		struct node* next;
		struct node* prev;
};

struct node* searchit(long long int n);

struct node* head = NULL;

// creating output file for doubly linked list
ofstream ot("dll.txt",ios_base::out);

int main(int argc, char **argv)
{
	// checking whether enough arguments given or not
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

// function for stack output
void stackit(char* file,int n) {
	FILE *inf;
	inf = fopen(file,"r");
	ofstream ouf("stack.txt",ios_base::out);
	long long int stack[n];
	int head=0,tail=0;
	long long int bash;
	char c;
	while ((c=getc(inf)) != EOF) {
		switch(c){
			case '!' : for(int i=tail-1;i>=head;i--) {
						   ouf << stack[i] << ' ';
					   }
					   getc(inf);
					   ouf << '\n';
					   break;
			case '+' : if(tail==n){												//Condition to check if stack is already full
					   	   ouf << "overflow" << endl;
					   	   fscanf(inf,"%lld",&bash);								//To move pointer to next line in the input file if stack is overflow
					   	   break;
					   }
					   fscanf(inf,"%lld",&stack[tail]);
					   ouf << "pushed " << stack[tail] << endl;
					   tail++;
					   break;
			case '-' : if(tail==0) {											//Condition to check if stack is empty
					       ouf << "underflow" << endl;
					       fscanf(inf,"%lld",&bash);								//To move pointer to next line in the input file if stack is underflow
					       break;
					   }
					   fscanf(inf,"%lld",&bash);
					   ouf << "popped " << stack[tail-1] << endl;
					   tail--;
					   break;
			case '?' : fscanf(inf,"%lld",&bash);
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

// function for queue output
void queueit(char* file,int n) {
	FILE *inf;
	inf = fopen(file,"r");
	ofstream ouf("queue.txt",ios_base::out);
	n+=1;
	long long int queue[n];
	int head=0,tail=0;
	long long int bash;
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
					   	   fscanf(inf,"%lld",&bash);
					   	   break;
					   }
					   fscanf(inf,"%lld",&queue[tail]);
					   ouf << "enqueued " << queue[tail] << endl;
					   tail = (tail+1)%n;
					   break;
			case '-' : if(tail==head) {
					       ouf << "underflow" << endl;
					       fscanf(inf,"%lld",&bash);
					       break;
					   }
					   fscanf(inf,"%lld",&bash);
					   ouf << "dequeued " << queue[head] << endl;
					   head = (head + 1)%n;
					   break;
			case '?' : fscanf(inf,"%lld",&bash);
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

// function for doubly linked list output
void dllit(char* file) {
	FILE *inf;
	inf = fopen(file,"r");
	char c;
	long long int hash;
	while ((c=getc(inf)) != EOF) {
		switch(c){
			case '!' : printit();
					   break;
			case '+' : fscanf(inf,"%lld",&hash);
					   insertit(hash);
					   ot << "inserted " << hash << endl;
					   break;
			case '-' : fscanf(inf,"%lld",&hash);
					   deleteit(hash);
					   break;
			case '?' : fscanf(inf,"%lld",&hash);
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

// function to insert an element in doubly linked list(dll)
void insertit(long long int n) {
	node* _node = (struct node*) malloc(sizeof(struct node));
	_node->strange = n;
	_node->next = head;
	_node->prev = NULL;
	if(head != NULL) {
		head->prev = _node;
	}
	head = _node;
}

// function to print elements of dll
void printit() {
	struct node* nod;
	nod = head;
	while(nod != NULL){
		ot << nod->strange << ' ';
		nod = nod->next;
	}
	ot << '\n';
}

// funtion to search element in dll
struct node* searchit(long long int n) {
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

// function to delete element in dll
void deleteit(long long int n) {
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