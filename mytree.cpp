/*implementing binary search tree in c++ and using insert();display() and search() funstion*/


#include<iostream>
using namespace std;

				//creating the node class
	class node{
	public:
		int data;
				//ptr to left and right
		node * left;
		node * right;
				//constructor
	node(int value){
		left=NULL;
		right=NULL;
		data=value;
	}
	};
				//creating class of the tree
	class BiST{
	public:
				//ptr to root
		node * root;
				//constructor
	BiST(){
		root=NULL;
	}
				
				//inserting recursively
				//first creating the main function so that it can be called recursively
	void insertH(node * curr,int value){
				//base casee
				//inserting when tree is empty
	if(curr==NULL){
		curr=new node(value);
				//updating the root
	if(root==NULL)
		root=curr;
	}
				//if value is less than the data of curr
	else if(value<curr->data){
				//linking the curr left
		if(curr->left==NULL)curr->left=new node(value);
				//if curr is not null the go left recursively
		else{
			insertH(curr->left,value);
		}
	}
				//if value is more than data of curr
	else{
				//linking the edge of curr right
		if(curr->right==NULL)curr->right=new node(value);
				//if curr right is not null then go right recursively
		else{
			insertH(curr->right,value);
		}
	}
	}
				//now writing the main insert fucnction using the insertH() recursively
	void insert(int value){
		insertH(root,value);
	}			//displaying the node inOrder
	

				//writting the function that will be called recursively
	void displayH(node * curr){
				//displaying the left side childerns first
				
				//exit condition
		if(curr==NULL){return;}
				//for left side sub trees
		displayH(curr->left);
				//printing the elements only when the ptr points to null
		cout<<curr->data<<"->";
				//for right side childern
		displayH(curr->right);
	}
					
				//real display function
		void display(){
			displayH(root);
		}
				
				//finding an element within the binary tree
				//main searchH function usinf the search function recursively

		
		bool searchH (int value){
			search(root,value);
		}
				//fucntion that will be called recursively
		bool search(node * curr,int value){
				//exit condition
		if(curr==NULL)return false;
		else if(curr->data==value)return true;
				//if value is less than root search left
		else if(value<curr->data) return search(curr->left,value);
				//else search right
		else return search(curr->right,value);
		}
	};
	int main(){
	
	BiST b;
	node*root=NULL;
	b.insert(5);
	b.insert(3);
	b.insert(8);
	b.insert(54);
	b.insert(48);
	b.insert(1);
	b.display();
				//asking user for the number and checking if its available or not
	int num;
	cout<<"\n enter the number to be searched"<<endl;
	cin>>num;
	if(b.searchH(num)==false)cout<<"not found\n";
	else cout<<"found\n";
	



}
		
		
	
		
