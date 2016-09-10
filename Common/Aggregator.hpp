/*
 * file:       Aggregator.hpp
 *
 * created:    26.08.2016
 * author:     Anton Kashcheev
 */
#ifndef COMMON_AGGREGATOR_HPP
#define COMMON_AGGREGATOR_HPP

#include <cstdint>

// declaration
namespace tpl
{namespace templates
{

template<unsigned int number, class HeadType, class ... TailTypes>
struct TypeGetter;

template<class ... Objects>
class Aggregator
{

public:
	bool init() const;

	template<unsigned int number>
	typename TypeGetter<number, Objects ... >::ValueType *pointer() noexcept;
	template<unsigned int number>
	const typename TypeGetter<number, Objects ... >::ValueType *pointer() const noexcept;

	template<unsigned int number>
	typename TypeGetter<number, Objects ... >::ValueType &get();
	template<unsigned int number>
	const typename TypeGetter<number, Objects ... >::ValueType &get() const;

	template<unsigned int number>
	void initialize();
	template<unsigned int number, class ... Args>
	void initialize(Args ... args);

	void initialize();
	template<class ... Args>
	void initialize(Args ... args);

	static inline constexpr unsigned int countArgs()
	{
		return (sizeof ... (Objects));
	}
};

template<class HeadObject, class ... TailObjects>
class Aggregator<HeadObject, TailObjects ...> : public Aggregator<TailObjects ...>
{
	HeadObject *headObject;
public:
	typedef Aggregator<HeadObject, TailObjects ...> CurrentType;
	typedef HeadObject ValueType;
	typedef Aggregator<TailObjects ...> BaseType;

	Aggregator();
	~Aggregator();

	bool init() const;

	template<unsigned int number>
	bool init() const;

	ValueType* pointer()  noexcept;
	const ValueType* pointer() const noexcept;

	template<unsigned int number>
	typename TypeGetter<number, HeadObject, TailObjects ... >::ValueType* pointer() noexcept;
	template<unsigned int number>
	const typename TypeGetter<number, HeadObject, TailObjects ... >::ValueType* pointer() const noexcept;

	ValueType &get();
	const ValueType &get() const;

	template<unsigned int number>
	typename TypeGetter<number, HeadObject, TailObjects ... >::ValueType &get();
	template<unsigned int number>
	const typename TypeGetter<number, HeadObject, TailObjects ... >::ValueType &get() const;

	void initialize();
	template<class ... Args>
	void initialize(Args ... args);

	template<unsigned int number>
	void initialize();
	template<unsigned int number, class ... Args>
	void initialize(Args ... args);

	static inline constexpr unsigned int countArgs()
	{
		return (sizeof ... (TailObjects)) + 1;
	}
};

template<>
class Aggregator<>
{
};

}}

