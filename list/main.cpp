#include <iostream>
#include "List.h"

void main()
{
	List<int> l;
	ListElem<int>* t;
	int k = 7;
	int m = 5;
	int n = 3;
	l.InsFirst(k);
	l.InsLast(n);
	l.InsLast(m);
	l.InsLast(m);
	cout << "List" << endl << l << endl;
	t = l.GetMiddle(5);
	cout << "Find element" << endl << t->GetData() << endl;
    l.Rotate();
	cout << "Changed multystack" << endl << l << endl;
	l.DelMax();
	cout << "Changed multystack" << endl << l << endl;
}
