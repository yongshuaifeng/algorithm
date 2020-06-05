#include<iostream>
#include<vector>

using namespace std;

int main()
{
    vector<int> tab = {9,8,7,6,5,4,3,2,1};
    cout<<"ÅÅÐòÇ°£º";
    for(int val:tab)
        cout<<val<<" ";
    
    //ÅÅÐò
    for(int i=tab.size()-1;i>0;i--){
        int max = 0;
        for(int j =1;j<=i;j++){
            if(tab[max]<=tab[j])
                max = j;
        }
        swap(tab[i],tab[max]);
    }
    cout<<endl;

    cout<<"ÅÅÐòºó£º";
    for(int val:tab)
        cout<<val<<" ";

    return 0;
}