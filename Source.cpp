#include <iostream>

using namespace std;

struct NODE { int data; NODE* pNext; NODE* pPrev; };

void listIn(NODE*& x, int& n)
{
	NODE* pCur = nullptr;
	int t;
	cout << "Input numbers (0 to stop): " << endl;
	cin >> t;
	while (t != 0)
	{
		if (x == nullptr)
		{
			x = new NODE;
			x->data = t;
			x->pNext = nullptr;
			x->pPrev = nullptr;
			pCur = x;
		}
		else 
		{
			pCur->pNext = new NODE;
			pCur->pNext->pPrev = pCur;
			pCur = pCur->pNext;
			pCur->data = t;
			pCur->pNext = nullptr;
		}
		cin >> t;
		n++;
	}
}

void nodeDelK(NODE*& x, int k, int& count)
{
	NODE* pCur = nullptr, * pDel = nullptr;
	pCur = x;
	while (pCur->pNext->pNext != nullptr)
	{
		if (pCur->pNext->data == k)
		{
			pDel = pCur->pNext;
			pCur->pNext = pDel->pNext;
			delete pDel;
			count--;
			break;
		}
		pCur = pCur->pNext;
	}
}

void nodeDelAllK(NODE*& x, int k, int& count)
{
	NODE* pCur = nullptr, * pDel = nullptr;
	pCur = x;
	while (pCur->pNext->pNext != nullptr)
	{
		pCur = pCur->pNext;
		if (pCur->pNext->data == k)
		{
			pDel = pCur->pNext;
			if (pDel != nullptr)
			{
				pCur->pNext = pDel->pNext;
			}
			else
			{
				delete pDel;
				break;
			}
			delete pDel;
			count--;
		}
	}
}

void beginningDel(NODE*& x)
{

}

void beginningIn(NODE*& x, int t)
{
	/*NODE* temp = new NODE;
	temp->data = t;
	temp->pNext = x->pNext;
	x = temp;*/
	if (x == nullptr)
	{
		x = new NODE;
		x->pNext = nullptr;
	}
	else
	{
		x->pPrev = new NODE;
		x->pPrev->pNext = x;
		x = x->pPrev;	
	}
	x->data = t;
	x->pPrev = nullptr;
}

void insBeforeK(NODE*& x, int t, int k)
{
	if (x == nullptr) return;
	NODE* pCur = x;
	if (x->data == k) beginningIn(x, t);
	else
	{
		while (pCur && pCur->data != k)
		{
			pCur = pCur->pNext;
		}
		if (pCur)
		{
			NODE* temp = new NODE;
			temp->data = t;
			temp->pNext = pCur;
			temp->pPrev = pCur->pPrev;
			pCur->pPrev->pNext = temp;
			pCur->pPrev = temp;
		}
	}
}

void listOut(NODE* x)
{
	while (x != nullptr)
	{
		cout << x->data << " ";
		x = x->pNext;
	}
}

void listOutR(NODE* x)
{
	NODE* pCur = x;
	while (pCur->pNext)
	{
		pCur = pCur->pNext;
	}
	while (pCur)
	{
		cout << pCur->data << " ";
		pCur = pCur->pPrev;
	}
}

void oddEven(NODE* x, NODE*& odd, NODE*& even)
{
	NODE* cur1, * cur2 = nullptr, * cur3 = nullptr;
	cur1 = x;
	while (cur1 != nullptr)
	{
		if (cur1->data % 2 == 0)
		{
			if (even == nullptr)
			{
				even = new NODE;
				even->data = cur1->data;
				even->pNext = nullptr;
				cur2 = even;
			}
			else
			{
				cur2->pNext = new NODE;
				cur2 = cur2->pNext;
				cur2->data = cur1->data;
				cur2->pNext = nullptr;
			}
		}
		else
		{
			if (odd == nullptr)
			{
				odd = new NODE;
				odd->data = cur1->data;
				odd->pNext = nullptr;
				cur3 = odd;
			}
			else
			{
				cur3->pNext = new NODE;
				cur3 = cur3->pNext;
				cur3->data = cur1->data;
				cur3->pNext = nullptr;
			}
		}
		cur1 = cur1->pNext;
	}
}

void listSort(NODE*& x)
{
	NODE* pCur = x, * pTemp = nullptr;
	int temp;
	while (pCur != nullptr)
	{
		if (pCur->pNext != nullptr) { pTemp = pCur->pNext; }
		while (pTemp != nullptr)
		{
			if (pCur->data > pTemp->data)
			{
				temp = pCur->data;
				pCur->data = pTemp->data;
				pTemp->data = temp;
			}
			pTemp = pTemp->pNext;
		}
		pCur = pCur->pNext;
	}
}

void listDel(NODE* x)
{
	NODE* temp;
	while (x!=nullptr && x->pNext != nullptr)
	{
		temp = x; 
		x = x->pNext;
		delete temp;
	}
}

//int main()
//{
//	NODE* pHead = nullptr, *pOdd = nullptr, *pEven = nullptr;
//	int count = 0, a, k;
//	listIn(pHead, count);
//	cout << "Insert x: "; cin >> a;
//	cout << "Insert k: "; cin >> k;
//	insBeforeK(pHead, a, k);
//	//beginningIn(pHead, a);
//	/*cout << "Delete first k, k= "; cin >> a;
//	nodeDelSing(pHead, a ,count);*/
//	/*cout << "Delete all j, j= "; cin >> a;
//	nodeDelAll(pHead, a, count);*/
//	/*oddEven(pHead, pOdd, pEven);
//	listOut(pOdd);
//	cout << endl;
//	listOut(pEven);
//	listOut(pHead);
//	listDel(pOdd);
//	listSort(pHead);*/
//	listOut(pHead);
//	listDel(pHead);
//}


/////////////////////////////////////////////////////////////////////////////////////////////////// Circular list

void cListIn(NODE*& p)
{
	NODE* pCur = nullptr;
	int t;
	cout << "Input numbers (0 to stop): " << endl;
	cin >> t;
	while (t != 0)
	{
		if (p == nullptr)
		{
			p = new NODE;
			p->data = t;
			p->pNext = nullptr;
			p->pPrev = nullptr;
			pCur = p;
		}
		else
		{
			pCur->pNext = new NODE;
			pCur->pNext->pPrev = pCur;
			pCur = pCur->pNext;
			pCur->data = t;
			pCur->pNext = nullptr;
		}
		cin >> t;
		p->pPrev = pCur;
		pCur->pNext = p;
	}
}

void cirDelf(NODE*& p)
{
	if (p == nullptr) return;
	NODE* pCur = p->pNext;
	pCur->pPrev = p->pPrev;
	pCur->pPrev->pNext = pCur;
	delete p;
	p = pCur;
}

void cirOut(NODE* p)
{
	NODE* pCur = p->pNext;
	cout << p->data << " ";
	while (pCur != p)
	{
		cout << pCur->data << " ";
		pCur = pCur->pNext;
	}
}

void cirDel(NODE*& p)
{
	NODE* pDel = p;
	p->pPrev->pNext = nullptr;
	while (p)
	{
		p = p->pNext;
		delete pDel;
		pDel = p;
	}
}

int main()
{
	NODE* pHead = nullptr;
	cListIn(pHead); cirDelf(pHead);
	cirOut(pHead);
	cirDel(pHead);
}