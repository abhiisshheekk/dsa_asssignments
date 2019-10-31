#include <bits/stdc++.h>

using namespace std;

class bst{
 public:
	int strange;
	bst* r_child;
	bst* l_child;
	bst* parent;
	class bst* searchy(bst* joy,int n);
	class bst* successor(bst* up,int n);
	class bst* predecessor(bst* deserve,int n);
};

ofstream ouf("bst.txt");

bst* root=NULL;

class bst* searchy(bst* joy,int n);
class bst* successor(bst* up,int n);
class bst* predecessor(bst* deserve,int n);
void insertit(int n);
void deleteit(int n);
void transplant(bst* thats,bst* it);
void inorderTr(bst* lal);
void preorderTr(bst* lal);
void postorderTr(bst* lal);
int mini();
int maxi();

int main(int argc,char** argv) {
	if(argc<2) {
		cout << "Not enough arguments given!";
	}
	ifstream inp;
	inp.open(argv[1],ios_base::in);
	string command;
	int bash;
	while(!(inp>>command).eof()) {
		if (command == "insert") {
			inp>>bash;
			insertit(bash);
			ouf << bash << " inserted" << endl;
		}
		else if (command == "inorder") {
			bst* kill = root;
			if (kill == NULL)
				ouf << " ";
			else
				inorderTr(kill);
			ouf.seekp(-1,ios_base::cur);
			ouf << endl;
		}
		else if (command == "minimum") {
			if (root == NULL) 
				ouf << endl;
			else {
				int min = mini();
				ouf << min << endl;
			}
		}
		else if (command == "maximum") {
			if (root == NULL) 
				ouf << endl;
			else {
				int max = maxi();
				ouf << max << endl;
			}
		}
		else if (command == "search") {
			inp>>bash;
			bst* sea = root;
			sea = searchy(sea,bash);
			if (sea != NULL) {
				ouf << bash << " found" << endl;
			} else ouf << bash << " not found" << endl;
		}
		else if (command == "successor") {
			inp>>bash;
			bst* bull = root;
			bull = successor(bull,bash);
			if (bull == NULL) {
				ouf << bash << " does not exist" << endl;
			}
			else if (bull->strange == bash)
				ouf << "successor of " << bash << " does not exist" << endl;
			else
				ouf << bull->strange << endl;
		}
		else if (command == "predecessor") {
			inp>>bash;
			bst* eye = root;
			eye = predecessor(eye,bash);
			if (eye == NULL) {
				ouf << bash << " does not exist" << endl;
			}
			else if (eye->strange == bash)
				ouf << "predecessor of " << bash << " does not exist" << endl;
			else
				ouf << eye->strange << endl;
		}
		else if (command == "preorder") {
			bst* kill = root;
			if (kill == NULL)
				ouf << " ";
			else
				preorderTr(kill);
			ouf.seekp(-1,ios_base::cur);
			ouf << endl;
		}
		else if (command == "postorder") {
			bst* kill = root;
			if (kill == NULL)
				ouf << " ";
			else
				postorderTr(kill);
			ouf.seekp(-1,ios_base::cur);
			ouf << endl;
		}
		else if (command == "delete") {
			inp>>bash;
			deleteit(bash);
		}
	}
	ouf.close();
}

void insertit(int n) {
	bst* elem = new bst();
	elem->strange = n;
	elem->l_child = NULL;
	elem->r_child = NULL;
	elem->parent = NULL;
	bst* y = root;
	bst* p = NULL;
	if(y==NULL) {
		root = elem;
	}
	while(y!=NULL) {
		p=y;
		if(n<y->strange) {
			y=y->l_child;
		}
		else y=y->r_child;
	}
	elem->parent = p;
	if(p!=NULL){
		if(n < p->strange) {
			p->l_child = elem;
		}
		else p->r_child = elem;
	}
}

void preorderTr(bst* lal) {
	bst* hell = lal;
	if(hell!=NULL) {
		ouf << hell->strange << " ";
		preorderTr(hell->l_child);
		preorderTr(hell->r_child);
	}
}

void postorderTr(bst* lal) {
	bst* hell = lal;
	if(hell!=NULL) {
		postorderTr(hell->l_child);
		postorderTr(hell->r_child);
		ouf << hell->strange << " ";
	}
}

void inorderTr(bst* lal) {
	bst* hell = lal;
	if(hell!=NULL) {
		inorderTr(hell->l_child);
		ouf << hell->strange << " ";
		inorderTr(hell->r_child);
	}
}

int mini() {
	bst* min = root;
	while (min->l_child != NULL) {
		min = min->l_child;
	}
	return min->strange;
}

int maxi() {
	bst* max = root;
	while (max->r_child != NULL) {
		max = max->r_child;
	}
	return max->strange;
}

class bst* searchy(bst* hit,int num) {
	if (hit!=NULL && hit->strange!=num) {
		if(num<hit->strange){
			return searchy(hit->l_child,num);
		} else return searchy(hit->r_child,num);
	}
	return hit;
}

class bst* successor(bst* cow,int n) {
	bst* suc = searchy(cow,n);
	bst* to;
	if (suc==NULL)
		return suc;
	if (maxi() == n)
		return suc;
	if (suc->r_child != NULL) {
		suc = suc->r_child;
		while (suc->l_child != NULL) {
			suc = suc->l_child;
		}
		return suc;
	}
	to = suc->parent;
	while (to!=NULL && to->r_child == suc) {
		suc = to;
		to = to->parent;
	}
	return to;
}

class bst* predecessor(bst* deserve,int n) {
	bst* nah = searchy(deserve,n);
	bst* yo;
	if (nah==NULL) 
		return nah;
	if (mini() == n)
		return nah;
	if (nah->l_child != NULL) {
		nah = nah->l_child;
		while (nah->r_child != NULL) {
			nah = nah->r_child;
		}
		return nah;
	}
	yo = nah->parent;
	while (yo!=NULL && yo->l_child == nah) {
		nah = yo;
		yo = yo->parent;
	}
	return yo;
	
}

void transplant(bst* thats,bst* it) {
	if (root == thats) 
		root = it;
	else {
		if (thats->parent->l_child == thats)
			thats->parent->l_child = it;
		else thats->parent->r_child = it;
	}
	if (it != NULL)
		it->parent = thats->parent;
}

void deleteit(int kick) {
	bst* del = searchy(root,kick);
	if (del == NULL) {
		ouf << kick << " does not exist" << endl;
		return;
	}
	if (del->l_child == NULL) 
		transplant(del,del->r_child);
	else {
		if (del->r_child == NULL) {
			transplant(del,del->l_child);
		}
		else {
			bst* y = successor(del,del->strange);
			if (y != del->r_child) {
				transplant(y,y->r_child);
				y->r_child = del->r_child;
				del->r_child->parent = y;
			}
			y->l_child = del->l_child;
			del->l_child->parent = y;
			transplant(del,y);
		}
	}
	ouf << kick << " deleted" << endl;
}