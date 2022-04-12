// 约瑟夫环问题
#include <iostream>
using namespace std;

struct LNode
{
    int data;
    LNode* next;
};

typedef LNode* LinkedList;
// 尾插法创建循环单链表
//此时n表示在环内的人数
LinkedList create(int n)
{
    LNode* L = new LNode();//L表示头结点
    L->data = 1;
    L->next = L; // 只有一个节点时指向自身成环
    for (int i = 2; i <= n; i++)
    {
        LNode* s = new LNode();//表示插入的元素节点
        s->data = i;
        s->next = L->next;
        L->next = s;
        L = s;//此时s成为新的头结点
    }
    return L;
}

// 删除节点，此时m表示练到m就出列
void nodeDelete(LinkedList& L, int m)
{
    LNode* front = L;//指向报数的前一个元素
    LNode* p = L->next;//指向被删除的元素
    int count = 1;//计数器
    while (p != front)//判断此时场上是否只有一个人
    {
        if (count < m)
        {
            p = p->next;
            front = front->next;
            count++;//没报数到m，数据正常后移
        }
        else
        {
            cout << p->data << " ";//打印出列的序号
            LNode* s=p;
            front->next = p->next;
            p = p->next;
            count = 1;//计数器重置
            delete s;//删除多余空间
        }
    }
    cout << p->data << endl;//打印最后一个人的序号
    delete p;//删除空间
}


int main()
{
    int m, n;
    cout << "请输入m与n" << endl;
    cin >> m >> n;
    LinkedList L = create(n);
    nodeDelete(L, m);
}

