// 队列的链式存储实现

#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};
struct QNode {
    Node* front;
    Node* rear;
};
typedef QNode* Queue;

void AddQ(int x, Queue ptrq)
{
    Node* rearcell = new Node();
    x = rearcell->data;
    rearcell = ptrq->rear->next;
    ptrq->rear = rearcell;
}

int DeleteQ(Queue ptrq)
{
    Node* frontcell;
    int frontitem;
    if (ptrq->front == nullptr)
    {
        cout << "队列为空" << endl;
        return -1;
    }
    if (ptrq->front == ptrq->rear)
    {
        frontcell = ptrq->front;
        frontitem = frontcell->data;
        ptrq->front = nullptr;//当链表只有一个元素时的情况
        ptrq->rear = nullptr;
        return frontitem;
    }   
    else
    {
        frontcell = ptrq->front;
        ptrq->front = frontcell->next;
        frontitem = frontcell->data;
        free(frontcell);
        return frontitem;
    }
}

int main()
{
    std::cout << "Hello World!\n";
}

