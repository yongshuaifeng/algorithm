#include<iostream>
#include<vector>

using namespace std;


void quickSort(vector<int>& tab,int l,int r)
{
    if(r<=l) return;
    int val = tab[l];
    int beg=l,end=r;

    while(beg<end){
        while(beg<end && tab[beg]<=val) beg++;
        while(beg<end && tab[end]>=val) end--;
        if(tab[beg]>val && tab[end]<val)
            swap(tab[beg],tab[end]);
    }

    //  cout<<beg<<" "<<end<<endl;
    //  cout<<tab[beg]<<endl;
    
    //cout<<beg<<" "<<end<<endl;
    int p;
    if(beg==r && end==r)
       { swap(tab[l],tab[r]); p = r;}
    else if(beg==l+1 && end==l+1)
        {swap(tab[l],tab[l]); p =l;}
    else 
       { swap(tab[l],tab[beg]); p =beg;}
   
    //if(l<end-1)
    quickSort(tab,l,p-1);
    //if(end+1<r)
    quickSort(tab,p+1,r);

    return;
}


int main()
{
    vector<int> tab = {9,8,7,6,5,4,3,2,1};
    //≈≈–Ú«∞
    cout<<"≈≈–Ú«∞£∫";
    for(int val:tab)
        cout<<val<<" ";
    cout<<endl;

    quickSort(tab,0,tab.size()-1);

    //≈≈–Ú∫Û
    cout<<"≈≈–Ú∫Û£∫";
    for(int val:tab)
        cout<<val<<" ";



    return 0;
}