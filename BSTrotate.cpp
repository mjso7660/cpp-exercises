#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

//binary search tree insert&search. Able to rotate to make a balanced BST

class node{
  public:
    int key_value;
    node *left;
    node *right;
    node *parent;
};

class btree{
	public:
		btree();
//		~btree();

		void insert(int key);
		void destroy_tree();
		void inordPrint();
		node *root;
		node *findMax();
		node *findMin();
		void transplant(node *leaf1, node*leaf2);
		void del(node *leaf);
		void right_rotate(node *leaf);

	private:
		void destroy_tree(node *leaf);
		void insert(int key, node *leaf);
		void inordPrint(node* leaf);
		node *findMin(node *leaf);
		node *findMax(node *leaf);

};

btree::btree(){
	root=NULL;
}

void btree::right_rotate(node *leaf){
	node *x=leaf->left;
	if(x!=NULL){
		if(x->right!=NULL){
			x->right->parent=leaf;
			leaf->left=x->right;
		}
		if(leaf->parent!=NULL){
			x->parent=leaf->parent;
			if(leaf==leaf->parent->left){
				leaf->parent->left=x;
			}else{
				leaf->parent->right=x;
			}
		}else{
			root=x;
			x->parent=NULL;
		}
		x->right=leaf;
		leaf->parent=x;
	}
}

//simply changes leaf1 with leaf2
void btree::transplant(node *leaf1, node *leaf2){
	if(leaf1->parent==NULL){
		this->root=leaf2;
	}else if(leaf1==leaf1->parent->left){
		leaf1->parent->left=leaf2;
	}else{
		leaf1->parent->right=leaf2;
	}
	if(leaf2!=NULL){
		leaf2->parent=leaf1->parent;
		leaf1->parent=NULL;
	}
}

//deletion of a node
void btree::del(node* leaf){
	if(leaf->left==NULL && leaf->right==NULL){
		if(leaf==leaf->parent->left){
			leaf->parent->left=NULL;
			transplant(leaf, leaf->right);
		}else{
			cout<<"should print.."<<endl;
			transplant(leaf, leaf->left);
			cout<<"error solved!"<<endl;
		}
	}else if(leaf->left==NULL){
		transplant(leaf,leaf->right);
	}else if(leaf->right==NULL){
		transplant(leaf,leaf->left);
	}else if(leaf->right!=NULL&&leaf->left!=NULL){
		node *y=findMin(leaf->right);
		if(y->parent!=leaf){
			transplant(y,y->right);
			y->right=leaf->right;
			y->right->parent=y;
		}
		transplant(leaf,y);
		y->left=leaf->left;
		y->left->parent=y;
	}else{
		cout<<"error with children"<<endl;
		cout<<leaf->left->key_value<<endl<<leaf->right->key_value<<endl;
	}
}

node *btree::findMin(){
	return findMin(root);
}

node *btree::findMin(node *leaf){
	if(leaf->left!=NULL){
		return findMin(leaf->left);
	}
	return leaf;
}

node *btree::findMax(){
        return findMax(root);
}

node *btree::findMax(node *leaf){
        if(leaf->right!=NULL){
                return findMax(leaf->right);
        }
	return leaf;
}

void btree::inordPrint(){
	inordPrint(root);
}

void btree::inordPrint(node *leaf){
	if(leaf!=NULL){
		if(leaf->left!=NULL){
			inordPrint(leaf->left);
		}
		cout<<leaf->key_value<<" ";
		if(leaf->right!=NULL){
			inordPrint(leaf->right);
		}
	}
}

void btree::insert(int key, node *leaf){
	if(key< leaf->key_value){
		if(leaf->left!=NULL){
			insert(key, leaf->left);
		}else{
			leaf->left=new node;
			leaf->left->key_value=key;
			leaf->left->parent=leaf;
			leaf->left->left=NULL;
			leaf->left->right=NULL;
		}
	}else if(key>= leaf->key_value){
                if(leaf->right!=NULL){
                        insert(key, leaf->right);
                }else{
                        leaf->right=new node;
                        leaf->right->key_value=key;
			leaf->right->parent=leaf;
                        leaf->right->left=NULL;
                        leaf->right->right=NULL;
		}
	}
}

void btree::insert(int key){
	if(root!=NULL){
		insert(key,root);
	}else{
		root=new node;
		root->key_value=key;
		root->parent=NULL;
		root->left=NULL;
		root->right=NULL;
	}
}

int main () {
	btree tree1;
	int i;
	while(cin>>i){
		tree1.insert(i);
	}
	tree1.inordPrint();
	tree1.right_rotate(tree1.root->right);

	//tests below
	cout<<tree1.root->right->right->key_value<<endl;;
	cout<<tree1.root->right->right->left->key_value;
	return 0;
}

