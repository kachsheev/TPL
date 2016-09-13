/*
 * file:       UniquePointer.hpp
 *
 * created:    03.09.2016
 * author:     Anton Kashcheev
 */
#ifndef UNIQUEPOINTER_HPP
#define UNIQUEPOINTER_HPP

// declaration
namespace tpl
{namespace templates
{

template<class Object>
class UniquePointer
{
public:
	template<class CreationObject, class ... Args>
	friend UniquePointer<CreationObject> makeUnique(Args ... args);

	UniquePointer();
	UniquePointer(const UniquePointer<Object> &) = delete;
	UniquePointer(UniquePointer<Object> &);
	UniquePointer(UniquePointer<Object> &&);
	~UniquePointer();

	UniquePointer<Object> &operator=(const UniquePointer<Object> &) = delete;
	const UniquePointer<Object> &operator =(const UniquePointer<Object> &) const;

	Object* operator->();
	Object& operator*();

	const Object* operator->() const;
	const Object& operator*() const;

private:
	void assign(const UniquePointer<Object> &) const;
	mutable Object *object;
};

template<class Object, class ... Args>
UniquePointer<Object> makeUnique(Args ... args);

}}

// implementation
namespace tpl
{namespace templates
{

template<class Object>
UniquePointer<Object>::UniquePointer() :
		object(nullptr)
{
}

template<class Object>
UniquePointer<Object>::UniquePointer(UniquePointer<Object> &pointer)
{
	assign(pointer);
}

template<class Object>
UniquePointer<Object>::UniquePointer(UniquePointer<Object> &&pointer)
{
	assign(pointer);
}

template<class Object>
UniquePointer<Object>::~UniquePointer()
{
	delete object;
}

template<class Object>
const UniquePointer<Object>& UniquePointer<Object>::operator =(const UniquePointer<Object> &uniquePointer) const
{
	assign(uniquePointer);
	return *this;
}

template<class Object>
Object *UniquePointer<Object>::operator->()
{
	return object;
}

template<class Object>
Object &UniquePointer<Object>::operator*()
{
	return *object;
}

template<class Object>
const Object *UniquePointer<Object>::operator->() const
{
	return object;
}

template<class Object>
const Object &UniquePointer<Object>::operator*() const
{
	return *object;
}

template<class Object>
void UniquePointer<Object>::assign(const UniquePointer<Object> &pointer) const
{
	object = pointer.object;
	pointer.object = nullptr;
}

template<class Object, class ... Args>
UniquePointer<Object> makeUnique(Args ... args)
{
	UniquePointer<Object> pointer;
	pointer.object = new Object(args ...);
	return pointer;
}

}}

#endif // UNIQUEPOINTER_HPP