// implementation
namespace tpl
{namespace templates
{

template<class HeadObject, class ... TailObjects>
Aggregator<HeadObject, TailObjects ...>::Aggregator() :
		Aggregator<TailObjects ...>(),
		headObject(nullptr)
{
}

template<class HeadObject, class ... TailObjects>
Aggregator<HeadObject, TailObjects ...>::~Aggregator()
{
	delete headObject;
}

template<class HeadObject, class ... TailObjects>
bool
Aggregator<HeadObject, TailObjects ...>::init() const
{
	return headObject != nullptr;
}

template<class HeadObject, class ... TailObjects>
typename Aggregator<HeadObject, TailObjects ...>::ValueType *
Aggregator<HeadObject, TailObjects ...>::pointer() noexcept
{
	return headObject;
}

template<class HeadObject, class ... TailObjects>
const typename Aggregator<HeadObject, TailObjects ...>::ValueType *
Aggregator<HeadObject, TailObjects ...>::pointer() const noexcept
{
	return headObject;
}

template<class HeadObject, class ... TailObjects>
template<unsigned int number>
typename TypeGetter<number, HeadObject, TailObjects ... >::ValueType *
Aggregator<HeadObject, TailObjects ...>::pointer() noexcept
{
	return TypeGetter<number, HeadObject, TailObjects ... >::pointer(*this);
}

template<class HeadObject, class ... TailObjects>
template<unsigned int number>
const typename TypeGetter<number, HeadObject, TailObjects ... >::ValueType *
Aggregator<HeadObject, TailObjects ...>::pointer() const noexcept
{
	return TypeGetter<number, HeadObject, TailObjects ... >::pointer(*this);
}

template<class HeadObject, class ... TailObjects>
typename Aggregator<HeadObject, TailObjects ...>::ValueType &
Aggregator<HeadObject, TailObjects ...>::get()
{
	return *headObject;
}

template<class HeadObject, class ... TailObjects>
const typename Aggregator<HeadObject, TailObjects ...>::ValueType &
Aggregator<HeadObject, TailObjects ...>::get() const
{
	return *headObject;
}

template<class HeadType, class ... TailTypes>
template<unsigned int number>
typename TypeGetter<number, HeadType, TailTypes ... >::ValueType &
Aggregator<HeadType, TailTypes ...>::get()
{
	return TypeGetter<number, HeadType, TailTypes ... >::get(*this);
}

template<class HeadType, class ... TailTypes>
template<unsigned int number>
const typename TypeGetter<number, HeadType, TailTypes ... >::ValueType &
Aggregator<HeadType, TailTypes ...>::get() const
{
	return TypeGetter<number, HeadType, TailTypes ... >::get(*this);
}

template<class HeadObject, class ... TailObjects>
void Aggregator<HeadObject, TailObjects ...>::initialize()
{
	headObject = new HeadObject();
}

template<class HeadObject, class ... TailObjects>
template<class ... Args>
void Aggregator<HeadObject, TailObjects ...>::initialize(Args ... args)
{
	headObject = new HeadObject(args ...);
}

template<class HeadObject, class ... TailObjects>
template<unsigned int number>
void Aggregator<HeadObject, TailObjects ...>::initialize()
{
	TypeGetter<number, HeadObject, TailObjects ...>::initialize(*this);
}

template<class HeadObject, class ... TailObjects>
template<unsigned int number, class ... Args>
void Aggregator<HeadObject, TailObjects ...>::initialize(Args ... args)
{
	TypeGetter<number, HeadObject, TailObjects ...>::initialize(*this, args ...);
}

}}


// declaration
namespace tpl
{namespace templates
{

template<unsigned int number, class HeadType, class ... TailTypes>
struct TypeGetter
{
	typedef TypeGetter<number - 1, TailTypes ...> NextTypeGetter;
	typedef typename NextTypeGetter::ValueType ValueType;
	typedef Aggregator<HeadType, TailTypes...> CurrentAggregator;

	static ValueType &get(CurrentAggregator &aggregator)
	{
		return NextTypeGetter::get(aggregator);
	}

	template<class ... Args>
	static void initialize(CurrentAggregator &aggregator, Args ... args)
	{
		NextTypeGetter::initialize(aggregator, args ...);
	}

	static void initialize(CurrentAggregator &aggregator)
	{
		NextTypeGetter::initialize(aggregator);
	}

	static const ValueType *pointer(const CurrentAggregator &aggregator) noexcept
	{
		return NextTypeGetter::pointer(aggregator);
	}

	static ValueType *pointer(CurrentAggregator &aggregator) noexcept
	{
		return NextTypeGetter::pointer(aggregator);
	}
};

template<class HeadType, class ... TailTypes>
struct TypeGetter<0u, HeadType, TailTypes ...>
{
	typedef Aggregator<HeadType, TailTypes ...> CurrentAggregator;
	typedef typename CurrentAggregator::ValueType ValueType;

	static const ValueType &get(const CurrentAggregator &aggregator)
	{
		return aggregator.get();
	}

	static ValueType &get(CurrentAggregator &aggregator)
	{
		return aggregator.get();
	}

	template<class ... Args>
	static void initialize(CurrentAggregator &aggregator, Args ... args)
	{
		return aggregator.initialize(args ...);
	}

	static void initialize(CurrentAggregator &aggregator)
	{
		return aggregator.initialize();
	}

	static const ValueType *pointer(const CurrentAggregator &aggregator) noexcept
	{
		return aggregator.pointer();
	}

	static ValueType *pointer(CurrentAggregator &aggregator) noexcept
	{
		return aggregator.pointer();
	}
};

}}

#endif // COMMON_AGGREGATOR_HPP
