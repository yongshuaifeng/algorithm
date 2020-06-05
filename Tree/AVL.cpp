#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct Node{
    int val;
    int height;
    Node* left;
    Node* right;
    Node* parent;
    Node(int v):val(v),height(0),left(nullptr),right(nullptr),parent(nullptr){}
};

Node* search(Node* root,int data){
    while(true){
        if(root == nullptr || root->val == data) break;
        else if(root->val < data) root = root->right;
        else if(root->val > data) root = root->left;
    }
    return root;
}


void Height(Node* node){
    while(node){
        if(!node->left && !node->right) node->height =0;
        else if(!node->left) node->height = node->right->height+1;
        else if(!node->right) node->height = node->left->height+1;
        else if(node->left && node->right) node->height = node->left->height>= node->right->height ?node->left->height+1:node->right->height+1;
        node = node->parent;
    }
    return;
}

void L_R(Node* node){
    Node* p = node->right;
    Node* g = node;
    node = p->right;
    
    swap(p->val,g->val);
    g->right = node;
    node->parent = g;
    p->right = p->left;
    if(p->right) p->right->parent =p;
    p->left = g->left;
    if(p->left) p->left->parent =p;
    g->left = p;

    p->height = 0;
    return;
}

void R_R(Node* node)
{
    Node* p = node->left;
    Node* g = node;
    node = p->left;

    swap(p->val,g->val);
    g->left = node;
    node->parent = g;
    p->left = p->right;
    if(p->left)p->left->parent = p;
    p->right = g->right;
    if(p->right) p->right->parent = p;
    g->right = p;

    p->height=0;
    return;
}

void LR_R(Node* node)
{
    Node* g = node;
    Node* p = node->right;
    node = p->left;

    swap(g->val,p->val);

    g->right = p->left; p->left->parent = g;
    node->right = p->right; p->right->parent = node;
    p->left = g->left;p->left->parent = p;
    p->right = node->left;p->right->parent = p;
    g->left = p;
    node->left = nullptr;

    g->height = 2;
    p->height = 1;
    return;
}

void LL_R(Node* node)
{
    Node* g = node;
    Node* p = node->right;
    node = p->right;

    swap(g->val,p->val);
    g->right = node;node->parent = g;
    p->right = p->left;
    p->left = g->left;p->left->parent = p;
    g->left = p;

    g->height = 2;
    p->height =1;
    
    return;
}

void RR_R(Node* node)
{
    Node* g = node;
    Node* p = node->left;
    node = p->left;

    swap(g->val,p->val);
    g->left = node;node->parent = g;
    p->left = p->right;
    p->right = g->right;p->right->parent = p;
    g->right = p;

    g->height = 2;
    p->height =1;
    
    return;
}

void RL_R(Node* node){
    Node* g = node;
    Node* p = node->left;
    node = p->right;

    swap(g->val,p->val);

    g->left = p->right;p->right->parent = g;
    node->left = p->left;p->left->parent =node;
    p->right = g->right;p->right->parent = p;
    p->left = node->right;p->left->parent =p;
    g->right = p;
    node->right = nullptr;

    g->height = 2;
    p->height = 1;
    return;
}


void DL_R(Node* node)
{
    Node* g = node;
    Node* p = node->right;
    node = p->left;

    swap(g->val,node->val);
    g->left = node;
    p->left= nullptr;
    node->parent = g;
    return;
}

void DR_R(Node* node)
{
    Node* g = node;
    Node* p = node->left;
    node = p->right;

    swap(g->val,node->val);
    g->right = node;
    p->right= nullptr;
    node->parent = g;
    return;
}

void Modify(Node* node){ //cout<<"tiaozheng："<<endl;
    int lh,rh;
    while(node != nullptr){
       if(!node->left) lh =-1;
       else lh = node->left->height;
       if(!node->right) rh = -1;
       else rh = node->right->height;

       if(lh-rh<-1){cout<<" L"<<endl;
           int l,r;
           if(!node->right->left) l =-1;
           else l = node->right->left->height;
           if(!node->right->right) r = -1;
           else r = node->right->right->height;

           if(l-r == -1) {if(node->right->right->right == nullptr)L_R(node); else LL_R(node);}
           else if(l-r == 1) LR_R(node);
           else DL_R(node);

       }else if(lh-rh>1){cout<<" R"<<endl;
           int l,r;
           if(!node->left->left) l =-1;
           else l = node->left->left->height;
           if(!node->left->right) r = -1;
           else r = node->left->right->height;

           if(l-r == -1) {if(node->left->left->left == nullptr)R_R(node);else RR_R(node);}
           else if(l-r == 1) RL_R(node);
           else DR_R(node);
       }//cout<<"parent"<<endl;
        node =node->parent;
    }
    return;
}



