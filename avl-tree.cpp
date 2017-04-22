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
  //balance factor = (height of right child) - (height of left child)
  int balanceFactor;

public:
  Node(T d = T(), Node<T>* p =nullptr, Node<T>* l = nullptr, Node<T>* r = nullptr);

};

template <class T>
class AVLTree {

private:
  Node<T>* root;
  int size;
  int setBalance(Node<T>* node);
  int getHeight(Node<T>* node) const;
  int getSize(Node<T>* node) const;
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
  AVLTree();
  AVLTree(const AVLTree<T>& rhs);
  ~AVLTree();

  AVLTree<T>& operator =(const AVLTree<T>& rhs);
  bool contains(const T& data) const;
  bool isEmpty() const;
  void clear();
  void insert(T data);
  void remove(const T& data);
  Node<T>* search(const T& data) const;
  void printInOrder() const;
  void printPostOrder() const;
  void printPreOrder() const;
  void printLevelOrder() const;
};








