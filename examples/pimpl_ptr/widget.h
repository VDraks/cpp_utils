#ifndef PIMPL_PTR_WIDGET_H
#define PIMPL_PTR_WIDGET_H

#include "memory/pimpl_ptr.h"

class Widget
{
public:
    Widget();
    Widget(Widget&&);
    ~Widget();

    void foo() const;
    void foo();

private:
    struct Impl;
    utils::PimplPtr<Impl> d_;
};

#endif // PIMPL_PTR_WIDGET_H
