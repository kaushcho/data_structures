#include <iostream>
#include <memory>
using namespace std;

int main()
{
    auto_ptr<int> x(new int);
    auto_ptr<int> y;

    y = x;

    cout << x.get() << endl;
    cout << y.get() << endl;

    return 0;
}
