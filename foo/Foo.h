#pragma once
#include <string>
class Foo
{

public:
    Foo(void);
    Foo(int);
    Foo(const Foo&);
    Foo(Foo&&);
    Foo& operator = (const Foo& );
    Foo& operator =(Foo&&);
    ~Foo(void);

    Foo operator + (Foo&);
    bool operator < (const Foo&) const;
    std::string objectID();
    std::string objectID() const;
private:
    int _data;
    int _objectID;
    static int fooInstanceNumber;

};

