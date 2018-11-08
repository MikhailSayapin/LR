#include <iostream>
#include <atomic>
using namespace std;

struct Control_block
{
	atomic_uint counter;
	Control_block()
	{
		counter = 0;
	}

	void add()
	{
		counter++;
	}

	void del()
	{
		counter--;
	}

	bool is_empty()
	{
		return counter == 1;
	}

	int value_counter()
	{
		return counter;
	}
};

template <typename T>
class SharedPtr
{
	T *ptr;
	Control_block *control_block;
public:
	SharedPtr()
	{
		ptr = nullptr;
		control_block = nullptr;
	}

	T* get()
	{
		if (ptr == nullptr)
		{
			return 0;
		}

		else
		{
			return ptr;
		}
	}
	SharedPtr(SharedPtr & shared_ptr)
	{
		ptr = shared_ptr.get();
		control_block = shared_ptr.control_block;
		control_block->add();
	}

	SharedPtr(T value)
	{
		ptr = new T(value);
		control_block = new Control_block;
		control_block->add();
	}

	SharedPtr & operator = (const SharedPtr & shared_ptr)
	{
		ptr = shared_ptr.get();
		control_block = shared_ptr.control_block;
		control_block->add();
		return *this;
	}

	void reset()
	{
		if (control_block->is_empty())
		{
			delete ptr;
			delete control_block;
		}

		else
		{
			ptr = nullptr;
			control_block = nullptr;
		}
	}

	void reset(T *data)
	{
		ptr = data;
		control_block = new Control_block;
		control_block->add();
	}

	void swap(SharedPtr &shared_ptr)
	{
		std::swap(ptr, shared_ptr.ptr);
		std::swap(control_block, shared_ptr.control_block);
	}

	T& operator*()
	{
		return *ptr;
	}

	T* operator ->()
	{
		return ptr;
	}

	size_t use_count()
	{
		return control_block->value_counter();
	}

	operator bool()
	{
		return ptr != nullptr;
	}

	~SharedPtr()
	{
		if (control_block != nullptr)
		{
			if (!control_block->is_empty())
			{
				control_block->del();
			}

			else
			{
				delete ptr;
				delete control_block;
			}
		}
	}
};