void insert(Node* root,int data){
    if(search(root,data)) return;
    Node* parent = nullptr;
    while(true){
       if(root->val < data) {parent = root;root = root->right;if(!root){root = new Node(data);parent->right = root;root->parent = parent;Height(parent);Modify(root);Height(root);break;}}
       else if(root->val > data) {parent = root;root = root->left; if(!root){root = new Node(data);parent->left = root;root->parent = parent;Height(parent);Modify(root);Height(root);break;}}
    }
    return;
}

void Insert(Node*& root,int data){
    if(!root) {root = new Node(data);return;}
    insert(root,data);
    return;
}

void del(Node* root,int data)
{
    Node* parent;
    Node* node;
    node = search(root,data);
    if(node == nullptr) return;
    if(!node->left && !node->right)
    {
        parent = node->parent;
        if(parent->left = node){parent->left = nullptr;node->parent = nullptr;delete node;}
        else{parent->right = nullptr;node->parent = nullptr;delete node;}
        Height(parent);Modify(parent);
    }
    else if(!node->left)
    {
        parent= node;
        node = node->right;
        if(node->left == nullptr){
            swap(node->val,parent->val);
            parent->right = node->right;
            if(parent->right)
            parent->right->parent = parent;
            node->right = nullptr;
            node->parent = nullptr;
            delete node;
            Height(parent);Modify(parent);
        }else{
            while(node->left)
                node = node->left;
            swap(parent->val,node->val);
            del(node,data);
        }

    }
    else if(!node->right)
    {
        parent = node;
        node = node->left;
        if(node->right == nullptr){
            swap(node->val,parent->val);
            parent->left = node->left;
            if(parent->left)
            parent->left->parent = parent;
            node->left = nullptr;
            node->parent = nullptr;
            delete node;
            Height(parent);Modify(parent);
        }else{
            while(node->right)
                node = node->right;
            swap(parent->val,node->val);
            del(node,data);
        }
    }
    else
    {
        parent= node;
        node = node->right;
        if(node->left == nullptr){
            swap(node->val,parent->val);
            parent->right = node->right;
            if(parent->right)
            parent->right->parent = parent;
            node->right = nullptr;
            node->parent = nullptr;
            delete node;
            Height(parent);Modify(parent);
        }else{
            while(node->left)
                node = node->left;
            swap(parent->val,node->val);
            del(node,data);
        }
    }
    
    return;
}

void Del(Node* &root,int data)
{
    if(root->val == data && !root->left && !root->right) {delete root; root =nullptr;}
    else del(root,data);
    return;
}

void inorder(Node* root){
    if(!root) return;
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
    return;
}

void preorder(Node* root){
    if(!root) return;
    cout<<root->val<<" ";
    inorder(root->left);
    inorder(root->right);
    return;
}

void levelvisit(Node* root){
    queue<Node*> q;
    q.push(root);
    while(q.size()>0){
        Node* node = q.front();
        q.pop();
        cout<<node->val<<" ";
        if(node->left) q.push(node->left);
        if(node->right) q.push(node->right);
    }
    return;
}

void inorder_H(Node* root){//return;
    if(!root) return;
    inorder_H(root->left);
    // int l,r;
    // if(!root->left) l =-1;else l = root->left->height;
    // if(!root->right) r = -1;else r = root->right->height;
    //cout<<l-r<<" ";
    cout<<root->height<<" ";
    inorder_H(root->right);
    return;
}

void inorder_B(Node* root){//return;
    if(!root) return;
    inorder_B(root->left);
    int l,r;
    if(!root->left) l =-1;else l = root->left->height;
    if(!root->right) r = -1;else r = root->right->height;
    cout<<l-r<<" ";
    inorder_B(root->right);
    return;
}

int main()
{
    Node* root = nullptr;
    vector<int> vi ={1,2,3,4,5,6,7};
    cout<<"********************插入*************************"<<endl;
    for(int i =0;i<vi.size();i++){
        cout<<"插入："<<vi[i]<<endl;
        Insert(root,vi[i]);
        cout<<"遍历：\t";
        inorder(root);
        cout<<endl;
        levelvisit(root);
        cout<<endl;
        cout<<"高度：\t";
        inorder_H(root);
        cout<<endl;
        cout<<"平衡：\t";
        inorder_B(root);
        cout<<endl;
    }
    cout<<"********************删除*************************"<<endl;
    for(int i =0;i<vi.size();i++){
        cout<<"删除："<<vi[i]<<endl;
        Del(root,vi[i]);
        cout<<"遍历：\t";
        inorder(root);
        cout<<endl;
        levelvisit(root);
        cout<<endl;
        cout<<"高度：\t";
        inorder_H(root);
        cout<<endl;
        cout<<"平衡：\t";
        inorder_B(root);
        cout<<endl;
    }
    return 0;
}