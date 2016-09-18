#include "widget.h"

#include <iostream>

struct Widget::Impl {
    Impl() { std::cout << "Widget::Impl" << std::endl; }
    ~Impl() { std::cout << "Widget::~Impl" << std::endl; }

    void foo() const { std::cout << "Widget::Impl::foo() const" << std::endl; }
    void foo() { std::cout << "Widget::Impl::foo()" << std::endl; }
};

Widget::Widget() {}

Widget::Widget(Widget&&) = default;

Widget::~Widget() {}

void Widget::foo() const
{
    d_->foo();
}

void Widget::foo()
{
    d_->foo();
}
