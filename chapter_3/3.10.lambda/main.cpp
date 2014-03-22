// chapter3.cpp : Defines the entry point for the console application.
//

#include<functional>
#include <iostream>
#include <string>
#include <map>


using namespace std;

void Lambda_no_parameter_no_capture()
{
    auto l = [] {
        std::cout << "hello world" << std::endl;
    };

    l();
}


void Lambda_parameter()
{
    auto l = [] (const std::string&s){
        std::cout << s << std::endl;
    };

    l("hello lambda");
}

void Lambda_mutable()
{
    int x=0;
    int y=42;

    // Cannot compile without mutable
    //auto qqq = [x, &y] {
    //    ++y; // ok
    //};

    auto qqq = [x, y] () mutable {
        ++y; // compile ok
    };

    qqq();

}


void Lambda_capture_outside_params()
{
    int x=0;
    int y=42;
    auto qqq = [x, y] () mutable{
        std::cout << "lambda x: " << x << std::endl;
        std::cout << "lambda y: " << y << std::endl;
        ++y; // OK
    };

    x = y = 77;
    qqq();
    qqq();
    std::cout << "final local y: " << y << std::endl;
    std::cout << "final local x: " << x << std::endl;
}


void Lambda_with_capture_all_outside_params()
{
    int x=0;
    int y=42;
    auto qqq =
        [=, &y] {
            std::cout << "lambda x: " << x << std::endl;
            std::cout << "lambda y: " << y << std::endl;
            ++y; // OK
        };

    x = y = 77;
    qqq();
    qqq();
    std::cout << "final local y: " << y << std::endl;
    std::cout << "final local x: " << x << std::endl;
}

void lambda_capture_mutable()
{
    int id = 0;
    auto f = [id] () mutable {
        std::cout << "id: " << id << std::endl;
        ++id; // OK
    };
    id = 42;
    f();
    f();
    f();
    std::cout << id << std::endl;
}


std::function<int(int,int)> lambda_return_Lambda ()
{
    return [] (int x, int y) {
        return x*y;
    };
}


class Test
{
private:
	int m_g = 60;

public:
	void Lambda_capture_outside_params()
	{
		int x = 0;
		int y = 42;
		auto qqq = [x,y](int i) mutable{
			int m = x;
			int n = i;
			++y; // OK
			std::cout << "lambda x: " << x << std::endl;
			std::cout << "lambda y: " << y << std::endl;
			std::cout << "lambda m: " << m << std::endl;
			std::cout << "lambda n: " << n << std::endl;
		};

		x = y = 77;
		qqq(2);
		qqq(6);
		std::cout << "final local y: " << y << std::endl;
		std::cout << "final local x: " << x << std::endl;
	}
};

class Lambda_Functor
{
public:
	Lambda_Functor(const int x, const int y) : _x(x), _y(y)
	{
	}

	void operator() (int i)
	{
		int m = _x;
		int n = i;
		++_y;
		std::cout << "functor _x: " << _x << std::endl;
		std::cout << "functor _y: " << _y << std::endl;
		std::cout << "functor m: " << m << std::endl;
		std::cout << "functor n: " << n << std::endl;
	}

private:
	int _x;
	int _y;
};

// This function is equivalent to the function Lambda_capture_outside_params
// Refer to: http://blog.feabhas.com/2014/03/demystifying-c-lambdas/
void Use_lambda_functor()
{
	int x = 0;
	int y = 42;

	Lambda_Functor lf(x, y);

	x = y = 77;

	lf(2);
	lf(6);

	std::cout << "final local y: " << y << std::endl;
	std::cout << "final local x: " << x << std::endl;
}

int main()
{
	Test t;
	t.Lambda_capture_outside_params();

	cout << "================================= Gorgeous Separator =================================" << endl;
    Use_lambda_functor();

    //Lambda_no_parameter_no_capture();
    //Lambda_parameter();
    //Lambda_mutable();
    //Lambda_capture_outside_params();
    //Lambda_with_capture_all_outside_params();
    //lambda_capture_mutable();

    //auto lf = lambda_return_Lambda();
    //std::cout << lf(6,7) << std::endl;

    return 0;
}

