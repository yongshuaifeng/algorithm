#include<iostream>
#include<vector>

using namespace std;
int main()
{
    vector<int> tab ={10,9,8,11,7,6,5,5,4,3,2,1};
    //vector<int> tab ={1,2,3,4,5,6};

    //≈≈–Ú«∞
    cout<<"≈≈–Ú«∞£∫";
    for(int val:tab)
        cout<<val<<" ";
    cout<<endl;

    for(int i=1;i<tab.size();i++){
        int p =i-1;
        int val = tab[i];
        while(tab[p]>val && p>=0)
           {tab[p+1] = tab[p]; p--;}

        tab[p+1] = val;
    }

     //≈≈–Ú∫Û
    cout<<"≈≈–Ú∫Û£∫";
    for(int val:tab)
        cout<<val<<" ";

    return 0;
}