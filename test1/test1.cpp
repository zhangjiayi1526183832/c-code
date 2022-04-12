#include <iostream>
using namespace std;
struct Node
{
    int coef;//系数
    int exp;//指数
    Node* next;
};
typedef Node* Polynomial;

void insertPoly(int c, int e, Polynomial *rear)
{
    Polynomial p = new Node();
    p->coef = c;
    p->exp = e;
    p->next = nullptr;
    (*rear)->next = p;
    *rear = p;
}

Polynomial readPoly()
{
    Polynomial p,rear,t;
    p = new Node();
    p->next = nullptr;
    rear = p;
    cout << "请输入多项式项数" << endl;
    int n;
    cin >> n;
    while (n--)
    {
        int c;
        int e;
        cin >> c >> e;
        insertPoly(c, e, &rear);
    }
    t = p;
    p = p->next;
    delete t;
    return p;
}

Polynomial addPoly(Polynomial p1, Polynomial p2)
{
    Polynomial sum = new Node();
    Polynomial t1 = p1;
    Polynomial t2 = p2;
    Polynomial rear = sum;
    while (t1 && t2)
    {
        if (t1->exp == t2->exp)
        {
            if ((t1->coef + t2->coef) == 0)
            {
                t1 = t1->next;
                t2 = t2->next;
                continue;
            }
            insertPoly(t1->coef + t2->coef, t1->exp, &rear);
            t1 = t1->next;
            t2 = t2->next;
        }
        else if (t1->exp > t2->exp)
        {
            insertPoly(t1->coef, t1->exp, &rear);
            t1 = t1->next;
        }
        else
        {
            insertPoly(t2->coef, t2->exp, &rear);
            t2 = t2->next;
        }
    }
    while (t1)
    {
        insertPoly(t1->coef, t1->exp, &rear);
        t1 = t1->next;
    }
    while (t2)
    {
        insertPoly(t2->coef, t2->exp, &rear);
        t2 = t2->next;
    }
    Polynomial t = sum;
    sum = sum->next;
    delete t;
    return sum;
}

void printPoly(Polynomial p)
{
    while (p)
    {
        cout << p->coef <<" " << p->exp << endl;
        p = p->next;
    }
}

int main()
{
    Polynomial p1, p2, sum;
    cout << "请输入第一个多项式" << endl;
    p1 = readPoly();
    cout << "请输入第二个多项式" << endl;
    p2 = readPoly();
    sum = addPoly(p1, p2);
    cout << "相加之后的多项式为" << endl;
    printPoly(sum);
}

