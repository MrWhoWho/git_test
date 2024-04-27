#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <set>
#include <time.h>
#include <string.h>

using namespace std;

class mysetCompare
{
public:
    bool operator()(int former, int latter);
};

bool mysetCompare::operator()(int former, int latter)
{
    return former > latter;
}


class mysetPerson
{
public:
    mysetPerson(const char*, int);
    char achName[15];
    int  s32Age;
};

mysetPerson::mysetPerson(const char* name, int age)
{
    memset(achName, 0, 15);
    strcpy(achName, name);
    s32Age = age;
}

class mysetCompareC
{
public:
    bool operator()(mysetPerson a, mysetPerson b);
};

bool mysetCompareC::operator ()(mysetPerson a, mysetPerson b)
{
    return a.s32Age > b.s32Age;
}




//void MysetPrint(set<int>& setarg)
//{
//    for(auto it = setarg.begin(); it != setarg.end(); it++)
//    {
//        cout /*<< it->first */<< *it << ",";
//    }

//    cout << endl;
//}

//void MysetPrint(set<string>& setarg)
//{
//    for(auto it = setarg.begin(); it != setarg.end(); it++)
//    {
//        cout /*<< it->first */<< *it << ",";
//    }

//    cout << endl;
//}


template<class T>
void MysetPrint(set<T>& setarg)
{
    for(auto it = setarg.begin(); it != setarg.end(); it++)
    {
        cout /*<< it->first */<< *it << ",";
    }

    cout << endl;
}

void MysetPrint(set<int, mysetCompare>& setarg)
{
    for(auto it = setarg.begin(); it != setarg.end(); it++)
    {
        cout << *it << ",";
    }

    cout << endl;
}

void MysetPrint(set<mysetPerson, mysetCompareC>& setarg)
{
    for(auto it = setarg.begin(); it != setarg.end(); it++)
    {
        cout << (*it).achName << " " << it->s32Age <<",";
    }

    cout << endl;
}

void testa()
{

    set<int> mysetInt;
    pair<set<int>::iterator , bool> mysetResult = mysetInt.insert(10);

    if(mysetResult.second > 0)
    {
        cout << *(mysetResult.first) << " "<< mysetResult.second << endl;
    }
    else if(mysetResult.second <= 0)
    {
        cout << "error" << __FUNCTION__ << __LINE__ ;
    }


    mysetResult = mysetInt.insert(10);

    if(mysetResult.second > 0)
    {
        cout << *(mysetResult.first) << " "<< mysetResult.second << endl;
    }
    else if(mysetResult.second <= 0)
    {
        cout << "error" << ":" << __FUNCTION__ << ":" << __LINE__ << ":" << endl;
    }

    mysetInt.insert(15);
    mysetInt.insert(20);
    mysetInt.insert(25);

    MysetPrint<int>(mysetInt);
}



void testb()
{
    srand(time(NULL));

    set<int, mysetCompare> mysetMulty;

    for(int i = 0; i < 10; i++)
    {
        int tmp = (rand()%(20-10)) + 10;
        mysetMulty.insert(tmp);
    }

    MysetPrint(mysetMulty);
}

void testc()
{
    int as32Ages[11] = {0};
    srand(time(NULL));
    for(int i = 0; i < 10; i++)
    {
        as32Ages[i] = (rand()%(40-23))+23;
    }

    mysetPerson personTeachera("a", as32Ages[0]);
    mysetPerson personTeacherb("b", as32Ages[1]);
    mysetPerson personTeacherc("c", as32Ages[2]);
    mysetPerson personTeacherd("d", as32Ages[3]);
    mysetPerson personTeachere("e", as32Ages[4]);
    mysetPerson personTeacherf("f", as32Ages[5]);
    mysetPerson personTeacherg("g", as32Ages[6]);
    mysetPerson personTeacherh("h", as32Ages[7]);
    mysetPerson personTeacheri("i", as32Ages[8]);
    mysetPerson personTeacherj("j", as32Ages[9]);


    mysetPerson personTeacherta("ta", 150);
    mysetPerson personTeachertb("ta", 151);
    mysetPerson personTeachertc("tc", 150);

    set<mysetPerson, mysetCompareC> mysetTeachers;
    mysetTeachers.insert(personTeachera);
    mysetTeachers.insert(personTeacherb);
    mysetTeachers.insert(personTeacherc);
    mysetTeachers.insert(personTeacherd);
    mysetTeachers.insert(personTeachere);
    mysetTeachers.insert(personTeacherf);
    mysetTeachers.insert(personTeacherg);
    mysetTeachers.insert(personTeacherh);
    mysetTeachers.insert(personTeacheri);
    mysetTeachers.insert(personTeacherj);


    mysetTeachers.insert(personTeacherta);
    mysetTeachers.insert(personTeachertb);
    mysetTeachers.insert(personTeachertc);

    MysetPrint(mysetTeachers);
}

void testd(void)
{
    set<string> mysetString;

    mysetString.insert("abc");
    mysetString.insert("def");
    mysetString.insert("hij");
    mysetString.insert("klm");
    MysetPrint<string>(mysetString);

    set<string>::iterator it = mysetString.find("abc");
    if(it != mysetString.end())
    {
        cout << *it << endl;
//        mysetString.erase(it);
        mysetString.erase(*it);
    }
    else
    {
        cout << "error: find" << __FILE__<< ":" << __LINE__ << endl;
    }

    it = mysetString.find("klm");
    if(it != mysetString.end())
    {
        cout << *it << endl;
        mysetString.erase(it);
//        mysetString.erase(*it);
    }
    else
    {
        cout << "error: find" << __FILE__<< ":" << __LINE__ << endl;
    }
    MysetPrint<string>(mysetString);
}



int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;

    cout << "__________________a" << endl;
    testa();
    cout << "__________________b" << endl;
    testb();
    cout << "__________________c" << endl;
    testc();
    cout << "__________________d" << endl;
    testd();

    return 0;
}



