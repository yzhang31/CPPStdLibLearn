// chapter_4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <functional>
#include <future>


void func (int x, int y){
    std::cout << "call void func (int x, int y)" << std::endl;
};

auto l = [] (int x, int y) {
     std::cout << "call auto l = [] (int x, int y)" << std::endl;
};

class C {
public:
    void operator () (int x, int y) const 
    {
        std::cout << "call C()" << std::endl;
    };

    void memfunc (int x, int y) const
    {
        std::cout << "call C::memfunc()" << std::endl;
    }
};

int main()
{
    C c;
    std::shared_ptr<C> sp(new C);
    // bind() uses callable objects to bind arguments:
    std::bind(func,77,33)(); // calls: func(77,33)
    std::bind(l,77,33)(); // calls: l(77,33
    std::bind(C(),77,33)(); // calls: C::operator()(77,33)

    std::bind(c,77,33)(); // calls: C::operator()(77,33)
    std::bind(&C::operator(), &c, 42, 77)();

    std::bind(&C::memfunc,c,77,33)(); // calls: c.memfunc(77,33)
    std::bind(&C::memfunc,sp,77,33)(); // calls: sp->memfunc(77,33)
    // async() uses callable objects to start (background) tasks:
    std::async(func,42,77); // calls: func(42,77)
    std::async(l,42,77); // calls: l(42,77)
    std::async(c,42,77); // calls: c.operator()(42,77)
    std::async(&C::memfunc,&c,42,77); // calls: c.memfunc(42,77)
    std::async(&C::memfunc,sp,42,77); // calls: sp->memfunc(42,77)
}

