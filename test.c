#include<stdio.h>

struct hole{
    int size,hid,actual;
};
struct process{
int holeid,size,flag;
};
void bestfit(struct process[],int,struct hole[],int);
int main(){
   struct hole h[10];
   struct process p[10];
   int i,np,nh;

   printf("ENter the number of Holes\n");
   scanf("%d",&nh);
   for(i=0;i<nh;i++){
    printf("Enter the hole H%d\n",i);
    scanf("%d",&h[i].size);
    h[i].hid = i;
   }
   printf("Enter the number of processes\n");
   scanf("%d",&np);
   for(int i=0; i<np; i++){
    printf("Enter the process P%d\n",i);
    scanf("%d",&p[i].size);
p[i].flag=0;
    p[i].size = i;
   }
bestfit(p,np,h,nh);


}

void bestfit(struct process p[],int np,struct hole h[],int nh){
    int i,j;
    for(i=0;i<np;i++){
int bestidx=-1;
        for(j=0;j<nh;j++){
            if(p[i].size<=h[j].size){
              if(bestidx==-1|| h[j].size<h[bestidx].size){
                bestidx=j;
              }
if(bestidx!=-1){
    p[i].flag=1;
    p[i].holeid=h[bestidx].hid;
    h[bestidx].size-=p[i].size;
}

            }
        }
    }
}