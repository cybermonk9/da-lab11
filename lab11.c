# include <stdio.h>
# include <time.h>
#include<stdlib.h>
int a[15000],b[15000],i,j,k,lb,ub;
void mergesort(int a[], int lb, int ub);
void merge(int a[], int lb, int mid, int ub);
void main()
{
int n;
clock_t st, et;
double ts;
printf("\n Enter the number of array elements: ");
scanf("%d", &n);
printf("\nThe Random Numbers are:\n");
for(i=0; i<n; i++)
{
a[i]=rand()%10000;
printf("%d\t",a[i]);
}
st=clock();
mergesort(a,0,n-1);
et=clock();
ts=((double)(et-st))/CLOCKS_PER_SEC;
printf("\nSorted Numbers are: \n ");
for(i=0; i<n; i++)
{
printf("%d\t", a[i]);
}
printf("\nThe time taken is %lf",ts);
}
void mergesort(int a[], int lb, int ub)
{ int mid;
 if(lb<ub)
 {
 mid = (lb+ub)/2;
 mergesort(a,lb,mid);
 mergesort(a,mid+1,ub);
 merge(a,lb,mid,ub);
 }
}
void merge(int a[], int lb, int mid, int ub)
{ i=lb;
 j=mid+1;
 k=lb;
 while(i<=mid && j<=ub)
 {
 if(a[i]<= a[j])
 {
 b[k] = a[i];
 i++;
 }
 else
 {
 b[k] = a[j];
 j++;
 }
 k++;
 }
 if(i>mid)
 {
 while(j<=ub)
 {
 b[k]=a[j];
 j++;
 k++;
 }
 }
 else
 {
 while(i<=mid)
 {
 b[k]=a[i];
 i++;
 k++;
 }
 }
 for(k=lb; k<=ub; k++)
 {
 a[k] = b[k];
 }
}