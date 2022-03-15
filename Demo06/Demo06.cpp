// 堆栈的链式存储 top应该在链表头，在链表尾进行删除操作时，删除后因为是单向链表，找不到前一个结点           

#include <iostream>
using namespace std;
struct SNode {
    int data;
    SNode* next;
};
typedef SNode* Stack;

Stack CreateStack()
{
    //创建一个新的头结点
    Stack s;
    s = new SNode();
    s->next == nullptr;
    return s;
}

int IsEmpty(Stack s)
{
    //判断堆栈是否为空
    return (s->next == nullptr);
}

void Push(int x, Stack s)
{
    Stack newnode = new SNode();
    newnode->data = x;
    newnode->next = s->next;
    s->next = newnode;
}

int Pop(Stack s)
{
    if (IsEmpty(s))
    {
        cout << "堆栈为空" << endl;
        return -1;
    }
    else
    {
        Stack firstcell = s->next;
        int x = firstcell->data;
        s->next = firstcell->next;
        delete firstcell;
        return x;
    }
}

int main()
{
    std::cout << "Hello World!\n";
}

