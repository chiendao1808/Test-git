#include<iostream>
using namespace std;
template <class T>
class Node{
    public: 
    T data;
    Node* left;
    Node* right;
    Node (T val , Node<T>* l, Node<T>* r )
    {
      this->data=val;
      this->left=l;
      this->right=r;       
    }
    ~Node()
    {
        this->left=NULL;
        this->right=NULL;
    }
};
template<class T>
class BST
{
    private:
    int size;
    Node<T>* root;
    public:
    BST()
    {
        this->root=NULL;
        this->size=0;
    }
    ~BST(){}
    bool isEmpty()
    {
        if (this->root)
        return false;
        else return true;
    }
    // Return size of the BST
    int getSize()
    {
        return this->size;
    }
    //Make the BST empty
    void makeEmpty()
    {
        if(this->root)
        return makeEmpty(this->root);

    }
    void makeEmpty(Node<T>* &t)
    {
        if(t)
        {
            makeEmpty(t->left);
            makeEmpty(t->right);
            delete t;
            t=NULL;
        }
        this->size=0;
    }
    // Insert a node has data = val
    void insert( T val)
    {
         insert(this->root, val);
    }
    void insert(Node<T>* &t, T val)
    {
        if(t==NULL) 
        {
            t = new Node<T>(val,NULL,NULL);
            this->size++;
        }
        else 
        {
            if(val<t->data)
            insert(t->left,val);
            else if (val>t->data)
            insert(t->right, val);
        }
    }
    // Finding a node has data = val
    Node<T>* findNode(T val)
    {
        return findNode(this->root, val);
    }
    Node<T>* findNode(Node<T>* &t,T val)
    {
        if(t)
        {
            if(t->data==val)
            return t;
            else if(t->data>val)
            return findNode(t->left, val);
            else return findNode(t->right, val);
        }
        return NULL;
    }

    // find replaced node for a node has 2 childs
    void findReplaceNode(Node<T> *&tree, Node<T>* &p) 
    {
        if(tree->left)
        {
            findReplaceNode(tree->left,p);
        }
        else
        {
            p->data=tree->data;
            p=tree;
            tree=tree->right;

        }
        // if (tree->right)
        // {
        //     findReplaceNode(tree->right, p);
        // }
        // else{
        //     p->data=tree->data;
        //     p=tree;
        //     tree=tree->left;
        // }
    }
    // Function used to delete a node in BST
    void deleteNode(T val)
    {
        return deleteNode(this->root, val);
    }
    void deleteNode(Node<T>* &t, T val)
    {
        if(t==NULL) return;
        if(val<t->data) deleteNode(t->left, val);
        else if (val>t->data) deleteNode(t->right,val);
        else{
            Node<T>* temp=t;
            if(t->left==NULL) // has one rightchild
            t=t->right;
            else if (t->right==NULL) // has one leftchild
            t=t->left;
            else{
                findReplaceNode(t->right, temp); // 1st method : find the leftmost child of the rightchild
               // findReplaceNode(t->left, temp);// 2nd Method: find the rightmost child of the leftchild
            }
            delete temp;
            this->size--;
        }
    }
};

template<class T>
 void PREORDER_tral(Node<T>* t)
    {
        if(!t) return ;
        else
        {
            cout<<t->data<<" ";
            PREORDER_tral(t->left);
            PREORDER_tral(t->right);
        }
    }

template< class T>
void INORDER_tral( Node<T>* t)
{
    if(!t) return;
    else
    {
        INORDER_tral(t->left);
        cout<<t->data<<" ";
        INORDER_tral(t->right);
    }
}

template<class T>
void POSTORDER_tral( Node<T>* t)
{
    if(!t) return ;
    else
    {
        POSTORDER_tral(t->left);
        POSTORDER_tral(t->right);
        cout<<t->data<<" ";
    }
}
int main()
{
    BST<int> tree1;
    tree1.insert(5);
    tree1.insert(8);
    tree1.insert(2);
    tree1.insert(12);
    tree1.insert(7);
    tree1.insert(14);
    tree1.insert(11);
    tree1.insert(15);
    tree1.insert(13);
    Node<int>* t=tree1.findNode(5);
    tree1.deleteNode(8);
    PREORDER_tral(t);
    cout<<endl;
    INORDER_tral(t);
    cout<<endl;
    POSTORDER_tral(t);
    system("pause");
    return 0;

}
