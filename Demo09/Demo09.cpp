#include <iostream>
using namespace std;
struct PolyNode
{
	int coef;//系数
	int expon;//指数
	PolyNode* next;
};
typedef PolyNode* Polynomial;
int main()
{
	Polynomial p1, p2, pp, ps;
	p1 = ReadPoly();
	p2 = ReadPoly();
	pp = MultPoly(p1, p2);
	ps = AddPoly(p1, p2);
	PrintPoly(pp);
	PrintPoly(ps);
}
