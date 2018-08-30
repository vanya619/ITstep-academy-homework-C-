#include <iostream>

template<typename Type>
class Stack
{
private:

	struct element
	{
		element *next;
		element *previous;
		Type data;

		element()
			:next(nullptr), previous(nullptr)
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

	 Stack& getCopy () const
	{
		Stack *copy = new Stack;
		element *iterator = top_element;

		while (iterator)
		{
			copy->push(iterator->data);
			iterator = iterator->previous;
		}
		return *copy;
	}

	 Stack& operator= (Stack& obj)
	 {
		 if (&obj != this)
		 {
			 ~Stack();
			 top_element = obj.getCopy().top_element;
			 size = obj.size;
		 }
		 return *this;
	 }

	void push(Type _data)
	{
		if (!top_element)
		{
			top_element = new element(_data);
			size = 1;
		}
		else
		{
			top_element->next = new element(_data);
			top_element->next->previous = top_element;
			top_element = top_element->next;
			++size;
		}
	}

	inline bool nullOrEmpty()
	{
		return top_element;
	}

	inline int getSize()
	{
		return size;
	}

	Type pop()
	{
		if (size)
		{
			element del = top_element;
			Type ret = del->data;
			top_element = top_element->previous;
			top_element->next = nullptr;
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

	~Stack()
	{
		element *iterator;
		while (top_element)
		{
			iterator = top_element;
			top_element = top_element->previous;
			delete iterator;
		}
	}
};

