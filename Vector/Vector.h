#include <iostream>

template <typename Type>
class Vector
{
private:

	int addSize;
	int size;
	Type* arr;

public:

	Vector()
		: arr{ nullptr }, size{ 0 }, addSize{ 0 }
	{}

	Vector(Type _data)
		//: addSize{ 15 }, size{ 1 }, arr{ new Type[addSize] }
	{
		//arr[0] = _data;
		Add(_data);
	}

	Vector(const Vector& obj)
		: addSize{ obj.addSize }, size{ obj.size }, arr{ new Type[obj.addSize] }
	{
		for (int i = 0; i < obj.size; ++i)
			arr[i] = obj.arr[i];
	}

	Vector(const std::initializer_list<Type>& list)
		: addSize{ static_cast<int>(list.size() * 1.5) }, size{ static_cast<int>(list.size()) }, arr{ new Type[addSize] }
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

			arr = new Type[obj.addSize];
			addSize = obj.addSize;
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
		return addSize - size;
	}

	void Swap(Vector& obj)
	{
		std::swap(arr, obj.arr);
		std::swap(size, obj.size);
		std::swap(addSize, obj.addSize);
	}

	void Add(Type _data)
	{
		if (!arr)
		{
			addSize = 15;
			size = 1;
			arr = new Type[addSize];
			arr[0] = _data;
		}
		else if (addSize == size)
		{
			addSize = static_cast<int>(addSize * 1.5);
			Type* copy = new Type[addSize];
			for (int i = 0; i < size; ++i)
				copy[i] = arr[i];
			copy[size++] = _data;
			delete[] arr;
			arr = copy;
		}
		else
		{
			arr[size++] = _data;
		}
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
		addSize = 0;
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