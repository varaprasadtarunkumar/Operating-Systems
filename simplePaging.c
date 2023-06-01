
#include<stdio.h>
int main()
{
int psize,pgsize,no_pages,memory,no_frames,log_address,phy_address;
int page_offset,pageno,pgentry;
int pgtable[100];
printf("enter process size:");
scanf("%d",&psize);
printf("enter the page size:");
scanf("%d",&pgsize);
no_pages=psize/pgsize;
printf("no. of pages=%d",no_pages);
printf("enter the physical address space:");
scanf("%d",&memory);
no_frames=memory/pgsize;
printf("no. of frames=%d",no_frames);
printf("enter the page table entries:");
for(int i=0;i<no_pages;i++)
{
scanf("%d",&pgtable[i]);
}
printf("enter the logical address:");
scanf("%d",&log_address);
page_offset=log_address%pgsize;
pageno=log_address/no_pages;
pgentry=pgtable[pageno];
phy_address=(pgentry*pgsize)+page_offset;
printf("the physical address space is:%d",phy_address);
}


