#include "bits/stdc++.h"

using namespace std;

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
ofstream ot("output.txt",ios_base::out);

int main(int argc,char** argv) {
	if(argc < 3) {
		cout << "Not enough arguments given!" << endl;
		return 0;
	}
	char* file = argv[1];
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