#include <stdexcept>
#include <iostream>
#include <errno.h>

using namespace std;


int main()
{
    logic_error e("Logic error."); // defined in <stdexcept>
    //system_error se(error_code());
    try
    {
        throw e;
    }
    catch (logic_error &e)
    {
        cerr << e.what() << endl;  // output exception information.
    }

}

