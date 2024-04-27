#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <stdlib.h>
#include <map>

using namespace std;


void PrintMap(map<string, int>& arg)
{
	for (auto it = arg.begin(); it != arg.end(); it++)
	{
		cout << it->first.c_str() << "," << it->second << "    ";
	}
	cout << endl;

	for_each(arg.begin(), arg.end(), [](pair<string, int> mymap){
		cout << mymap.first.c_str() << "," << mymap.second << "    ";
	});
	cout << endl;

}


void testa(void)
{
	map<string, int> mapStudents;

	mapStudents["c"] = 7;
	mapStudents["d"] = 6;
	mapStudents["e"] = 5;
	mapStudents.insert(pair<string, int>("a", 9));
	mapStudents.insert(pair<string, int>("b", 8));
	mapStudents.insert(make_pair("f", 4));
	PrintMap(mapStudents);

	mapStudents["b"] = 80;
	mapStudents["c"] = 70;
	PrintMap(mapStudents);


	std::pair<std::map<string, int>::iterator,bool> ret;
	ret = mapStudents.insert(pair<string, int>("e", 50));
	if (false == ret.second) 
	{
		std::cout << "element e already existed";
		std::cout << " with a value of " << ret.first->second << '\n';
	}
	
	PrintMap(mapStudents);

	auto it = mapStudents.lower_bound("c");
	cout << it->first.c_str() << endl;

	it = mapStudents.upper_bound("c");
	cout << it->first.c_str() << endl;

	mapStudents["g"];
	cout << mapStudents.size() << endl;
	PrintMap(mapStudents);

	auto iterator = mapStudents.find("f");
	if (iterator != mapStudents.end())
	{
		iterator->second = 40;
	}
	PrintMap(mapStudents);

	BEGIN:
	for (auto it = mapStudents.begin(); it != mapStudents.end(); it++)
	{
		if ((it->second%2) == 1)
		{
			mapStudents.erase(it);
			goto BEGIN;
		}
	}
	PrintMap(mapStudents);

	mapStudents.erase("g");
	PrintMap(mapStudents);


//	pair<string, int> mapErase("f", 40);
//	mapStudents.erase(mapErase);
//	PrintMap(mapStudents);

}

void TestB(void)
{
	map<int, int> mapTestA;

	mapTestA.insert(pair<int, int>(100, 1));
	mapTestA.insert(map<int, int>::value_type(101, 2));

	map<int, int>::iterator itmapTestA;

	for(itmapTestA = mapTestA.begin(); itmapTestA != mapTestA.end(); itmapTestA++)
	{
		cout << itmapTestA->first << ": " << itmapTestA->second << endl;
	}
}

void TestC(void)
{
	map<pair<int, int>, string> mapTestA;

	mapTestA[pair<int, int>(0, 1)] = "hello a";
	mapTestA.insert(pair<pair<int, int>, string>(pair<int, int>(2, 3), "hello b"));
	mapTestA.insert(map<pair<int, int>, string>::value_type(pair<int, int>(4, 5), "hello c"));

	map<pair<int, int>, string>::iterator itmapTestA;
	for(itmapTestA = mapTestA.begin(); itmapTestA != mapTestA.end(); itmapTestA++)
	{
		cout << "(" << itmapTestA->first.first << ", " << itmapTestA->first.second << ")" << ": " << itmapTestA->second << endl;
	}

}


void testD(void)
{
	map<string, int> mapStudents;
	map<string, int>::iterator itmapCur = mapStudents.find("abc");
	if (itmapCur != mapStudents.end())
	{
		int s32Cur = itmapCur->second;

		return;
	}
	else
	{
	}

	
	PrintMap(mapStudents);
}


int main(int argc, char** argv)
{
	cout << "______________________________________________________a" << endl;
	testa();
	cout << "______________________________________________________b" << endl;
	TestB();
	cout << "______________________________________________________c" << endl;
	TestC();
	cout << "______________________________________________________c" << endl;
	testD();

#ifdef WIN32
	system("pause");
#endif

	return 0;
}


int main_b ()
{
  std::map<char,int> mymap;

  // first insert function version (single parameter):
  mymap.insert ( std::pair<char,int>('a',100) );
  mymap.insert ( std::pair<char,int>('z',200) );

  std::pair<std::map<char,int>::iterator,bool> ret;
  ret = mymap.insert ( std::pair<char,int>('z',500) );
  if (ret.second==false) {
    std::cout << "element 'z' already existed";
    std::cout << " with a value of " << ret.first->second << '\n';
  }

  // second insert function version (with hint position):
  std::map<char,int>::iterator it = mymap.begin();
  mymap.insert (it, std::pair<char,int>('b',300));  // max efficiency inserting
  mymap.insert (it, std::pair<char,int>('c',400));  // no max efficiency inserting

  // third insert function version (range insertion):
  std::map<char,int> anothermap;
  anothermap.insert(mymap.begin(),mymap.find('c'));

  // showing contents:
  std::cout << "mymap contains:\n";
  for (it=mymap.begin(); it!=mymap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';

  std::cout << "anothermap contains:\n";
  for (it=anothermap.begin(); it!=anothermap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';

  return 0;
}









