#include<vector>
#include<queue>
#include<iostream>
#include<stack>

using namespace std;

struct Node
{
   int val;
   Node* left;
   Node* right;
   Node(int v):val(v),left(nullptr),right(nullptr){}
   //Node* bulidTree(const std::vector<int>& v);
};

Node* bulidTree(const std::vector<int>& v)
{
    std::vector<Node*> temp;
    for(int i =0;i<v.size();i++){
        Node* p = new Node(v[i]);
        temp.push_back(p);
    } 

    for(int j =0;j<=(temp.size()/2-1);j++){
        temp[j]->left = temp[2*j+1];
        if(2*j+2 < temp.size())
        temp[j]->right = temp[2*j+2];
    }

    return temp[0];
}

void previsit(Node* root){
    cout<<root->val<<" ";
    if(root->left) previsit(root->left);
    if(root->right) previsit(root->right);
    return;
}

void previsit1(Node* root){
    stack<Node*> st;
    st.push(root);
    while(st.size()>0){
       Node* r = st.top();
       st.pop();
       cout<<r->val<<" ";

       if(r->right) st.push(r->right);
       if(r->left) st.push(r->left);
    }
    return;
}

void midvisit(Node* root){
    if(root->left) midvisit(root->left);
     cout<<root->val<<" ";
    if(root->right) midvisit(root->right);
    return;
}

void midvisit1(Node* root){
    stack<Node*> st;
    while(root){
        st.push(root);
        root = root->left;
    }

    while(st.size()>0){
        Node* r = st.top();
        st.pop();
        cout<<r->val<<" ";

        r = r->right;
        while(r){
            st.push(r);
            r = r->left;
        }
    }

    return;
}

void postvisit(Node* root){
    if(root->left) postvisit(root->left);
    if(root->right) postvisit(root->right);
    cout<<root->val<<" ";
    return;
}

void postvisit1(Node* root){
    stack<Node*> st;
    while(root){
        st.push(root);
       if(root->left) root = root->left;
       else root = root->right;
    }
    while(st.size()>0){
        Node* r = st.top();
        st.pop();
        cout<<r->val<<" ";

        if((st.size()>0) && r == st.top()->left){
            r = st.top()->right;
            while (r)
            {
                st.push(r);
                if(r->left) r = r->left;
                else r = r->right;
            }
            
        }
    }
    return;
}

void levelvisit(Node* root)
{
    queue<Node*> qi;
    qi.push(root);
    while(qi.size()>0){
        Node* r = qi.front();
        cout<<r->val<<" ";
        qi.pop();
        if(r->left) qi.push(r->left);
        if(r->right) qi.push(r->right);
    }

    return;
}


int main()
{
    vector<int> tab = {1,2,3,4,5,6,7,8};
    Node* root;
    root = bulidTree(tab);
    //前序遍历
    cout<<"前序遍历"<<endl;
    previsit1(root);
    cout<<endl;

    //中序遍历
    cout<<"中序遍历"<<endl;
    midvisit1(root);
    cout<<endl;

    //后序遍历
    cout<<"后序遍历"<<endl;
    postvisit1(root);
    cout<<endl;

    //层序遍历
    cout<<"层序遍历"<<endl;
    levelvisit(root);
    cout<<endl;
    



    return 0;
}