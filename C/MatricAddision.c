#include<stdio.h>
void main(){
    int n,a[3][3]={3,6,8,2,6,4,8,1,5},b[3][3]={2,4,6,8,5,6,3,1,7},c[3][3];
    printf("Enter the order of the matrix(within 5): ");
    scanf("%d",&n);
   /*printf("Enter Elements for matrix: \n");
    for (int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            printf("a[%d][%d] = ",i,j);
            scanf("%d",&a[i][j]);
        }
    }
    printf("Enter Elements for 2nd matrix: \n");
    for (int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            printf("b[%d][%d] = ",i,j);
            scanf("%d",&b[i][j]);
        }
    }*/
    int count=0;
    for (int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("c[%d][%d] = %d\n",i,j,a[i][j]+b[i][j]);
            //scanf("%d",&a[i][j]);
            count++;
        }
    }
    printf("Counter = %d\n",count);

}