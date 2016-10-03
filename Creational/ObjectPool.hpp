/*
 * file:       ObjectPool.hpp
 *
 * created:    11.09.2016
 * author:     Anton Kashcheev
 */

#ifndef OBJECTPOOL_HPP
#define OBJECTPOOL_HPP

#include <assert.h>
#include "../Common/Types.hpp"

// declaration
namespace tpl
{

template<class Object>
class ObjectPool
{
public:
	typedef types::size_t Size;

	ObjectPool();
	ObjectPool(Size size);
	ObjectPool(const ObjectPool<Object> &) = delete;
	ObjectPool(ObjectPool<Object> &&) = delete;
	~ObjectPool();

	ObjectPool<Object> &operator=(const ObjectPool<Object> &objectPool);
	ObjectPool<Object> &operator=(ObjectPool<Object> &&objectPool);

	void reserve(Size size);
	void resize(Size size);

	void clean();

	Size size();
	Size capacity();

	void incrementSize();
	void decrementSize();

	Object &get(Size index) noexcept;
	template<class RealObject>
	RealObject &get(Size index) noexcept;

	const Object &get(Size index) const noexcept;
	template<class RealObject>
	const RealObject &get(Size index) const noexcept;

	Object &operator[](Size index) noexcept;
	template<class RealObject>
	RealObject &operator[](Size index) noexcept;

	Object &operator[](Size index) const noexcept;
	template<class RealObject>
	RealObject &operator[](Size index) const noexcept;

	Object *pointer() noexcept;
	template<class RealObject>
	RealObject *pointer() noexcept;

	const Object *pointer() const noexcept;
	template<class RealObject>
	const RealObject *pointer() const noexcept;

	void init(Size index);
	template<class ... Args>
	void init(Size index, Args && ... args);

	void defaultInit();

protected:

private:
	Object **arrayObjectPool;
	Size poolSize;
	Size poolCapacity;
};

}

// implementation
namespace tpl
{

template<class Object>
ObjectPool<Object>::ObjectPool() :
		arrayObjectPool(nullptr),
		poolSize(0),
		poolCapacity(0)
{

}

template<class Object>
ObjectPool<Object>::ObjectPool(types::size_t size) :
		poolSize(0),
		poolCapacity(size)
{
	arrayObjectPool = new Object*[poolCapacity];
	for (Size i = 0; i < poolCapacity; ++i)
	{
		arrayObjectPool[i] = nullptr;
	}
}

template<class Object>
void ObjectPool<Object>::reserve(types::size_t size)
{
	Object **tempArrayPool = new Object *[poolCapacity + size];
	for (Size i = 0; i < poolSize; ++i)
	{
		tempArrayPool[i] = arrayObjectPool[i];
	}
	delete[] arrayObjectPool;
	arrayObjectPool = tempArrayPool;
	poolCapacity += size;
}

template<class Object>
void ObjectPool<Object>::resize(types::size_t size)
{
	if (size > poolCapacity)
	{
		Object **tempArrayPool = new Object *[size];
		for (Size i = 0; i < poolSize; ++i)
		{
			tempArrayPool[i] = arrayObjectPool[i];
		}
		delete[] arrayObjectPool;
		arrayObjectPool = tempArrayPool;
		poolCapacity = size;
	}
}

template<class Object>
void ObjectPool<Object>::clean()
{
	for (Size i = 0; i < poolSize; ++i)
	{
		delete arrayObjectPool[i];
	}
	poolSize = 0;
}

template<class Object>
typename types::size_t ObjectPool<Object>::size()
{
	return poolSize;
}

template<class Object>
typename types::size_t ObjectPool<Object>::capacity()
{
	return poolCapacity;
}

template<class Object>
void ObjectPool<Object>::incrementSize()
{
	assert(poolSize != poolCapacity);
	++poolSize;
}

template<class Object>
Object &ObjectPool<Object>::get(typename types::size_t index) noexcept
{
	assert(index < poolSize);
	return *arrayObjectPool[index];
}

template<class Object>
template<class RealObject>
RealObject &ObjectPool<Object>::get(typename types::size_t index) noexcept
{
	assert(index < poolSize);
	return *static_cast<RealObject *>(arrayObjectPool[index]);
}

template<class Object>
const Object &ObjectPool<Object>::get(typename types::size_t index) const noexcept
{
	assert(index < poolSize);
	return *arrayObjectPool[index];
}

template<class Object>
template<class RealObject>
const RealObject &ObjectPool<Object>::get(typename types::size_t index) const noexcept
{
	assert(index < poolSize);
	return *static_cast<RealObject *>(arrayObjectPool[index]);
}

}

#endif // OBJECTPOOL_HPP
