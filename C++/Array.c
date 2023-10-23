#include<stdio.h>
void main(){
    int a[5]={1,2,3,4,5},b[5]={9,8,7,6,5},c[5],n,count=0,countm=0;
    printf("Enter the order of the matrix(within 5): ");
    scanf("%d",&n);
    printf("Array after addision: \n");
    for(int i=0;i<n;i++){
        c[i]=a[i]+b[i];
        printf("c[%d]=%d\t",i,c[i]);
        count++;}
    printf("\n\nArray after multiplication:\n ");
    for(int i=0;i<n;i++){
        c[i]=a[i]*b[i];
        printf("c[%d]=%d\t",i,c[i]);
        countm++;
    
    }
    printf("\n\nCounter of array addition: %d\n",count);
    printf("Counter of array multiplication: %d\n",countm);
}