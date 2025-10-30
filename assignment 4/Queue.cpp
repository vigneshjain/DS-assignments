#include <stdio.h>
#define MAX 50

int Q[MAX], front=-1, rear=-1;

int isEmpty() { return front==-1; }
int isFull()  { return rear==MAX-1; }

void enqueue(int x) {
    if(isFull()) printf("Queue is Full\n");
    else {
        if(front==-1) front=0;
        Q[++rear] = x;
    }
}

void dequeue() {
    if(isEmpty()) printf("Queue is Empty\n");
    else {
        printf("Dequeued: %d\n", Q[front]);
        if(front==rear) front=rear=-1;
        else front++;
    }
}

void peek() {
    if(isEmpty()) printf("Queue is Empty\n");
    else printf("Front element: %d\n", Q[front]);
}

void display() {
    if(isEmpty()) printf("Queue Empty\n");
    else {
        for(int i=front; i<=rear; i++) printf("%d ", Q[i]);
        printf("\n");
    }
}

int main() {
    int choice,x;
    do {
        printf("\n1-Enqueue 2-Dequeue 3-Peek 4-Display 5-Exit: ");
        scanf("%d",&choice);
        switch(choice) {
            case 1: printf("Enter value: "); scanf("%d",&x); enqueue(x); break;
            case 2: dequeue(); break;
            case 3: peek(); break;
            case 4: display(); break;
        }
    } while(choice!=5);
    return 0;
}
