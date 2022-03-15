// 线性表的数组存取实现
#include <iostream>
using namespace std;
#define MAXSIZE 100
class LNode {
public:
    int data[MAXSIZE];
    int Last;//最后一个元素出现的位置
};
typedef LNode* List;
List create()
{
    List ptrl = new LNode;
    ptrl->Last = -1;
    return ptrl;
}
//新建一个空表 默认值为0

void print(List ptrl)
{
    for (int i = 0; i <= ptrl->Last; i++)
    {
        cout << ptrl->data[i] << " ";
    }
}
//打印表

int Find(int x, List ptrl)
{
    for (int i = 0; i < ptrl->Last; i++)
    {
        if (x == ptrl->data[i])
            return i;
    }
    return -1;
}
//在表中查找一个元素，并且返回下标,找不到返回-1

void Insert(int x,int i,List ptrl)
{
    if (ptrl->Last > MAXSIZE - 1)
        cout << "此表已满" << endl;
    else if (i < 1 || i>99)
        cout << "位置不合法" << endl;
    for (int j = ptrl->Last; j >=i-1; j--)
        ptrl->data[j + 1] = ptrl->data[j];
    ptrl->data[i - 1] = x;
    ptrl->Last++;
}
//在第i个位置插入x

void Delete(int i, List ptrl)
{
    for (int j = i; j <= ptrl->Last; j++)
        ptrl->data[j] = ptrl->data[j + 1];
    ptrl->Last--;
    return;
}
//删除第i个位置的元素
int main()
{
    List list = create();
    int i;
    for(i = 0;  i < 10 ; i++)
    {
        list->data[i] = i;
        list->Last++;
    }
    Insert(10, 3, list);
    Delete(8, list);
    print(list);
}


