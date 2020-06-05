#include<iostream>
#include<vector>

using namespace std;
void merge(vector<int>& tab,int l,int r)
{
    //if(l==r) return;
    int mid = (l+r)/2;
    //v1(0...mid)
    //v2(mid+1...r);

    //copy
    vector<int> vi;
    for(int i=l;i<=mid;i++)
        vi.push_back(tab[i]);

    int p=l,b1=0,b2=mid+1;
    while(p<=r){
        if(b1>=vi.size()) break;
        else if(b2>r) {tab[p] = vi[b1];b1++;}
        else if(vi[b1]<=tab[b2]){
            tab[p] = vi[b1];
            b1++;
        }
        else if(vi[b1]>tab[b2]){
            tab[p] = tab[b2];
            b2++;
        }
        p++;
    }
    return;
}

void mergeSort(vector<int>& tab,int l,int r){
     if(l==r) return;
     int mid = (l+r)/2;
     mergeSort(tab,l,mid);
     mergeSort(tab,mid+1,r);
     merge(tab,l,r);
     return;
}


int main()
{
    vector<int> tab ={10,9,8,7,6,5,11,4,3,2,1};
    //≈≈–Ú«∞
    cout<<"≈≈–Ú«∞£∫";
    for(int val:tab)
        cout<<val<<" ";
    cout<<endl;

    //
    mergeSort(tab,0,tab.size()-1);
    

    //≈≈–Ú«∞
    cout<<"≈≈–Ú∫Û£∫";
    for(int val:tab)
        cout<<val<<" ";

    return 0;
}