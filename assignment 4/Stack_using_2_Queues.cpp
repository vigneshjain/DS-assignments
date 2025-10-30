#include <stdio.h>
#define MAX 50

int Q1[MAX],Q2[MAX];
int f1=-1,r1=-1,f2=-1,r2=-1;

void enqueue1(int x){ if(f1==-1)f1=0; Q1[++r1]=x; }
int dequeue1(){ return Q1[f1++]; }
void enqueue2(int x){ if(f2==-1)f2=0; Q2[++r2]=x; }
int dequeue2(){ return Q2[f2++]; }

void push(int x) {
    enqueue2(x);
    while(f1!=-1 && f1<=r1) enqueue2(dequeue1());
    f1=f2; r1=r2; f2=-1;r2=-1;
    for(int i=f1;i<=r1;i++) Q1[i]=Q2[i]; 
}

void pop() {
    if(f1==-1) printf("Empty\n");
    else printf("Popped %d\n",dequeue1());
}

int main(){
    push(1);push(2);push(3);
    pop(); pop();
    return 0;
}
