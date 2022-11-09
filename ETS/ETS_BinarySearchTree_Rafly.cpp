#include <iostream>
using namespace std;

// Node
struct Node{
  string famTree;
  Node *left, *right, *parent; // Dalam sebuah Node berisi left, parent, dan right
};

// Variabel pointer global
Node *root, *newNode;

// Create New Tree
void CreateTree( string famTree )
{

  if( root != NULL ) // Mengecek apakah root sudah ada atau belum
    cout << "\nTree sudah dibuat" << endl;
  else{
    root = new Node(); // membuat Node baru
    root->famTree = famTree; // root dinamakan famTree
    root->left = NULL;
    root->right = NULL;
    root->parent = NULL;
    cout << "\n- Node " << famTree << " berhasil dibuat menjadi root." << endl;
  }
}

// insert Left Child
Node *insertLeftChild( string famTree, Node *node )
{
  if( root == NULL ){
    cout << "\n!!! Buat tree terlebih dahulu !!!" << endl;
    return NULL;
  }else{
    // cek apakah anak kiri ada atau tidak
    if( node->left != NULL ){
      // kalau ada
      cout << "\n!! Node "<< node->famTree << " sudah ada anak kiri !!" << endl;
      return NULL;
    }else{
      // kalau tidak ada
      newNode = new Node();
      newNode->famTree = famTree;
      newNode->left = NULL;
      newNode->right = NULL;
      newNode->parent = node;
      node->left = newNode;
      cout << "\n- Node " << famTree << " berhasil ditambahkan ke anak kiri " << newNode->parent->famTree << endl;
      return newNode;
    }
  }
}

// insert right Child
Node *insertRightChild( string famTree, Node *node )
{
  if( root == NULL ){
    cout << "\n!!! Buat tree terlebih dahulu !!!" << endl;
    return NULL;
  }else{
    // cek apakah anak kiri ada atau tidak
    if( node->right != NULL ){
      // kalau ada
      cout << "\n!! Node " << node->famTree << " sudah ada anak kanan !!" << endl;
      return NULL;
    }else{
      // kalau tidak ada
      newNode = new Node();
      newNode->famTree = famTree;
      newNode->left = NULL;
      newNode->right = NULL;
      newNode->parent = node;
      node->right = newNode;
      cout << "\n- Node " << famTree << " berhasil ditambahkan ke anak kanan " << newNode->parent->famTree << endl;
      return newNode;
    }

  }
}

// UpDate
void UpDate(string famTree, Node *node)
{
  if( !root ){
    cout << "\n!!! Buat tree terlebih dahulu !!!" << endl;
  }else{
    if( !node )
      cout << "\n!!! Node yang ingin diganti tidak ada !!!" << endl;
    else{
      string temp = node->famTree;
      node->famTree = famTree;
      cout << "\n>>> UPDATE <<<" << endl;
      cout << "\n- famTree node " << temp << " berhasil diubah menjadi " << famTree << endl;
    }
  }
}

// Describe
void Describe( Node *node )
{
  if( !root ){
    cout << "\n!!! Buat tree terlebih dahulu !!!" << endl;
  }else{
    if( !node )
      cout << "\n!!! Node yang ditunjuk tidak ada !!!" << endl;
    else{


      cout << "\n- famTree Node : " << node->famTree << endl;
      cout << "- Root Node : " << root->famTree << endl;
      
      if( !node->parent )
        cout << "- Parent Node : (tidak punya orang tua)" << endl;
      else
        cout << "- Parent Node : " << node->parent->famTree << endl;



      if( node->parent != NULL && node->parent->left != node && node->parent->right == node )

        cout << "- Saudara : " << node->parent->left->famTree << endl;

      else if( node->parent != NULL && node->parent->right != node && 
      node->parent->left == node )

        cout << "- Saudara : " << node->parent->right->famTree << endl;

      else

        cout << "- Saudara : (tidak punya saudara)" << endl;




      if( !node->left )
        cout << "- Anak Kiri Node : (tidak punya anak kiri)" << endl;
      else
        cout << "- Anak Kiri Node : " << node->left->famTree << endl;

      if( !node->right )
        cout << "- Anak Kanan Node : (tidak punya anak kanan)" << endl;
      else
        cout << "- Anak Kanan Node : " << node->right->famTree << endl;
    }
  }
}

// Tranversal
// preOrder
void preOrder( Node *node = root )
{

  if( !root )
    cout << "\nBuat tree terlebih dahulu!!" << endl;
  else{

    if( node != NULL ){
      cout << node->famTree << ", ";
      preOrder(node->left);
      preOrder(node->right);
    }
  }
}

// inOrder
void inOrder( Node *node = root )
{

  if( !root )
    cout << "\nBuat tree terlebih dahulu!!" << endl;
  else{

    if( node != NULL ){
      inOrder(node->left);
      cout << node->famTree << ", ";
      inOrder(node->right);
    }
  }
}

// postOrder
void postOrder( Node *node = root )
{

  if( !root )
    cout << "\nBuat tree terlebih dahulu!!" << endl;
  else{

    if( node != NULL ){
      postOrder(node->left);
      postOrder(node->right);
      cout << node->famTree << ", ";
    }
  }
}

int main()
{
  cout << "\n>>> TREE CREATION <<<" << endl;
  CreateTree("GGG Grandfather");

  Node *nodeB, *nodeC, *nodeD, *nodeE, *nodeF, *nodeG, *nodeH, *nodeI, *nodeJ, *nodeK, *nodeL, *nodeM;

  nodeB = insertLeftChild("GG Grandfather", root);
  nodeC = insertRightChild("C", root);
  nodeD = insertLeftChild("D", nodeB);
  nodeE = insertRightChild("E", nodeB);
  nodeF = insertLeftChild("F", nodeC);
  nodeG = insertRightChild("G", nodeC);
  nodeH = insertLeftChild("Lahsin", nodeD);
  nodeI = insertRightChild("I", nodeD);
  nodeJ = insertLeftChild("Sugrah", nodeH);
  nodeK = insertRightChild("Ismullah", nodeH);
  nodeL = insertLeftChild("Rafly", nodeJ);
  nodeM = insertRightChild("Farah", nodeJ);
  cout << "\n" << endl;

  UpDate("GreatGrandfather", nodeD);
  cout << "\n" << endl;

  cout << "\n>>> NODE D <<<" << endl;
  Describe(nodeD);
  cout << "\n" << endl;
  
  cout << "\n>>> TRANSVERSAL <<<" << endl;
  cout << "\n- PreOrder :" << endl;
  preOrder();
  cout << "\n" << endl;
  cout << "- InOrder :" << endl;
  inOrder();
  cout << "\n" << endl;
  cout << "- PostOrder :" << endl;
  postOrder();
  cout << "\n" << endl;  











}