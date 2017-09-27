#include <stdexcept>

namespace meta
{

template <typename Class, typename T>
Member<Class, T>::Member(const char* name, member_ptr_t<Class, T> ptr) :
    name(name),
    ptr(ptr)
{ }

template <typename Class, typename T>
Member<Class, T, ref_getter_func_ptr_t<Class, T>, ref_setter_func_ptr_t<Class, T>>::Member(const char* name, ref_getter_func_ptr_t<Class, T> getterPtr, ref_setter_func_ptr_t<Class, T> setterPtr) : 
    name(name),
    getterPtr(getterPtr),
    setterPtr(setterPtr)
{ }

template <typename Class, typename T>
Member<Class, T, val_getter_func_ptr_t<Class, T>, val_setter_func_ptr_t<Class, T>>::Member(const char* name, val_getter_func_ptr_t<Class, T> getterPtr, val_setter_func_ptr_t<Class, T> setterPtr) :
    name(name),
    getterPtr(getterPtr),
    setterPtr(setterPtr)
{ }

template <typename Class, typename T>
Member<Class, T, ref_getter_func_ptr_t<Class, T>>::Member(const char* name, ref_getter_func_ptr_t<Class, T> getterPtr) : 
    name(name),
    getterPtr(getterPtr)
{ }

template <typename Class, typename T>
Member<Class, T, val_getter_func_ptr_t<Class, T>>::Member(const char* name, val_getter_func_ptr_t<Class, T> getterPtr) :
    name(name),
    getterPtr(getterPtr)
{ }

template <typename Class, typename T>
Member<Class, T, ref_setter_func_ptr_t<Class, T>>::Member(const char* name, ref_setter_func_ptr_t<Class, T> setterPtr) : 
    name(name),
    setterPtr(setterPtr)
{ }

template <typename Class, typename T>
Member<Class, T, val_setter_func_ptr_t<Class, T>>::Member(const char* name, val_setter_func_ptr_t<Class, T> setterPtr) :
    name(name),
    setterPtr(setterPtr)
{ }

template <typename Class, typename T>
const T& Member<Class, T>::get(const Class& obj) const {
    return obj.*ptr;
}

template <typename Class, typename T>
const T& Member<Class, T, ref_getter_func_ptr_t<Class, T>, ref_setter_func_ptr_t<Class, T>>::get(const Class& obj) const {
    return (obj.*getterPtr)();
}

template <typename Class, typename T>
T Member<Class, T, val_getter_func_ptr_t<Class, T>, val_setter_func_ptr_t<Class, T>>::get(const Class& obj) const {
    return (obj.*getterPtr)();
}

template <typename Class, typename T>
const T& Member<Class, T, ref_getter_func_ptr_t<Class, T>>::get(const Class& obj) const {
    return (obj.*getterPtr)();
}

template <typename Class, typename T>
T Member<Class, T, val_getter_func_ptr_t<Class, T>>::get(const Class& obj) const {
    return (obj.*getterPtr)();
}

template <typename Class, typename T>
const T& Member<Class, T, ref_setter_func_ptr_t<Class, T>>::get(const Class& obj) const {
    throw std::runtime_error("Cannot get member: getter is not available");
}

template <typename Class, typename T>
const T& Member<Class, T, val_setter_func_ptr_t<Class, T>>::get(const Class& obj) const {
    throw std::runtime_error("Cannot get member: getter is not available");
}

template <typename Class, typename T>
T Member<Class, T>::getCopy(const Class& obj) const {
    return obj.*ptr;
}

template <typename Class, typename T>
T Member<Class, T, ref_getter_func_ptr_t<Class, T>, ref_setter_func_ptr_t<Class, T>>::getCopy(const Class& obj) const {
    return (obj.*getterPtr)();
}

template <typename Class, typename T>
T Member<Class, T, val_getter_func_ptr_t<Class, T>, val_setter_func_ptr_t<Class, T>>::getCopy(const Class& obj) const {
    return (obj.*getterPtr)();
}

template <typename Class, typename T>
T Member<Class, T, ref_getter_func_ptr_t<Class, T>>::getCopy(const Class& obj) const {
    return (obj.*getterPtr)();
}

template <typename Class, typename T>
T Member<Class, T, val_getter_func_ptr_t<Class, T>>::getCopy(const Class& obj) const {
    return (obj.*getterPtr)();
}

template <typename Class, typename T>
T Member<Class, T, ref_setter_func_ptr_t<Class, T>>::getCopy(const Class& obj) const {
    throw std::runtime_error("Cannot get member: getter is not available");
}

template <typename Class, typename T>
T Member<Class, T, val_setter_func_ptr_t<Class, T>>::getCopy(const Class& obj) const {
    throw std::runtime_error("Cannot get member: getter is not available");
}

template <typename Class, typename T>
T& Member<Class, T>::getRef(Class& obj) const {
    return obj.*ptr;
}

template <typename Class, typename T>
T& Member<Class, T, ref_getter_func_ptr_t<Class, T>, ref_setter_func_ptr_t<Class, T>>::getRef(Class& obj) const {
    throw std::runtime_error("Cannot return ref to member: getter can only return by const ref");
}

template <typename Class, typename T>
T& Member<Class, T, val_getter_func_ptr_t<Class, T>, val_setter_func_ptr_t<Class, T>>::getRef(Class& obj) const {
    throw std::runtime_error("Cannot return ref to member: getter can only return by value");
}

template <typename Class, typename T>
T& Member<Class, T, ref_getter_func_ptr_t<Class, T>>::getRef(Class& obj) const {
    throw std::runtime_error("Cannot return ref to member: getter can only return by const ref");
}

template <typename Class, typename T>
T& Member<Class, T, val_getter_func_ptr_t<Class, T>>::getRef(Class& obj) const {
    throw std::runtime_error("Cannot return ref to member: getter can only return by value");
}

template <typename Class, typename T>
T& Member<Class, T, ref_setter_func_ptr_t<Class, T>>::getRef(Class& obj) const {
    throw std::runtime_error("Cannot return ref to member: getter is not available");
}

template <typename Class, typename T>
T& Member<Class, T, val_setter_func_ptr_t<Class, T>>::getRef(Class& obj) const {
    throw std::runtime_error("Cannot return ref to member: getter is not available");
}

template <typename Class, typename T>
member_ptr_t<Class, T> Member<Class, T>::getPtr() const {
    return ptr;
}

template <typename Class, typename T>
member_ptr_t<Class, T> Member<Class, T, ref_getter_func_ptr_t<Class, T>, ref_setter_func_ptr_t<Class, T>>::getPtr() const {
    throw std::runtime_error("Cannot get pointer to member: only have getter and setter");
}

template <typename Class, typename T>
member_ptr_t<Class, T> Member<Class, T, val_getter_func_ptr_t<Class, T>, val_setter_func_ptr_t<Class, T>>::getPtr() const {
    throw std::runtime_error("Cannot get pointer to member: only have getter and setter");
}

template <typename Class, typename T>
member_ptr_t<Class, T>  Member<Class, T, ref_getter_func_ptr_t<Class, T>>::getPtr() const {
    throw std::runtime_error("Cannot get pointer to member: only have getter by ref");
}

template <typename Class, typename T>
member_ptr_t<Class, T> Member<Class, T, val_getter_func_ptr_t<Class, T>>::getPtr() const {
    throw std::runtime_error("Cannot get pointer to member: only have getter by value");
}

template <typename Class, typename T>
member_ptr_t<Class, T> Member<Class, T, ref_setter_func_ptr_t<Class, T>>::getPtr() const {
    throw std::runtime_error("Cannot get pointer to member: only have setter");
}

template <typename Class, typename T>
member_ptr_t<Class, T> Member<Class, T, val_setter_func_ptr_t<Class, T>>::getPtr() const {
    throw std::runtime_error("Cannot get pointer to member: only have setter");
}

template<typename Class, typename T>
template <typename V, typename>
void Member<Class, T>::set(Class& obj, V&& value) const {
    // TODO: add rvalueSetter?
    obj.*ptr = value;
}

template<typename Class, typename T>
template <typename V, typename>
void Member<Class, T, ref_getter_func_ptr_t<Class, T>, ref_setter_func_ptr_t<Class, T>>::set(Class& obj, V&& value) const {
    // TODO: add rvalueSetter?
    (obj.*setterPtr)(value);
}

template<typename Class, typename T>
template <typename V, typename>
void Member<Class, T, val_getter_func_ptr_t<Class, T>, val_setter_func_ptr_t<Class, T>>::set(Class& obj, V&& value) const {
    // TODO: add rvalueSetter?
    (obj.*setterPtr)(value);
}

template <typename Class, typename T>
template <typename V, typename>
void  Member<Class, T, ref_getter_func_ptr_t<Class, T>>::set(Class& obj, V&& value) const {
    // TODO: add rvalueSetter?
    throw std::runtime_error("Cannot set member: only have getter");
}

template <typename Class, typename T>
template <typename V, typename>
void Member<Class, T, val_getter_func_ptr_t<Class, T>>::set(Class& obj, V&& value) const {
    // TODO: add rvalueSetter?
    throw std::runtime_error("Cannot set member: only have getter");
}

template <typename Class, typename T>
template <typename V, typename>
void Member<Class, T, ref_setter_func_ptr_t<Class, T>>::set(Class& obj, V&& value) const {
    // TODO: add rvalueSetter?
    (obj.*setterPtr)(value);
}

template <typename Class, typename T>
template <typename V, typename>
void Member<Class, T, val_setter_func_ptr_t<Class, T>>::set(Class& obj, V&& value) const {
    // TODO: add rvalueSetter?
    (obj.*setterPtr)(value);
}

template <typename Class, typename T>
auto member(const char* name, member_ptr_t<Class, T> ptr) {
    return Member<Class, T>(name, ptr);
}

template <typename Class, typename T>
auto member(const char* name, ref_getter_func_ptr_t<Class, T> getterPtr, ref_setter_func_ptr_t<Class, T> setterPtr) {
    return Member<Class, T, ref_getter_func_ptr_t<Class, T>, ref_setter_func_ptr_t<Class, T>>(name, getterPtr, setterPtr);
}

template <typename Class, typename T>
auto member(const char* name, val_getter_func_ptr_t<Class, T> getterPtr, val_setter_func_ptr_t<Class, T> setterPtr) {
    return Member<Class, T, val_getter_func_ptr_t<Class, T>, val_setter_func_ptr_t<Class, T>>(name, getterPtr, setterPtr);
}

// read only
template <typename Class, typename T>
auto member(const char* name, ref_getter_func_ptr_t<Class, T> getterPtr) {
    return Member<Class, T, ref_getter_func_ptr_t<Class, T>>(name, getterPtr);
}

template <typename Class, typename T>
auto member(const char* name, val_getter_func_ptr_t<Class, T> getterPtr) {
    return Member<Class, T, val_getter_func_ptr_t<Class, T>>(name, getterPtr);
}

// set only 
template <typename Class, typename T>
auto member(const char* name, ref_setter_func_ptr_t<Class, T> setterPtr) {
    return Member<Class, T, ref_setter_func_ptr_t<Class, T>>(name, setterPtr);
}

template <typename Class, typename T>
auto member(const char* name, val_setter_func_ptr_t<Class, T> setterPtr) {
    return Member<Class, T, val_setter_func_ptr_t<Class, T>>(name, setterPtr);
}

} // end of namespace meta