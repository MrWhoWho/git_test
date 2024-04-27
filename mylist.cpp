#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <list>

using namespace std;

void PrintSize(list<int>& ls)
{
	cout << "size = " << ls.size() << endl;

}

void PrintList(list<int> ls)
{
	for (auto it = ls.begin(); it != ls.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void testa()
{
	list<int> ls;
	PrintSize(ls);

	for (int i = 0; i < 5; i++)
	{
		ls.push_back(i);
	}
	PrintSize(ls);
	PrintList(ls);

	auto it = ls.begin();
	for (int i = 0; i < 3; i++)
	{
		it++;
	}

	ls.insert(it, 100);
	PrintList(ls);
}

void testb()
{
	list<int> ls;

	for (int i = 0; i < 5; i++)
	{
		ls.push_back(i);
	}
	PrintList(ls);

	for (int i = 0; i < 5; i++)
	{
		ls.push_front((i*10));
	}
	PrintList(ls);

	ls.sort();
	PrintList(ls);

	ls.reverse();
	PrintList(ls);

	ls.push_back(4);
	ls.push_back(4);
	ls.remove(4);
	PrintList(ls);

	for (auto it = ls.begin(); it != ls.end();)
	{
		if ((*it) > 9)
		{
			it = ls.erase(it);
		}
		else
		{
			it++;
		}
	}
	PrintList(ls);
}

int ia[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 99 };

void testc()
{
	int len = sizeof(ia) / sizeof(int);
	list<int> ls(ia, ia + len);
	PrintList(ls);

	ls.pop_back();
	ls.pop_front();
	PrintList(ls);

	cout << ls.front() << endl;
	cout << ls.back() << endl;
}


int main(int argc, char** argv)
{
	cout << "______________________a" << endl;
	testa();
	cout << "______________________b" << endl;
	testb();
	cout << "______________________c" << endl;
	testc();


	system("pause");
	return 0;
}

