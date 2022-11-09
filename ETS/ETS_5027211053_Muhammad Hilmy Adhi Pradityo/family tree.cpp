#include <iostream>
using namespace std;

// node
struct Node{
  string label;
  Node *left, *right, *parent;
};

// variabel pointer global
Node *root, *newNode;

// create New Tree
void createNewTree( string label ){
  if( root != NULL )
    cout << "\nTree sudah dibuat" << endl;
  else{
    root = new Node();
    root->label = label;
    root->left = NULL;
    root->right = NULL;
    root->parent = NULL;
    cout << "\nNode " << label << " berhasil dibuat menjadi root." << endl;
  }
}

// insert Left
Node *insertLeft( string label, Node *node ){
  if( root == NULL ){
    cout << "\nBuat tree terlebih dahulu!!" << endl;
    return NULL;
  }else{
    // cek apakah anak kiri ada atau tidak
    if( node->left != NULL ){
      // kalau ada
      cout << "\nNode "<< node->label << " sudah ada anak kiri!!" << endl;
      return NULL;
    }else{
      // kalau tidak ada
      newNode = new Node();
      newNode->label = label;
      newNode->left = NULL;
      newNode->right = NULL;
      newNode->parent = node;
      node->left = newNode;
      cout << "\nNode " << label << " berhasil ditambahkan ke anak kiri " << newNode->parent->label << endl;
      return newNode;
    }
  }
}

// insert right
Node *insertRight( string label, Node *node ){
  if( root == NULL ){
    cout << "\nBuat tree terlebih dahulu!!" << endl;
    return NULL;
  }else{
    // cek apakah anak kiri ada atau tidak
    if( node->right != NULL ){
      // kalau ada
      cout << "\nNode " << node->label << " sudah ada anak kanan!!" << endl;
      return NULL;
    }else{
      // kalau tidak ada
      newNode = new Node();
      newNode->label = label;
      newNode->left = NULL;
      newNode->right = NULL;
      newNode->parent = node;
      node->right = newNode;
      cout << "\nNode" << label << " berhasil ditambahkan ke anak kanan " << newNode->parent->label << endl;
      return newNode;
    }
  }
}

// Empty
bool empty(){
  if( root == NULL )
    return true;
  else
    return false;
}

// update
void update(string label, Node *node){
  if( !root ){
    cout << "\nBuat tree terlebih dahulu!!" << endl;
  }else{
    if( !node )
      cout << "\nNode yang ingin diganti tidak ada!!" << endl;
    else{
      string temp = node->label;
      node->label = label;
      cout << "\nLabel node " << temp << " berhasil diubah menjadi " << label << endl;
    }
  }
}

// Tranversal
// preOrder
void preOrder( Node *node = root ){
  if( !root )
    cout << "\nBuat tree terlebih dahulu!!" << endl;
  else{
    if( node != NULL ){
      cout << node->label << ", ";
      preOrder(node->left);
      preOrder(node->right);
    }
  }
}

// inOrder
void inOrder( Node *node = root ){
  if( !root )
    cout << "\nBuat tree terlebih dahulu!!" << endl;
  else{
    if( node != NULL ){
      inOrder(node->left);
      cout << node->label << ", ";
      inOrder(node->right);
    }
  }
}

// postOrder
void postOrder( Node *node = root ){
  if( !root )
    cout << "\nBuat tree terlebih dahulu!!" << endl;
  else{
    if( node != NULL ){
      postOrder(node->left);
      postOrder(node->right);
      cout << node->label << ", ";
    }
  }
}

// size
int size(Node *node = root){
  if( !root ){
    cout << "\nBuat tree terlebih dahulu!!" << endl;
    return 0;
  }else{
    if( !node ){
      return 0;
    }else{
      return 1 + size( node->left ) + size(node->right);
    }
  }
}

// height
int height( Node *node = root ){
  if( !root ){
      cout << "\nBuat tree terlebih dahulu!!" << endl;
      return 0;
    }else{
      if( !node ){
        return 0;
      }else{
        int heightKiri = height( node->left );
        int heightKanan = height( node->right );

        if( heightKiri >= heightKanan ){
          return heightKiri + 1;
        }else{
          return heightKanan + 1;
        }
      }
    }
}

// characteristic
void charateristic(){
  cout << "\nSize Tree : " << size() << endl;
  cout << "Height Tree : " << height() << endl;
  cout << "Average Node of Tree : " << size() / height() << endl;
}

int main(){

  createNewTree("Amin");

  Node *anak1 = insertLeft("Bagas", root);
  Node *anak2 = insertRight("Bagus", root);
  Node *cucu1 = insertLeft("Caca", anak1);
  Node *cucu2 = insertRight("Coki", anak1);
  Node *cucu3 = insertLeft("Ciko", anak2);
  Node *cucu4 = insertRight("Cinta", anak2);
  Node *cicit1 = insertLeft("Dadang", cucu1);
  Node *cicit2 = insertRight("Dida", cucu1);
  Node *cicit3 = insertLeft("Denis", cucu2);
  Node *cicit4 = insertLeft("Derry", cucu3);
  Node *cicit5 = insertRight("Dona", cucu3);
  Node *cicit6 = insertLeft("Dani", cucu4);
  Node *cicit7 = insertRight("Dinda", cucu4);
  Node *canggah1 = insertLeft("Edo", cicit1);
  Node *canggah2 = insertRight("Elisa", cicit1);
  Node *canggah3 = insertLeft("Emil", cicit2);
  Node *canggah4 = insertLeft("Ehsan", cicit5);
  Node *canggah5 = insertRight("Erni", cicit5);
  Node *wareng1 = insertLeft("Fino", canggah2);
  Node *wareng2 = insertRight("Fani", canggah2);
  Node *wareng3 = insertLeft("Farel", canggah5);
  Node *udhek1 = insertLeft("Gimik", wareng3);
  Node *udhek2 = insertRight("Ghea", wareng3);

  cout << "Tree empty? : " << empty() << endl;

  update("Cakra", cucu2);
  cout << "\nPreOrder :" << endl;
  preOrder();
  cout << "\n" << endl;

  update("Dita", cicit5);
  cout << "InOrder :" << endl;
  inOrder();
  cout << "\n" << endl;

  update("Eva", canggah5);
  cout << "PostOrder :" << endl;
  postOrder();
  cout << "\n" << endl;  

  charateristic();
}