// 线性表的链表存取实现
#include <iostream>
using namespace std;
class LNode {
public:
    int data;
    LNode* next;
};
typedef LNode* List;
int Length(List ptrl)
{//ptrl 头指针
    int i = 0;
    List p = ptrl;
    while (p)
    {
        p = p->next;
        i++;
    }
    return i;
}
//返回链表的长度

List FindIndex(int i, List ptrl)
{
    List p = ptrl;
    int j = 0;
    for (j=0;p!=nullptr&&j < i; j++)
    {
        p = p->next;
    }
        return p;//如果找到了第i个元素，此时在循环中p指向的的是第i个元素，如果没有第i个元素，此时循环中p指向的是空指针
}
//返回链表的第i个元素指针

List FindValue(int x, List ptrl)
{
    List p = ptrl;
    for (int i = 0; p != nullptr && x != p->data; i++)
    {
        p = p->next;
    }
        return p;//原理同上
}
//返回链表中元素为x的指针

List Insert(int x, int i, List ptrl)
{
    List p = FindIndex(i-1,ptrl);//此时p指向的是插入元素的前一个元素
    List s = new LNode();//s是插入元素的指针
    if (i == 1)
    {
        s->data = x;
        s->next = ptrl;//当插入表头时，此时s所指向的应该是原链表的表头，此时s成为新链表的表头。
        return s;//这里应该返回的是新链表的表头
    }
    if (p == nullptr)
    {
        cout << "找不到第i个位置" << endl;
        return nullptr;//此时没有产生新的链表，返回空指针
    }
    else 
    {
        s->data = x;
        s->next = p->next;
        p->next = s;//两个赋值部分不能交换，否则会出现s->next = s
        return ptrl;//新链表的表头指针不变。返回ptrl。
    }

}
//将x插入到链表的第i个位置

List Delete(int i, List ptrl)
{
    List p = FindIndex(i - 1, ptrl);
    List s;//s指向被删除的元素
    if (i == 1)
    {
        s = ptrl;
        if (ptrl != nullptr)
            ptrl = ptrl->next;
        else
            return nullptr;
        delete s;
        return ptrl;
    }
    if (p == nullptr || p->next == nullptr)
        cout << "第i个结点不存在" << endl;
    else
    {
        s = p->next;
        p->next = s->next;
        delete s;
        return ptrl;
    }
}

int main()
{
}


