#include <iostream>
using namespace std;

template <class T> class Node;
template <class T> class AVLTree;

template <class T>
class Node {

  friend class AVLTree<T>;

private:
  T data;
  Node<T>* parent;
  Node<T>* left;
  Node<T>* right;
  int balanceFactor;

public:
  Node(T d = T(), Node<T>* p =nullptr, Node<T>* l = nullptr, Node<T>* r = nullptr);

};

template <class T>
Node<T>::Node(T d, Node<T>* p, Node<T>* l, Node<T>* r){
  data = d;
  parent = p;
  left = l;
  right = r;
  balanceFactor = 0;
}

template <class T>
class AVLTree {

private:
  Node<T>* root;
  int size;
  int setBalance(Node<T>* node);
  int getHeight(Node<T>* node) const;
  void rebalance(Node<T>* node);
  void rotate(Node<T>* parent);
  void LLR(Node<T>* node);
  void LRR(Node<T>* node);
  void RRR(Node<T>* node);
  void RLR(Node<T>* node);
  void printInOrder(Node<T>* node) const;
  void printPostOrder(Node<T>* node) const;
  void printPreOrder(Node<T>* node) const;
  void printLevelOrder(Node<T>* node) const;
  Node<T>* copy(Node<T>* rhs) const;
  void remove(Node<T>* node);

public:
  AVLTree(): root(nullptr), size(0){}
  AVLTree(const AVLTree<T>& rhs): root(nullptr) { *this = rhs; }
  ~AVLTree();
  AVLTree<T>& operator =(const AVLTree<T>& rhs);

  bool contains(const T& data) const;
  bool isEmpty() const { return size == 0; }
  void clear();
  void insert(T data);
  Node<T>* search(const T& data) const;
  void remove(const T& data) { remove(search(data)); }
  void printInOrder() const { printInOrder(root); }
  void printPostOrder() const { printPostOrder(root); }
  void printPreOrder() const { printPreOrder(root); }
  void printLevelOrder() const { printLevelOrder(root); }
  int getHeight() const { return getHeight(root); }
  int getSize() const { return size; }

};

template <class T>
AVLTree<T>::~AVLTree(){
  clear();
}

template <class T>
AVLTree<T>& AVLTree<T>::operator =(const AVLTree<T>& rhs){
  if (this == &rhs) return *this;
  clear();
  root = copy(rhs.root);
  size = rhs.size;
  return *this;
}

template <class T>
bool AVLTree<T>::contains(const T& data) const {
  if (search(data) == nullptr) return false;
  return true;
}

template <class T>
void AVLTree<T>::clear(){
  while (root != nullptr)
    remove(root);
}

template <class T>
void AVLTree<T>::insert(T data){
  if (root == nullptr){
    root = new Node<T>(data);
    return;
  }
  Node<T>* curr = root;
  Node<T>* prev = curr;
  while (curr != nullptr){
    prev = curr;
    if (data < curr->data)
      curr = curr->left;
    else if (data > curr->data)
      curr = curr->right;
    else
      return;
  }
  size++;
  Node<T>* newNode = new Node<T>(data, prev);
  if (data < prev->data)
    prev->left = newNode;
  else
    prev->right = newNode;

  rebalance(newNode);
}

template <class T>
Node<T>* AVLTree<T>::search(const T& data) const {
  Node<T>* temp = root;
  while (temp != nullptr){
    if (temp->data == data) return temp;
    if (temp->data < data) temp = temp->right;
    else temp = temp->left;
  }
  return nullptr;
}
