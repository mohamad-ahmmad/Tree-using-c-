#pragma once
#include<iostream>
#include<fstream>
using namespace std;


class NODE {
private :
	int data;
	NODE * R_ptr;
	NODE * L_ptr;
	

public:
	NODE() {
		data = 0;
		R_ptr = NULL;
		L_ptr = NULL;
	}
	NODE(int data){
		this->data = data;
		R_ptr = NULL;
		L_ptr = NULL;
	
	}
	~NODE() {

	}
	// get functions
	int getdata() {
		return data;
	}
	NODE* getLptr() {

		return L_ptr;
	}
	NODE* getRptr() {
		return R_ptr;
	}

	//set functions
	void setdata(int data) {
		this->data = data;
	}
	void setLptr(NODE* ptr) {
		L_ptr = ptr;
	}
	void setRptr(NODE* ptr) {
		R_ptr = ptr;
	}

};

class MyBinaryTree {
private :
	NODE * root;
	NODE* insertN(NODE* rot, NODE* node) {

		


		if (rot == NULL) {
			
			rot = node;
			
			return rot;
		}
		if (rot->getdata() > node->getdata()) {
			
			rot->setLptr(insertN(rot->getLptr(), node));
		}
		else {
	
			rot->setRptr(insertN(rot->getRptr(), node));
		}


	}
	void print_inorder(NODE* root) {

		if (root == NULL) {
			return;
		}

		print_inorder(root->getLptr());
		if(root != NULL)
		cout << root->getdata() << " ";
		print_inorder(root->getRptr());

	}
	void PrintsumNodesK (NODE * rot , int k) {
		
	
		if ((rot->getLptr()==NULL)||(rot->getRptr()==NULL) ) {
			return;
		}
		
		if ((rot->getLptr()->getdata()+ rot->getRptr()->getdata())==k) {
			cout << rot->getdata()<<" ";
		}
		PrintsumNodesK(rot->getLptr(), k);
		PrintsumNodesK(rot->getRptr(), k);
	}
	NODE* searchN(NODE* rot, int data) {
		NODE* tmp = rot;
		while (1) {
			if (tmp->getdata() == data)
				return tmp;
			if (tmp->getdata() < data)
				tmp = tmp->getRptr();

			else
				tmp = tmp->getLptr();

		}
	}
	bool found(NODE* rot, int data) {

		bool find = false;

		if (rot == NULL)
			return false;
		if (rot->getdata() == data) {
			find = true;
			
			
		}
		if (!find)
			find = found(rot->getLptr(), data);
		if (!find)
			find = found(rot->getRptr(), data);
		return find;
	}
   
	void print_inrange_priv(NODE* rot, int val1, int val2) {
		if (rot == NULL) {
			return;
		}
		if ((rot->getdata() > val1) && (rot->getdata() < val2)) {
			cout << rot->getdata()<<" ";
		}

		print_inrange_priv(rot->getLptr(),val1,val2);
		print_inrange_priv(rot->getRptr(),val1,val2);
	}
	void printlvl_priv(NODE * root, int k) {
		if (root == NULL)
			return ;

		if (k == 0)
		{
			
			cout << root->getdata() << "---";

		}
	     printlvl_priv(root->getLptr(), k - 1);
		 printlvl_priv(root->getRptr(), k - 1);

	}
	int height(NODE* root)
	{
	
		if (root == NULL) {
			return 0;
		}

		
		return 1 + max(height(root->getLptr()), height(root->getRptr()));
	}
	bool isBalanced_priv(NODE* rot) {
		int l_height;

		int r_height; 

	
		if (rot == NULL)
			return 1;

		
		l_height = height(rot->getLptr());
		r_height = height(rot->getRptr());
	
		if ((abs(l_height - r_height) <= 1) && isBalanced_priv(rot->getLptr()) && isBalanced_priv(rot->getRptr())) {

			return 1;

		}
		
		return 0;
	}
	NODE* creat_node_priv( int data) {

		NODE* ptr = new NODE(data);
		return ptr;

	}
	
public:
	MyBinaryTree() {
		 root = NULL;
		 
	}
	MyBinaryTree(int data) {
		root->setdata(data);
		
	}
	~MyBinaryTree() {

	}
	
	int hight(int data) {
		NODE* p = search(data);
		if (!(found(root , data))) {
			
			return NULL;
		}
		if ((p->getLptr()==NULL)&&(p->getRptr()==NULL)) {
			return 0;
		}

		return  height(p)-1;
	}
	void print_inrange(int val1, int val2) {
		print_inrange_priv(root , val1 , val2);
	}
	NODE* search(int data) {
		if (root == NULL) {
			cout << "Empty Tree." << endl;
			return NULL;
		}

		if (!(found(root,data))) {
		
			cout << "The Node Not Found." << endl;
			return NULL;
		}
		
		return searchN(root,data);

	}
	NODE* creat_node(int data) {
		if (found(root , data)) {
			cout << "Erorr: Already Inserted ,Insert a new Data." << endl;
			return NULL;
		}
		return creat_node_priv( data);
	}
    NODE * insert(NODE * node) {
	 
		return insertN(root, node);
		
	}
	void print_INorder() {
		
		print_inorder(root);

	}
	NODE* get_root() {
		return this->root;
	}
	void set_root(NODE* rot){
		root = rot;
	}
	void PrintSumNodesK( int k) {
		PrintsumNodesK(root , k);
	}
	void print_lv1_to_lv2(int lv1 , int lv2 ) {
		
		if (!((height(root)-1) >= lv2)) {

			cout << "Not Available." << endl;
			return;
		}


		for (int i = lv1;lv1 <= lv2;lv1++) {
			
			printlvl_priv(root, lv1);

		}
	}
	bool isBalanced() {
		

		return isBalanced_priv(root);
	}
	
	
	//OVERLOADED
	ostream& print_overload_inorder(ostream& ou, NODE* root) {

		if (root == NULL) {
			return ou;

			
		}

		print_inorder(root->getLptr());
		ou << root->getdata() << " ";

		print_inorder(root->getRptr());

	
	}
	friend ostream& operator << (ostream &ou , MyBinaryTree T ) {
		
		return T.print_overload_inorder(ou, T.get_root());
	}
	//OVERLOADED
	
};
//
void print_menu(){
cout    << "----------------------Tree Application----------------------\n"
        <<"1-Add More than Node Using Array.\n"
		<<"2-Add a Node.\n"
		<<"3-Print The Tree in Order.\n"
		<<""
		<<"4-Print Nodes With Given Value Range.\n"
		<<"5-Check if The Tree Balanced or no.\n"
		<<"6-Prints All Nodes Where The Sum of Its Children Equal a Given Value.\n"
		<<"7-Prints All Nodes Between Two Levels.\n"
		<<"8-The Height of a Given Node.\n"
		<<"9-Exit\n";


}