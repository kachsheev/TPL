/*
 * file:       ObjectPool.hpp
 *
 * created:    11.09.2016
 * author:     Anton Kashcheev
 */

#ifndef OBJECTPOOL_HPP
#define OBJECTPOOL_HPP

#include <cstdint>

// declaration
namespace tpl
{

template<class Object>
class ObjectPool
{
public:
	typedef std::size_t Size;

	ObjectPool();
	ObjectPool(const ObjectPool<Object> &);
	ObjectPool(ObjectPool<Object> &&);
	~ObjectPool();

	ObjectPool<Object> &operator=(const ObjectPool<Object> &objectPool);
	ObjectPool<Object> &operator=(ObjectPool<Object> &&objectPool);

	void reserve(std::size_t size);
	void resize(std::size_t size);

	void clear();

	std::size_t size();

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
//namespace tpl
//{
//}
#endif // OBJECTPOOL_HPP
