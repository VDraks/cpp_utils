#ifndef MEMORY_PIMPL_PTR_H
#define MEMORY_PIMPL_PTR_H

#include <memory>

namespace utils {

template<class T>
class PimplPtr {
public:    
    using ElementType = typename std::unique_ptr<T>::element_type;

    PimplPtr(): p_(std::make_unique<T>()) {
        static_assert(sizeof(T) > 0, "Probably, you forgot to declare constructor explicitly");
    }
    explicit PimplPtr(std::unique_ptr<T>&& p) noexcept: p_(std::move(p)) {}

    PimplPtr(PimplPtr&&) noexcept = default;
    PimplPtr& operator =(PimplPtr&&) noexcept = default;

    ~PimplPtr() {
        static_assert(sizeof(T) > 0, "Probably, you forgot to declare destructor explicitly");
    }

    constexpr const ElementType* operator->() const noexcept { return p_.get(); }
    constexpr const ElementType& operator*() const noexcept { return p_.get(); }
    constexpr const ElementType* get() const noexcept { return p_.get(); }
    constexpr operator const ElementType*() const noexcept { return p_.get(); }

    constexpr ElementType* operator->() noexcept { return p_.get(); }
    constexpr ElementType& operator*() noexcept { return p_.get(); }
    constexpr ElementType* get() noexcept { return p_.get(); }
    constexpr operator ElementType*() noexcept { return p_.get(); }

private:
    std::unique_ptr<T> p_; ///> Should be non-const for move semantic
};

} // namespace utils

#endif // MEMORY_PIMPL_PTR_H
