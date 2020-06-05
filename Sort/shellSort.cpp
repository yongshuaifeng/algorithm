#include<iostream>
#include<vector>

using namespace std;

void shellsort(vector<int>& tab){
    int len = tab.size()/2;
    
    while(len>=1){
        for(int j = len;j<2*len;j++){
            for(int i = j;i<tab.size();i += len){
                int val = tab[i];
                int p = i-len;
                while(tab[p]>val && p>=0){
                    tab[p+len] = tab[p];
                    p -= len;
                }
                tab[p+len] = val;
            }
        }


        len /= 2;
    }
    return;
}


int main()
{
    vector<int> tab = {10,9,8,7,6,5,4,3,2,1};
    //≈≈–Ú«∞
    cout<<"≈≈–Ú«∞£∫";
    for(int val:tab)
        cout<<val<<" ";
    cout<<endl;

    shellsort(tab);

     //≈≈–Ú∫Û
    cout<<"≈≈–Ú∫Û£∫";
    for(int val:tab)
        cout<<val<<" ";

    return 0;
}