#include<stdio.h>
int main(){
    int a[2][3]={{1,2,1},{1,1,3}};
    int b[3][2]={{1,1},{1,2},{1,1}};
    int result[2][2]={0};
    int i=0,j;
    while(i!=2){
        for(int k=0;k<3;k++){
            j=0;
            while(j!=2){
                result[i][j]+=a[i][k]*b[k][j];
                ++j;
            }
        }
        ++i;
    }
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            printf("%d ",result[i][j]);
        }
        printf("\n");
    }
}