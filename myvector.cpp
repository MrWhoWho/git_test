#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

void PrintVector(vector<int>& v)
{
	cout << v.size()<<"hello"<<"git" << endl;
	for (auto it = v.begin(); it != v.end(); it++)
	{
		cout << *(it) << " ";
	}
	cout << endl;
}

void testa(void)
{
	int arr[] = {2, 3, 4, 1, 9};
	int arr1[] = {1, 2, 3, 4, 5};

	int len = sizeof(arr)/sizeof(int);
	int len1 = sizeof(arr1) / sizeof(int);

	//(]
	vector<int> v(arr, arr+len);		
//	vector<int> v1(v.begin(), v.end());
	vector<int> v1(arr1, arr1 + len1);

	PrintVector(v);
	PrintVector(v1);

	v.swap(v1);

	PrintVector(v);
	PrintVector(v1);

}

void PrintSize(vector<int>& v)
{
	cout << "size = " << v.size() << endl;
	cout << "capacity = " << v.capacity() << endl;
}

void testb()
{
	vector<int> v;
	PrintSize(v);

	v.resize(5);
	PrintSize(v);
	PrintVector(v);

	v.resize(10);
	PrintSize(v);
	PrintVector(v);

}

void testc()
{
	vector<int> v;

	v.push_back(9);
	v.push_back(4);
	v.push_back(3);
	v.push_back(6);
	v.push_back(8);
	v.push_back(0);
	v.push_back(10);
	PrintVector(v);

	v.insert(v.begin()+1, 100);
	v.insert(v.begin()+5, 101);
	PrintVector(v);

	v.erase(v.begin()+1);
	v.erase(v.begin()+4);
	PrintVector(v);

	v.erase(v.begin(), v.begin()+5);		//(]
	PrintVector(v);

}

void testd()
{
	int *p = NULL;
	int count = 0;
	vector<int> v;
	v.reserve(100000);
	for (int i = 0; i < 100000; ++i)
	{
		v.push_back(i);
		if (&v[0] != p)
		{
			++count;
			p = &v[0];
		}
	}

	PrintSize(v);
	cout << "count = " << count << endl;

}

void teste()
{
	vector<int> v;
	v.reserve(1000);
	PrintSize(v);

	v.resize(5);
	PrintSize(v);

	vector<int>(v).swap(v);
	PrintSize(v);

}

int ia[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 99 };

void testf()
{
	int len = sizeof(ia) / sizeof(int);
	vector<int> v(ia, (ia + len));
	PrintVector(v);

	for (auto it = v.begin(); it != v.end();)
	{
		if ((*it) % 2 == 1)
		{
			it = v.erase(it);
		}
		else
		{
			it++;
		}
	}
	PrintVector(v);

}

void testg()
{
	int arr[] = { 2, 3, 4, 1, 9 };
	int len = sizeof(arr) / sizeof(int);

	vector<int> v(arr, arr + len);
	vector<int> v1;
	
	v1.assign(v.begin(), v.end());
	PrintVector(v1);

	v1.assign(5, 10);
	PrintVector(v1);

}


void testh()
{
	vector<int> v;

	v.push_back(9);
	v.push_back(4);
	v.push_back(3);
	v.push_back(6);
	v.push_back(8);
	v.push_back(0);
	v.push_back(10);

//	cout << v.begin() << endl;
	cout << &*v.begin() << endl;
}

int main(int argc, char** argv)
{
	cout << "_____________a" << endl;
	testa();
	cout << "_____________b" << endl;
	testb();
	cout << "_____________c" << endl;
	testc();
	cout << "_____________d" << endl;
	testd();
	cout << "_____________e" << endl;
	teste();
	cout << "_____________f" << endl;
	testf();
	cout << "_____________g" << endl;
	testg();
	cout << "_____________h" << endl;
	testh();


	system("pause");
}





































