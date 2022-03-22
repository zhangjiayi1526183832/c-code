// 堆栈的链式存储 top应该在链表头，在链表尾进行删除操作时，删除后因为是单向链表，找不到前一个结点           

#include <iostream>
using namespace std;
struct SNode {
    char data;
    SNode* next;
};
typedef SNode* Stack;

Stack CreateStack()
{
    //创建一个新的头结点
    Stack s;
    s = new SNode();
    s->next = nullptr;
    return s;
}

bool IsEmpty(Stack s)
{
    //判断堆栈是否为空
    return (s->next == nullptr);
}

void Push(char x, Stack s)
{
    Stack newnode = new SNode();
    newnode->data = x;
    newnode->next = s->next;
    s->next = newnode;
}

char Pop(Stack s)
{
    if (IsEmpty(s))
    {
        cout << "堆栈为空" << endl;
        return '\0';
    }
    else
    {
        Stack firstcell = s->next;
        char x = firstcell->data;
        s->next = firstcell->next;
        delete firstcell;
        return x;
    }
}

//括号匹配问题
bool Match(char a, char b)
{
    //判断两个括号是否匹配
    if (a == '(' && b == ')')
        return true;
    if (a == '[' && b == ']')
        return true;
    if (a == '{' && b == '}')
        return true;
    return false;
}

void BracketMatch(char* str)
{
    Stack s = CreateStack();
    for (size_t i = 0; str[i]!='\0'; i++)
    {
        switch (str[i])
        {
        case '(':
        case '[':
        case '{':
            Push(str[i], s);
            break;
        case ')':
        case ']':
        case '}':
            if (IsEmpty(s))
            {
                cout << "不匹配" << endl;
                return;
            }
            else
            {
                if (Match(Pop(s), str[i]))
                {
                    continue;
                }
                else
                {
                    cout << "不匹配" << endl;
                    return;
                }
            }
        }
        if (IsEmpty(s))
        {
            cout << "匹配" << endl;
            return;
        } 
        else
        {
            cout << "不匹配" << endl;
            return;
        }
            
    }
}
int main()
{
    char c[] = "()[]";
    BracketMatch(c);
}

