#include <iostream>
using namespace std;

template<typename T>
class SharedPtr
{
	struct control_block
	{
		T *ptr;
		unsigned int count = 0;
	};
	control_block block;
public:
	SharedPtr()
	{
		block.ptr = nullptr;
		block.count = 1;
	}

	SharedPtr(const SharedPtr &data)
	{
		this->block.ptr = data.block.ptr;
		block.count++;
	}

	SharedPtr &operator=(const SharedPtr &data)
	{
		if (block.ptr != data.block.ptr)
		{
			block.ptr = data.block.ptr;
		}

		if (block.count != data.block.count)
		{
			block.count = data.block.count;
		}
		return *this;
	}

	T& operator*()
	{
		return *(block.ptr);
	}

	T* operator->()
	{
		return block.ptr;
	}

	void reset() //Не забыть применить деструктор
	{
		block.ptr = nullptr;
		block.count = 0;
	}

	void reset(T *data_for_add)
	{
		reset();
		block.ptr = data_for_add;
	}

	void swap(SharedPtr &other)
	{
		swap(this->block.ptr, other.block.ptr);
		swap(this->block.count, other.block.count);
	}

	SharedPtr& swap(SharedPtr &other)
	{
		this->block.ptr = other.block.ptr;
		this->block.count = other.block.count;
		return *this;
	}

	T *get()
	{
		if (block.count != 0)
		{
			return block.ptr;
		}
	}

	unsigned int use_count()
	{
		return block.count;
	}

	operator bool()
	{
		return block.count != 0;
	}

	~SharedPtr()
	{
		if (block.count > 1)
		{
			block.count--;
		}

		else
		{
			block.ptr = nullptr;
			block.count = 0;
		}
	}
};
