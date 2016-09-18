#include <iostream>

#include "widget.h"

using namespace std;

int main(void)
{
    Widget widget;
    widget.foo();
    const Widget newOwnerWidget(std::move(widget));
    newOwnerWidget.foo();
    return 0;
}
