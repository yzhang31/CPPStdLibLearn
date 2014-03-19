#include "Foo.h"
#include <iostream> 
#include <sstream>
#include <string>

int Foo::fooInstanceNumber = 0;

Foo::Foo(void)
{
    _objectID = fooInstanceNumber++;
    _data = 0;
    std::cout<<"Default Construct Foo::Foo(void)" <<objectID()<<std::endl;
}

Foo::Foo(int data)
{
    _objectID = fooInstanceNumber++;
    std::cout<<"Construct Foo::Foo(int)" << objectID()<<std::endl;
    _data = data;
}

Foo::~Foo(void)
{
    std::cout<<"Destruct Foo::~Foo(void)" <<objectID()<<std::endl;
}

Foo::Foo(const Foo& lvalue)
{
    _objectID = fooInstanceNumber++;
    std::cout<<"Copy Construct Foo::Foo(const Foo&)" <<objectID()<<std::endl;
    _data = lvalue._data;
}

Foo::Foo(Foo&& rValue)
{
    _objectID = fooInstanceNumber++;
    std::cout<<"Move Construct Foo::Foo(Foo&&)" <<objectID()<<std::endl;
    _data = rValue._data;
}

Foo& Foo::operator = (const Foo& lvalue)
{
    if (this != &lvalue)
    {
        _objectID = fooInstanceNumber++;
        std::cout<<"copy assignment Foo:: operator = (Foo&&)" <<objectID()<<std::endl;
        _data = lvalue._data;
    }
    return *this;
}

Foo& Foo::operator = (Foo&& rvalue)
{
    if (this != &rvalue)
    {
        _objectID = fooInstanceNumber++;
        std::cout<<"Move assignment Foo:: operator = (Foo&&)" <<objectID()<<std::endl;
        _data = rvalue._data;
    }
    return *this;
}

Foo Foo::operator+(Foo& rValue)
{
    std::cout<<"member Foo::operator + :" <<objectID() <<" +"<<rValue.objectID()<<std::endl;
    Foo x(_data+ rValue._data);
    return x;
}

bool Foo::operator<(const Foo& rValue) const
{
    bool b  = _data < rValue._data;
    std::cout<<"member Foo::operator < :"<<objectID()<<" <"<<rValue.objectID()<<(b? "True":"False") << std::endl;
    return b;
}

std::string Foo::objectID()
{
    std::ostringstream os;
    os <<" Obj-"<< this->_objectID <<" ";
    return os.str();
}

std::string Foo::objectID() const
{
    std::ostringstream os;
    os <<" Obj-"<< this->_objectID<< " ";
    return os.str();
}