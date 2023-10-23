#include<stdio.h>
int ls(int arr[],int z){
    for (size_t j = 0; j < 9; j++)
    {
        //printf("%d",arr[j]);
        if(arr[j]==z){
            printf("Element found at  %d",j);
            return j;
        }
    }
    return -1;

}
void main()
{
    int a[10]={76,34,65,24,98,67,54,23,12,82},x;
    int count=0;
    for (size_t i = 0; i < 10; i++)
    {
        printf("%d\t",a[i]);

    }
    
    printf("\nEnter the num you want:");
    scanf("%d",&x);
    ls(a,x);
    count++;
}