#include <iostream>

template <typename Type>
class Collection
{
private:
	Type* collection;
	int size;

public:
	Collection(Type count)
		: collection{ new Type{ count } }, size{ 1 }
	{}

	Collection(Type *val, int size_)
		: collection{ new Type[size_] }, size{ size_ }
	{
		for (int i = 0; i < size; ++i)
			collection[i] = val[i];
	}

	template <typename Type>
	Collection(std::initializer_list<Type> list)
		:collection{ new Type[list.size()] }, size{ static_cast<int>(list.size()) }
	{
		int i = 0;
		for (const int& val : list)
			collection[i++] = val;
	}

	~Collection()
	{
		size > 1 ? delete[] collection : delete collection;
	}

	template <typename Type>
	friend std::ostream& operator<< (std::ostream& oss, const Collection<Type>& obj);
};

template <typename Type>
std::ostream& operator<< (std::ostream& oss, const Collection<Type>& obj)
{
	for (int i = 0; i < obj.size; ++i)
		oss << obj.collection[i] << " ";
	return oss;
}
