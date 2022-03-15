//栈的数组存储方式实现

#include <iostream>
using namespace std;
#define MAXSIZE 100
struct SNode {
    int data[MAXSIZE];
    int top;
};
typedef SNode* Stack;

void push(int x, Stack ptrs)
{
    //入栈
    if (ptrs->top == MAXSIZE - 1)
    {
        cout << "堆栈已经满了" << endl;
        return;
    }
    else
    {
        ptrs->top++;
        ptrs->data[ptrs->top] = x;//两个步骤可以简化成  ptrs->data[++（ptrs->top）] = x
        return;
    }
}

int Pop(Stack ptrs)
{
    //出栈
    if (ptrs->top == -1)
    {
        cout << "此时堆栈已空" << endl;
        return -1;//此时-1表示出栈时发生错误
    }
    else
        return ptrs->data[ptrs->top--];   
}

int main()
{
    
}
