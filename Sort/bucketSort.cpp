#include<iostream>
#include<vector>

using namespace std;

void bucketsort(vector<int>& tab){
    int min=tab[0],max=tab[0];
    for(int i=0;i<tab.size();i++){
        if(min > tab[i]) min = tab[i];
        if(max < tab[i]) max = tab[i];
    }
    int length = max-min;
    vector<int> tem(length+1,0);

    for(int i=0;i<tab.size();i++)
        tem[tab[i]-min]++;
    

    int p =0;
    for(int j=0;j<tem.size();j++)
        while(tem[j]>0){
            tab[p]= j+min;
            tem[j]--;
            p++;
        }

    return;
}


int main()
{
    vector<int> tab = {10,9,8,7,6,5,4,3,2,1,-5};
     //≈≈–Ú«∞
    cout<<"≈≈–Ú«∞£∫";
    for(int val:tab)
        cout<<val<<" ";
    cout<<endl;

    bucketsort(tab);

    //≈≈–Ú∫Û
    cout<<"≈≈–Ú∫Û£∫";
    for(int val:tab)
        cout<<val<<" ";

    return 0;
}