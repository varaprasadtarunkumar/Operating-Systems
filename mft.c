 #include <stdio.h>
int n,m,pro[20],par[20],alloc[20],frag[20],finish[20],i,j,k,c,p,ch,sum=0;
int tot,os,use;
/* n= no of partitions
   m= no of processes
   pro[]=array to store process size
   par[]=array to store partition size
   alloc[]=array to indicate whether partition is allocated by a process
   frag[]=array to store internal fragmentation of each partition
   finish[]=array to indicate whether partition is allocated to a process*/
void equal();
void unequal();
void first();
void best();
void worst();
void next();
int main()
{

printf("Enter total memory: ");
scanf("%d",&tot);
printf("Enter OS size: ");
scanf("%d",&os);
use=tot-os;
printf("Usable memory:%d",use);
printf("\nEnter number of partitions:");
scanf("%d",&n);
printf("Enter 1 for equal size partitions else 2:");
scanf("%d",&ch);
switch(ch){
case 1:
equal();
break;
case 2:
unequal();
break;
default:printf("\nEntered invalid option\n");
break;
}
return 0;
}

void equal()
{
printf("Size of each partition= %d",use/n);
for(i=0;i<n;i++)
{
par[i]=use/n;    //allocating equal sizes to all partitions
alloc[i]=-1;
}
printf("\nEnter number of processes:");
scanf("%d",&m);
for(i=0;i<m;i++)
{
printf("\nEnter process %d size:",i+1);
scanf("%d",&pro[i]);
finish[i]=-1;
}
for(i=0;i<m;i++)
{
for(j=0;j<n;j++)
{
if(pro[i]<=par[j] && alloc[j]==-1 && finish[i]==-1)
{
finish[i]=0;
alloc[j]=i;
printf("\n\npartition %d of size %d is allocated to process %d of size %d:",j+1,par[j],i+1,pro[i]);
frag[i]=par[j]-pro[i];
printf("\nInternal fragmentation: %d ",frag[i]);
sum += frag[i];
}
}
if(finish[i]==-1)
printf("\n\npartition cannot be allocated to process %d",i+1);
}
printf("\n\nTotal internal fragmentation:%d",sum);
}

void unequal()
{
printf("Unequal partitioning");
for(i=0;i<m;i++)
{
frag[i]=0;
}
sum=0;
for(i=0;i<n-1;i++)
{
printf("\nEnter partition %d size:",i+1);
scanf("%d",&par[i]);
sum += par[i];
}
for(i=0;i<n;i++)
alloc[i]=-1;
par[n-1]=use-sum;
if(par[n-1]<=0)
{
printf("Invalid partition sizes");
return;
}
printf("\npartition %d size: %d",n,par[n-1]);
printf("\nEnter number of processes:");
scanf("%d",&m);
for(i=0;i<m;i++)
{
printf("Enter process %d size: ",i+1);
scanf("%d",&pro[i]);
finish[i]=-1;
}
printf("\n1.First fit\n2.Best-fit\n3.Worst fit\n4.next-fit\nEnter your choice:");
scanf("%d",&ch);
switch(ch)
{
case 1:
first();
break;
case 2:
best();
break;
case 3:
worst();
break;
case 4:
next();
break;
default:
printf("\nEntered invalid option\n");
break;
}
}

void first()
{
printf("first fit");
sum=0;
for(i=0;i<m;i++)
{
for(j=0;j<n;j++)
{
if(pro[i]<=par[j] && alloc[j]==-1 && finish[i]==-1)
{
finish[i]=0;
alloc[j]=i;
printf("\n\npartition %d of size %d is allocated to process %d of size %d:",j+1,par[j],i+1,pro[i]);
frag[i]=par[j]-pro[i];
printf("\nInternal fragmentation: %d ",frag[i]);
sum += frag[i];
}
}
if(finish[i]==-1)
printf("\n\npartition cannot be allocated to process %d",i+1);
}
printf("\n\nTotal internal fragmentation:%d",sum);
}

void best()
{
//printf("best fit");
sum=0;
for(i=0;i<m;i++)
{
int min=99999;
p=-1;
for(j=0;j<n;j++)
{
if(pro[i]<=par[j] && alloc[j]==-1 && finish[i]==-1)
{
if(min>par[j]-pro[i])
{
min=par[j]-pro[i];
p=j;
}
}
}
if(p>=0){
finish[i]=0;
alloc[p]=i;
printf("\n\npartition %d of size %d is allocated to process %d of size %d:",p+1,par[p],i+1,pro[i]);
frag[i]=par[p]-pro[i];
printf("\nInternal fragmentation: %d ",frag[i]);
sum += frag[i];
}
if(finish[i]==-1)
printf("\n\npartition cannot be allocated to process %d",i+1);
}
printf("\n\nTotal internal fragmentation:%d",sum);
}

void worst()
{
//printf("worst fit");
sum=0;
for(i=0;i<m;i++)
{
int max=-99999;
p=-1;
for(j=0;j<n;j++)
{
if(pro[i]<=par[j] && alloc[j]==-1 && finish[i]==-1)
{
if(max<par[j]-pro[i])
{
max=par[j]-pro[i];
p=j;
}
}
}
if(p>=0){
finish[i]=0;
alloc[p]=i;
printf("\n\npartition %d of size %d is allocated to process %d of size %d:",p+1,par[p],i+1,pro[i]);
frag[i]=par[p]-pro[i];
printf("\nInternal fragmentation: %d ",frag[i]);
sum += frag[i];
}
if(finish[i]==-1)
printf("\n\npartition cannot be allocated to process %d",i+1);
}
printf("\n\nTotal internal fragmentation:%d",sum);
}

void next()
{
//printf("next fit");
sum=0;
printf("\nEnter previous partition position:");
scanf("%d",&p);
for(i=0;i<m;i++)
{
for(j=p;j<n;j++)
{
if(pro[i]<=par[j] && alloc[j]==-1 && finish[i]==-1)
{
finish[i]=0;
alloc[j]=i;
printf("\n\npartition %d of size %d is allocated to process %d of size %d:",j+1,par[j],i+1,pro[i]);
frag[i]=par[j]-pro[i];
printf("\nInternal fragmentation: %d ",frag[i]);
sum += frag[i];
}
}
for(j=0;j<p;j++)
{
if(pro[i]<=par[j] && alloc[j]==-1 && finish[i]==-1)
{
finish[i]=0;
alloc[j]=i;
printf("\n\npartition %d of size %d is allocated to process %d of size %d:",j+1,par[j],i+1,pro[i]);
frag[i]=par[j]-pro[i];
printf("\nInternal fragmentation: %d ",frag[i]);
sum += frag[i];
}
}
if(finish[i]==-1)
printf("\n\npartition cannot be allocated to process %d",i+1);
}
printf("\n\nTotal internal fragmentation:%d",sum);
}


