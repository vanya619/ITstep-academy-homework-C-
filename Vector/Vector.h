#include <iostream>

template <typename Type>
class Vector
{
private:

	int addlSize;
	int size;
	Type* arr;

public:

	Vector()
		: arr{ nullptr }, size{ 0 }, addlSize{ 0 }
	{}

	Vector(Type _data)
		: addlSize{ 15 }, size{ 10 }, arr{ new Type[addlSize] }

	{
		arr[0] = _data;
	}

	Vector(const Vector& obj)
		: addlSize{ obj.addlSize }, size{ obj.size }, arr{ new Type[obj.addlSize] }
	{
		for (int i = 0; i < obj.size; ++i)
			arr[i] = obj.arr[i];
	}

	Vector(const std::initializer_list<Type>& list)
		: addlSize{ static_cast<int>(list.size() * 1.5) }, size{ static_cast<int>(list.size()) }, arr{ new Type[addlSize] }
	{
		int i = 0;
		for (const Type& val : list)
			arr[i++] = val;
	}

	Vector& operator= (const Vector& obj)
	{
		if (&obj != this)
		{
			Clear();

			arr = new Type[obj.addlSize];
			addlSize = obj.addlSize;
			size = obj.size;

			for (int i = 0; i < size; ++i)
				arr[i] = obj[i];
		}
	}

	Type& operator[] (int index)
	{
		return arr[index];
	}

	Type& at(int index)
	{
		if (index > -1 && index < size)
			return operator[index];
		throw std::exception("Array out of range");
	}

	int Capacity() const
	{
		return addlSize - size;
	}

	void Swap(Vector& obj)
	{
		std::swap(arr, obj.arr);
		std::swap(size, obj.size);
		std::swap(addlSize, obj.addlSize);
	}

	bool Empty() const
	{
		if (arr)
			return true;
		return false;
	}

	void Clear()
	{
		if (arr)
			delete[] arr;
		size = 0;
		addlSize = 0;
	}

	template <typename Type>
	friend std::ostream& operator<< (std::ostream& oss, const Vector<Type> obj)
	{
		for (int i = 0; i < obj.size; ++i)
			oss << obj.arr[i] << " ";
		return oss;
	}

	~Vector()
	{
		Clear();
	}
};


