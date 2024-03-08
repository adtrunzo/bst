//----------------------------------------------------------------------------
//----------------------------------------------------------------------------

// two ways to implement a binary search tree...

//----------------------------------------------------------------------------
//----------------------------------------------------------------------------

#ifndef BST_HH
#define BST_HH

#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//----------------------------------------------------------------------------
//----------------------------------------------------------------------------

// the BSTNode class is what we're making the binary search tree out of

template<typename T>
class BSTNode
{
public: 

  BSTNode(T theKey) {key = theKey; left = NULL; right = NULL; number = 1; }
  BSTNode(T theKey, BSTNode<T> *theLeft, BSTNode<T> *theRight) { key = theKey; left = theLeft; right = theRight; number = 1; }

  const T & getKey() { return key; }
  void setKey(T theKey) { key = theKey; }
  
  int getNumber() { return number; }
  void setNumber(){ number = number + 1;}
  BSTNode<T> *getLeft() { return left; }
  void setLeft(BSTNode<T> * theLeft) { left = theLeft; }

  BSTNode<T> *getRight() { return right; }
  void setRight(BSTNode<T> * theRight) { right = theRight; }

  void print() { cout << key << " (" << number << ")" << endl; }
  
  BSTNode<T> *getNew(T & key) {
	BSTNode* newNode = new BSTNode(key);
	return newNode;
}
private:

  T key;

  BSTNode<T> *left;   // link to left child
  BSTNode<T> *right;  // link to right child
  int number;         // how many occurrences of key there are

};

//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
// BSTREE_FAST
//----------------------------------------------------------------------------
//----------------------------------------------------------------------------

// a binary search tree, implemented as a linked structure

// this is only partial--there's no remove functionality, for example

template<typename T>
class BSTree_Fast
{
public:
  //int uniquecount = 0;
  //int totalcount = 0;
  BSTree_Fast() { maxDepth = 0; uniquecount = 0; totalcount = 0; root = NULL; }  // make an empty BST

  void insert(T &);                             // put a key into the BST 
  bool contains(T &);                           // does this BST contain a certain key?
  const T & findMax();                          // what is the smallest key in the BST?
  const T & findMin();
  int getMaxDepth() { return maxDepth; }
  void print();
private:

  int maxDepth;
  int uniquecount;
  int totalcount;
  BSTNode<T> *root;                             // pointer to the node at the root of the tree

};



//----------------------------------------------------------------------------
template <typename T>
void BSTree_Fast<T>::print(){
cout<<"total elements " << totalcount<<"\n";
cout<<"unique elements "<<uniquecount<<"\n";
cout<<"min"<<findMin()<<"\n";
cout<<"max"<<findMax()<<"\n";
}


//--------------------------------------------------------
//

template<typename T>
void BSTree_Fast<T>::insert(T & key)
{
  if(root == NULL){
	//BSTNode <T> 
	* root = BSTNode<T>(key);
	//set key as root
	//root = new BSTNode<T>(key); 
	//root.getNew(key);
	//root = getNew();
	totalcount = totalcount + 1;
	uniquecount = uniquecount + 1;
	}else{
  	if(key < root -> getKey()){
	  BSTNode<T> left = BSTNode<T>(key);
	  root -> setLeft(key); 
	  totalcount = totalcount + 1;
	  uniquecount = uniquecount + 1;
}else if(key > root -> getKey()){
BSTNode<T> right = BSTNode<T>(key);
	root -> setRight(right);
	totalcount = totalcount + 1;
	uniquecount = uniquecount + 1;
}else{
//increase number by 1
//
	root-> setNumber();
	totalcount = totalcount + 1;
}
	
}
}

//----------------------------------------------------------------------------

template<typename T>
bool BSTree_Fast<T>::contains(T & key)
{
BSTNode<T> temp = root;
bool run = true;
while(run){
  if(key > temp){
	temp = temp.getRight();
	if(key == temp){
	run = false;
	return true;
}
}
else if(key < temp){
	temp = temp.getLeft();
	if(key == temp){
	run = false;
	return true;
}
}
else if (key == temp){
run = false;
return true;

}
else{
run = false;
return false; 
}
}
}

//----------------------------------------------------------------------------

// return largest key in BST
// print error and exit if BST is empty
template<typename T>
const T & BSTree_Fast<T>::findMin(){
  
  //new bst node
  BSTNode<T> current = root;
  while(root.getLeft() != NULL){
	//follow the pointers left	
	current = current.getLeft();
}
  return current.getKey(); 
}

//-----------------------------------
//
template<typename T>
const T & BSTree_Fast<T>::findMax()
{
  BSTNode<T> current = root;
  while(root.getRight() != NULL){
 	//follow the pointers  right
 	current = current.getRight();
}
  return current.getKey();
}

//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
// BSTREE_SLOW
//----------------------------------------------------------------------------
//----------------------------------------------------------------------------

// a binary search tree, implemented as an unordered STL vector

// once again, this is only partial

template<typename T>
class BSTree_Slow
{
  
  BSTree_Slow() {unique = 0; total = 0; tree.clear(); }               // make an empty BST

  void insert(T &);                             // put a key into the BST 
  bool contains(T &);                           // does this BST contain a certain key?
  const T & findMax();                          // what is the smallest key in the BST?
  const T & findMin();
  void print(); 
private:
  int unique;
  int total;
  vector < BSTNode<T> * > tree;                 // vector of pointers to nodes in the "tree"

};

//----------------------------------------------------------------------------

template<typename T>
void BSTree_Slow<T>::insert(T & key)
{
  if(tree.contains(key)){
//count + 1;
  total = total + 1;
}else{
  tree.push_back(key);
  total = total + 1;
  unique = unique + 1;
  }
}

//----------------------------------------------------------------------------

template<typename T>
bool BSTree_Slow<T>::contains(T & key)
{
  if(std::cout(tree.begin(), tree.end(), key)){
	return true;
}
  else{
	return false;
}
}

//----------------------------------------------------------------------------

// return largest key in BST
// print error and exit if BST is empty

template<typename T>
const T & BSTree_Slow<T>::findMax()
{
  return *max_element(tree.begin(), tree.end());
}


template<typename T>
const T & BSTree_Slow<T>::findMin(){

  return *min_element(tree.begin(), tree.end());
}

template<typename T>
void BSTree_Slow<T>::print(){
cout<<"max "<<tree.findMax()<<"\n";
cout<<"min "<<tree.findMin()<<"\n";
cout<<"total "<<total<<"\n";
cout<<"unique "<<unique<<"\n";
}
//----------------------------------------------------------------------------
//----------------------------------------------------------------------------

#endif
