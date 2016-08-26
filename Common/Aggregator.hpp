/*
 * file:       Aggregator.hpp
 *
 * created:    26.08.2016
 * author:     Anton Kashcheev
 */
#ifndef COMMON_AGGREGATOR_HPP
#define COMMON_AGGREGATOR_HPP

// declaration
namespace tpl
{namespace templates
{

template<class ... Objects>
class Aggregator;

template<class HeadObject, class ... TailObjects>
class Aggregator<HeadObject, TailObjects ...> : public Aggregator<TailObjects ...>
{
	HeadObject *headObject;
public:
	typedef HeadObject ValueType;
	typedef Aggregator<TailObjects ...> BaseType;

	Aggregator();

	bool init() const;

	void initialize();

	template<class ... Args>
	void initialize(Args ... args);

	ValueType* pointer();
	const ValueType* pointer() const;

	ValueType &get();
	const ValueType &get() const;
};

template<>
class Aggregator<>
{
};

template<unsigned int count, class HeadObject, class ... TailObjects>
class Getter
{
public:
	typedef typename Getter<count - 1, TailObjects ...>::ReturnType ReturnType;
	static ReturnType& get(Aggregator<HeadObject, TailObjects ...> &&aggregator)
	{
		return Getter<count - 1, TailObjects ...>::get(aggregator);
	}
	static const ReturnType& get(const Aggregator<HeadObject, TailObjects ...> &aggregator)
	{
		return Getter<count - 1, TailObjects ...>::get(aggregator);
	}
};

template<class HeadObject, class ... TailObjects>
class Getter<0U, HeadObject, TailObjects ...>
{
public:
	typedef typename Aggregator<HeadObject, TailObjects ...>::ValueType ReturnType;
	static ReturnType& get(Aggregator<HeadObject, TailObjects ...> &&aggregator)
	{
		return aggregator.get();
	}
	static const ReturnType& get(const Aggregator<HeadObject, TailObjects ...> &aggregator)
	{
		return aggregator.get();
	}

template<class ... Args>
constexpr unsigned int getCountArguments(Args ...) noexcept;

template<unsigned int count, typename HeadObjects, typename... TailObjects>
typename Getter<count, HeadObjects, TailObjects...>::ReturnType &
get(Aggregator<HeadObjects, TailObjects...> &&aggregator);

template<unsigned int count, typename HeadObjects, typename... TailObjects>
const typename Getter<count, HeadObjects, TailObjects...>::ReturnType &
get(const Aggregator<HeadObjects, TailObjects...> &aggregator);

};

}}

// implementation
namespace tpl
{namespace templates
{

template<class HeadObject, class ... TailObjects>
Aggregator<HeadObject, TailObjects ...>::Aggregator() :
		headObject(nullptr)
{
}

template<class HeadObject, class ... TailObjects>
bool
Aggregator<HeadObject, TailObjects ...>::init() const
{
	return headObject != nullptr;
}

template<class HeadObject, class ... TailObjects>
void
Aggregator<HeadObject, TailObjects ...>::initialize()
{
	headObject = new HeadObject();
}

template<class HeadObject, class ... TailObjects>
template<class ... Args>
void
Aggregator<HeadObject, TailObjects ...>::initialize(Args ... args)
{
	headObject = new HeadObject(args ...);
}

template<class HeadObject, class ... TailObjects>
Aggregator<HeadObject, TailObjects ...>::ValueType *
Aggregator<HeadObject, TailObjects ...>::pointer()
{
	return headObject;
}

template<class HeadObject, class ... TailObjects>
const Aggregator<HeadObject, TailObjects ...>::ValueType *
Aggregator<HeadObject, TailObjects ...>::pointer() const
{
	return headObject;
}

template<class HeadObject, class ... TailObjects>
Aggregator<HeadObject, TailObjects ...>::ValueType &
Aggregator<HeadObject, TailObjects ...>::get()
{
	return *headObject;
}

template<class HeadObject, class ... TailObjects>
const Aggregator<HeadObject, TailObjects ...>::ValueType &
Aggregator<HeadObject, TailObjects ...>::get() const
{
	return *headObject;
}

template<unsigned int count, class HeadObject, class ... TailObjects>
Getter<count, HeadObject, TailObjects ...>::ReturnType &
Getter<count, HeadObject, TailObjects ...>::get(Aggregator<HeadObject, TailObjects ...> &&aggregator)
{
	return Getter<count - 1, TailObjects ...>::get(aggregator);
}

template<unsigned int count, class HeadObject, class ... TailObjects>
const Getter<count, HeadObject, TailObjects ...>::ReturnType &
Getter<count, HeadObject, TailObjects ...>::get(const Aggregator<HeadObject, TailObjects ...> &&aggregator)
{
	return Getter<count - 1, TailObjects ...>::get(aggregator);
}

template<class HeadObject, class ... TailObjects>
Getter<0U, HeadObject, TailObjects ...>::ReturnType &
Getter<0U, HeadObject, TailObjects ...>::get(Aggregator<HeadObject, TailObjects ...> &&aggregator)
{
	return aggregator.get();
}

template<class HeadObject, class ... TailObjects>
const Getter<0U, HeadObject, TailObjects ...>::ReturnType &
Getter<0U, HeadObject, TailObjects ...>::get(const Aggregator<HeadObject, TailObjects ...> &aggregator)
{
	return aggregator.get();
}

template<class ... Args>
constexpr unsigned int getCountArguments(Args ...) noexcept
{
	return sizeof...(Args);
}

template<unsigned int count, typename HeadObjects, typename... TailObjects>
typename Getter<count, HeadObjects, TailObjects...>::ReturnType &
get(Aggregator<HeadObjects, TailObjects...> &&aggregator)
{
	return Getter<count, HeadObjects, TailObjects...>::get(aggregator);
}

template<unsigned int count, typename HeadObjects, typename... TailObjects>
const typename Getter<count, HeadObjects, TailObjects...>::ReturnType &
get(const Aggregator<HeadObjects, TailObjects...> &aggregator)
{
	return Getter<count, HeadObjects, TailObjects...>::get(aggregator);
}



}}


#endif // COMMON_AGGREGATOR_HPP
