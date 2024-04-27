#include <queue>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <list>


#include<deque>//双端队列

//提供了二维动态数组的功能，头部，尾部，任意操作


using namespace std;

void testa()
{

	queue<char *>myq;

	char as8_Commanda[] = "calc";
	char as8_Commandb[] = "notepad";
	char as8_Commandc[] = "tasklist";
	char as8_Commandd[] = "mspaint";
/*
	myq.push("calc");	
	myq.push("notepad");
	myq.push("tasklist");
	myq.push("mspaint");
*/
	myq.push(as8_Commanda);	
	myq.push(as8_Commandb);	
	myq.push(as8_Commandc);	
	myq.push(as8_Commandd);	

	while (!myq.empty())
	{
	  char *p=	myq.front();//获取
	  cout << p << endl;
	  myq.pop();
	}

}


void testb()
{

	deque<int> mydq;
	mydq.push_back(1);
	mydq.push_back(11);
	mydq.push_back(111);
	mydq.push_back(1111);
	mydq.push_back(11111);
	mydq.push_front(123);
	mydq.insert(mydq.begin() + 3, 100);//插入

	for (int i = 0; i < mydq.size();i++)
	{
		std::cout << mydq[i] << std::endl;
	}

	deque<int>::iterator ib = mydq.begin();
	deque<int>::iterator ie = mydq.end();
	for (; ib != ie; ib++)
	{
		std::cout << *ib<< std::endl;
	}

}


void testc()
{

	deque<int> mydq;
	mydq.push_back(1);
	mydq.push_back(11);
	mydq.push_back(111);
	mydq.push_back(1111);
	mydq.push_back(11111);
	mydq.push_front(123);
	//mydq.erase(mydq.begin());
	//mydq.erase(mydq.end() - 1);
	mydq.pop_front();//头部弹出
	mydq.pop_back();//尾部
	mydq.erase(mydq.begin());
	//mydq.clear();
	
	deque<int>::iterator ib = mydq.begin();
	deque<int>::iterator ie = mydq.end();
	for (; ib != ie; ib++)
	{
		std::cout << *ib << std::endl;
	}

}


void testd()
{
	deque<int> mydq1;
	mydq1.push_back(1);
	mydq1.push_back(11);
	mydq1.push_back(111);
	mydq1.push_back(1111);
	mydq1.push_back(11111);

	deque<int> mydq2;
	mydq2.push_back(2);
	mydq2.push_back(21);
	mydq2.push_back(211);
	mydq2.push_back(2111);
	
	mydq1.swap(mydq2);

	{
		deque<int>::iterator ib = mydq1.begin();
		deque<int>::iterator ie = mydq1.end();
		for (; ib != ie; ib++)
		{
			std::cout << *ib << std::endl;
		}
	}

	{
		deque<int>::iterator ib = mydq2.begin();
		deque<int>::iterator ie = mydq2.end();
		for (; ib != ie; ib++)
		{
			std::cout << *ib << std::endl;
		}
	}

}


void teste()
{
	deque<int> mydq1;
	mydq1.push_back(1);
	mydq1.push_back(11);
	mydq1.push_back(111);
	mydq1.push_back(1111);
	mydq1.push_back(11111);
	std::cout << mydq1.front() << std::endl;
	std::cout << mydq1.back() << std::endl;
	std::cout << mydq1.max_size() << std::endl;
	std::cout << mydq1.size() << std::endl;

}

void  testf()
{
	priority_queue<int > myq;
	myq.push(10);
	myq.push(12);
	myq.push(11);
	myq.push(110);
	myq.push(101);//自动排序

	while (!myq.empty())
	{
		std::cout << myq.top() << endl;
		myq.pop();
	}

}


struct student
{
	int age;
	string name;
};
//strcmp==0;

struct stuless
{
	bool operator()(const student &s1,  const student &s2)
	{
//		return s1.age < s2.age;
		return s1.age > s2.age;		
	}

};

void testg()
{                  //类名，   //存储         //比大小
	priority_queue<student, deque<student>, stuless> myq;
	student s1;
	s1.age = 10;
	s1.name = "tansheng";
	student s2;
	s2.age = 9;
	s2.name = "xiongfei";
	student s3;
	s3.age = 19;
	s3.name = "xiongpengfei";
	myq.push(s1);
	myq.push(s2);
	myq.push(s3);
	while (!myq.empty())
	{
		std::cout << myq.top().age << myq.top().name << endl;
		myq.pop();
	}

}



int main()
{
	cout << "__________________________a" << endl;
	testa();

	cout << "__________________________b" << endl;
	testb();
	
	cout << "__________________________c" << endl;
	testc();

	cout << "__________________________d" << endl;
	testd();

	cout << "__________________________e" << endl;
	teste();

	cout << "__________________________f" << endl;
	testf();

	cout << "__________________________g" << endl;
	testg();

	return 0;
}










