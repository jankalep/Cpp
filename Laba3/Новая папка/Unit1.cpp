#include <iostream.h>
#include <math.h>
#include <iomanip.h>
#include <vcl.h>
int main()
{
double **a;
int n,i,j,s,m;
cout<<"Vvedite n:"<<endl;
cin>>n;
n+=1;
cout<<"Vvedite m:"<<endl;
cin>>m;
m+=1;
a=new double*[n];
for(i=1;i<n;i++)
a[i]=new double[m];
for(i=1;i<n;i++)
for(j=1;j<n;j++)
{
cout<<"Vvedite a["<<i<<"]["<<j<<"] "<<setw(2);
cin>>a[i][j];
}
for(i=1;i<n;i++)
{
for(j=1;j<m;j++)
cout<<setw(2)<<a[i][j];
cout<<endl;
}
s=0;
for(i=1;i<n;i++)
{
for(j=2;j<m-1;j++)
if ((a[i][j-1] < a[i][j]) && (a[i][j] < a[i][j+1]))
s+=1;
}
cout<<"V matrice "<<s<<" osobyh elementov"<<endl;
for(i=1;i<n;i++)
delete [] a[i];
delete []a;
a=NULL;
Sleep(100000);
}
