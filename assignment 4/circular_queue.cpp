#include <stdio.h>
#define MAX 50

int CQ[MAX], front=-1, rear=-1;

int isEmpty() { return front==-1; }
int isFull()  { return (front==(rear+1)%MAX); }

void enqueue(int x) {
    if(isFull()) printf("Circular Queue Full\n");
    else {
        if(front==-1) front=0;
        rear=(rear+1)%MAX;
        CQ[rear]=x;
    }
}

void dequeue() {
    if(isEmpty()) printf("Empty\n");
    else {
        printf("Dequeued: %d\n", CQ[front]);
        if(front==rear) front=rear=-1;
        else front=(front+1)%MAX;
    }
}

void peek() {
    if(isEmpty()) printf("Empty\n");
    else printf("Front element: %d\n", CQ[front]);
}

void display() {
    if(isEmpty()) printf("Empty\n");
    else {
        int i=front;
        while(1) {
            printf("%d ",CQ[i]);
            if(i==rear) break;
            i=(i+1)%MAX;
        }
        printf("\n");
    }
}

int main() {
    int choice,x;
    do {
        printf("\n1-Enqueue 2-Dequeue 3-Peek 4-Display 5-Exit: ");
        scanf("%d",&choice);
        switch(choice) {
            case 1: printf("Enter: "); scanf("%d",&x); enqueue(x); break;
            case 2: dequeue(); break;
            case 3: peek(); break;
            case 4: display(); break;
        }
    } while(choice!=5);
    return 0;
}
