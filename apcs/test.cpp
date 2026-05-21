#include<bits/stdc++.h>
using namespace std;
int Num[105][105];
int main(){
    int r,c,h,k,m,a,b,s,d,i,i2,i3,Max=-10000,Min=10000,num=0,key;
    cin>>r>>c>>h>>k;
    vector<vector<int>>deep(r,vector<int>(c,h));
    for(i=0;i<k;i++){
        cin>>a>>b;
        Num[a][b]+=1;
    }
    cin>>m;
    for(i=0;i<m;i++){
        cin>>a>>b>>s>>d;
        key=0;
        for(i2=a-(s/2);i2<=a+(s/2);i2++){
            for(i3=b-(s/2);i3<=b+(s/2);i3++){
                if(i2<0||i2>r-1||i3<0||i3>c-1) continue;
                if(Num[i2][i3]!=0){
                    Num[i2][i3]=0;
                    key=1;
                }
            }
        }
        if(key==0){
            for(i2=a-(s/2);i2<=a+(s/2);i2++){
                for(i3=b-(s/2);i3<=b+(s/2);i3++){
                    if(i2<0||i2>r-1||i3<0||i3>c-1) continue;
                    deep[i2][i3]-=d;
                }
            }
        }
    }
    for(i2=0;i2<r;i2++){
        for(i3=0;i3<c;i3++){
            Max=max(Max,deep[i2][i3]);
            Min=min(Min,deep[i2][i3]);
            num+=Num[i2][i3];
         }
    }
    cout<<Max<<" "<<Min<<" "<<num;
}