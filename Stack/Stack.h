#include <iostream>

template<typename Type>
class Stack
{
private:

	struct element
	{
		element *previous;
		Type data;

		element()
			:previous(nullptr)
		{}

		element(Type _data)
			:element()
		{
			data = _data;
		}
	};

	int size;
	element *top_element;

public:

	Stack()
		: size(0), top_element(nullptr)
	{}

	Stack(const Stack& obj)
	{
		top_element = obj.getCopy().top_element;
		size = obj.size;
	}

	Stack& GetCopy() const
	{
		Stack *copy = new Stack;
		element *iterator = top_element;

		while (iterator)
		{
			copy->push(iterator->data);
			iterator = iterator->previous;
		}
		copy->size = size;
		return *copy;
	}

	Stack& operator= (Stack& obj)
	{
		if (&obj != this)
		{
			ClearStack();
			top_element = obj.getCopy().top_element;
			size = obj.size;
		}
		return *this;
	}

	void Push(Type _data)
	{
		if (!top_element)
		{
			top_element = new element(_data);
			size = 1;
		}
		else
		{
			element* newElement = new element(_data);
			newElement->previous = top_element;
			top_element = newElement;
			++size;
		}
	}

	inline bool NullOrEmpty()
	{
		return top_element;
	}

	inline int GetSize()
	{
		return size;
	}

	Type Pop()
	{
		if (size)
		{
			element* del = top_element;
			Type ret = del->data;
			top_element = top_element->previous;
			delete del;
			return ret;
		}
		throw std::exception("Stack is null");
	}

	friend std::ostream& operator<< (std::ostream& oss, const Stack& obj)
	{
		element *iterator = obj.top_element;
		while (iterator)
		{
			oss << iterator->data << std::endl;
			iterator = iterator->previous;
		}
		return oss;
	}

	void ClearStack()
	{
		element *iterator;

		while (top_element)
		{
			iterator = top_element;
			top_element = top_element->previous;
			delete iterator;
		}
		size = 0;
	}

	~Stack()
	{
		ClearStack();
	}
};
