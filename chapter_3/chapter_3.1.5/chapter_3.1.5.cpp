// chapter_3.1.5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Foo.h"
#include <iostream>
#include <set>
using namespace std;

void PrintCollectionObject( std::set<Foo>& coll )
{
    cout<<"--Coll Elements start--" << endl;
    for (const Foo& d : coll)
    {
        cout << d.objectID() << endl;
    }
    cout<<"--Coll Elements   end--" << endl;
}

void foo(Foo& X)
{
    cout<<"foo(Foo& X) on:"<< X.objectID() <<endl;
}

void foo(const Foo& X)
{
    cout<<"const foo(Foo& X) on:"<< X.objectID() <<endl;
}


void foo(Foo&& X)
{
    cout<<"foo(Foo&& X) on:"<< X.objectID() <<endl;
}

void createAndInsert(std::set<Foo>& coll)
{
    Foo x(1);
    cout<<"----------------------111-------------------"<<endl;
    coll.insert(x+x);
    PrintCollectionObject(coll);
    cout<<"----------------------222-------------------"<<endl;
    
    coll.insert(std::move(x));
    PrintCollectionObject(coll);
    cout<<"----------------------333----------------"<<endl;
}

void runFooCallTest()
{
    foo(Foo(2)); // rvalue call
    Foo x(1);

    foo(x); // lvalue call
}

int _tmain(int argc, _TCHAR* argv[])
{
    std::set<Foo> coll;

    //createAndInsert(coll);
    runFooCallTest();
	return 0;
}

