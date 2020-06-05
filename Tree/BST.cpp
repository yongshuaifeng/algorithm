#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct Node{
    int val;
    Node* parent;
    Node* left;
    Node* right;
    Node(int v):val(v),parent(nullptr),left(nullptr),right(nullptr){}
};

Node* search(Node* bst,int data){
    Node* node;
    if(bst == nullptr) {node = nullptr; return node;}
    if(bst->val == data) return bst;
    else if(bst->val > data) node = search(bst->left,data);
    else if(bst->val < data) node = search(bst->right,data);
    return node;
}

bool find(Node* bst,int data){
    if(search(bst,data)) return true;
    else return false;
}

void insert(Node* bst,Node* p,int data){
    while(true){
       if(bst->val > data) { 
           p =bst; 
           bst = bst->left; 
           if(bst == nullptr)
            {
                bst = new Node(data);
                bst->parent =p;
                p->left = bst;
                break;
            } 
        }
       else if(bst->val < data) { p =bst; bst = bst->right;if(bst == nullptr){bst = new Node(data);bst->parent =p;p->right = bst;break;} }
    }
    return;
}

void Insert(Node*& bst,int data){
    if(search(bst,data) != nullptr) return;
    if(bst == nullptr) {bst = new Node(data);}
    else insert(bst,nullptr,data);//cout<<bst->val<<endl;
    return;
}


void del(Node* bst,int data)
{
    Node* node,*parent;
    node = search(bst,data);//cout<<node->val<<endl;return;
    if(node == nullptr) return;
    
    if(!node->left && !node->right){//cout<<"00"<<endl;
            parent = node->parent;
            if(parent->left == node) {parent->left = nullptr;delete node;}
            if(parent->right == node) {parent->right = nullptr;delete node;}
      
    }else if(!node->left){//cout<<"01"<<endl;
       parent = node;
       node = node->right;
       if(node->left == nullptr){
           swap(parent->val,node->val);
           parent->right = node->right;
           if(node->right) node->right->parent = parent;
           node->right = nullptr;
           node->parent = nullptr;
           delete node;
       }
       else{
           while(node->left) node = node->left;
           swap(parent->val,node->val);
           del(node,node->val);
       }
    }else if(!node->right){//cout<<"10"<<endl;
        parent = node;
        node = node->left;
        if(node->right == nullptr){
            swap(parent->val,node->val);
            parent->left = node->left;
            if(node->left) node->left->parent = parent;
            node->left = nullptr;
            node->parent = nullptr;
        }else{
            while(node->right) node= node->right;
            swap(parent->val,node->val);
            del(node,node->val);
        }
       
    }else{//cout<<"11"<<endl;
        parent = node;
        node = node->left;
        if(node->right == nullptr){
            swap(parent->val,node->val);
            parent->left = node->left;
            if(node->left) node->left->parent = parent;
            node->left = nullptr;
            node->parent = nullptr;
        }else{
            while(node->right) node= node->right;
            swap(parent->val,node->val);
            del(node,node->val);
        }
    }
}

void Del(Node*& bst,int data){
     if(bst->val == data && !bst->left && !bst->right && !bst->parent)
     { delete bst;bst = nullptr;}
     else del(bst,data);
     return;
}


void levelvisit(Node* root){
    cout<<"levelvisit beg:"<<endl;
    queue<Node*> q;
    q.push(root);
    while(q.size()>0){
        Node* node = q.front();
        q.pop();
        cout<<node->val<<" ";
        if(node->left) q.push(node->left);
        if(node->right) q.push(node->right);
    }
    cout<<endl;
    cout<<"levelvisit end:"<<endl;;
    return;
}

void midvisit(Node* root)
{
    if(root == nullptr) return;
    midvisit(root->left);
    cout<<root->val<<" ";
    // if(root->left)
    // cout<<" l:"<<root->left->val;
    // if(root->right)
    // cout<<" r:"<<root->right->val;
    // cout<<endl;
    midvisit(root->right);
    return;
}

int main()
{
    Node* root=nullptr;
    vector<int> tab = {1,2,3,4,5,6,10,3,2,65,92,32,67,7,9,33};
    for(int i = 0;i<tab.size();i++){
        cout<<"²åÈë£º"<<tab[i]<<endl;
        Insert(root,tab[i]);
        midvisit(root);
        cout<<endl;
    }
    cout<<"***********************É¾³ý****************8"<<endl;
    //  cout<<"É¾³ý£º"<<30<<endl;
    //     del(root,30);
    //  midvisit(root);
    for(int i = 0;i<tab.size();i++){
        cout<<"É¾³ý£º"<<tab[i]<<endl;
        Del(root,tab[i]);
        midvisit(root);
        cout<<endl;
    }
    //root = nullptr;
    //if(root == nullptr) cout<<"del root"<<endl;
    return 0;
}


