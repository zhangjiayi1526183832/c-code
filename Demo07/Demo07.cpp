// 队列的数组存储实现

#include <iostream>
using namespace std;
#define MAXSIZE 100
struct QNode {
    //加入元素时rear加1，删除元素时front加1
    int data[MAXSIZE];
    int front;
    int rear;
};
typedef QNode* Queue;

void AddQ(int x, Queue ptrq)
{
    //入队列
    if (ptrq->rear % MAXSIZE == ptrq->front)
        cout << "队列已满" << endl;
    else
    {
        ptrq->rear = (++ptrq->rear) % MAXSIZE;
        ptrq->data[ptrq->rear] = x;
    }
}

int DeleteQ(Queue ptrq)
{
    //出队列
    if (ptrq->front == ptrq->rear)
    {
        cout << "队列为空" << endl;
        return -1;
    }
    else
    {
        int x = ptrq->data[ptrq->front];
        ptrq->front = (ptrq->front++) % MAXSIZE;
        return x;
    }
}
int main()
{
    std::cout << "Hello World!\n";
}

