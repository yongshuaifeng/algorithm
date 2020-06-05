#include<iostream>
#include<vector>

using namespace std;

int main()
{
    vector<int> tab = {10,9,8,7,6,5,4,3,2,1};
    cout<<"ÅÅÐòÇ°£º";
    for(int val:tab)
        cout<<val<<" ";

    for(int i =tab.size()-1;i>0;i--){
        for(int j =0;j<i;j++){
            if(tab[j]>tab[j+1])
                swap(tab[j],tab[j+1]);
        }

    }
    
    cout<<endl;

    cout<<"ÅÅÐòºó£º";
    for(int val:tab)
        cout<<val<<" ";



    return 0;
}