//用一个数组实现两个堆栈
#include <iostream>
using namespace std;
#define MAXSIZE 100
struct SNode {
    int data[MAXSIZE];
    int top1;//第一个堆栈的顶
    int top2;//第二个堆栈的顶
};
typedef SNode* Stack;

void Push(int x, Stack ptrs, int flag)
{
    //入栈，flag=1表示进入第一个堆栈
    if (ptrs->top2 - ptrs->top1 == 1)
    {
        cout << "堆栈已满" << endl;
        return;
    }
    if (flag == 1)
        ptrs->data[++ptrs->top1] = x;
    else
        ptrs->data[--ptrs->top2] = x;
    return;
}

int Pop(Stack ptrs, int flag)
{
    if (flag == 1)
    {
        if (ptrs->top1 == -1)
        {
            cout << "堆栈1为空" << endl;
            return -1;
        }
        else
            return ptrs->data[ptrs->top1--];
    }   
    else
    {
        if (ptrs->top2 == MAXSIZE)
        {
            cout << "堆栈2为空" << endl;
            return -1;
        }
        else
            return ptrs->data[ptrs->top2++];
    }
        
}
int main()
{
    
}

