#ifndef __KM_QUEUE_H__
#define __KM_QUEUE_H__

namespace km{

template<class Value, class Alloc=std::allocator<Value> >
class queue{

public:
	typedef Value value_type;
	typedef Alloc allocator_type;
	typedef typename allocator_type::reference reference;
	typedef typename allcoator_type::const_reference const_reference;
	typedef size_t size_type;

	enum{
		ERR_OK = 0,
		ERR_FULL = 1,
		ERR_EMPTY = 2,
		ERR_UNKNOWN,
	};

	queue(size_type max_size = default_values_size);
	~queue();

	int push(Value &v);
	int push_nowait(Value &v);

	int pop(Value &v);
	int pop_nowait(Value &v);
	
private:
	value_type *_values;
	size_t _max_size;
	size_t _in_pos;
	size_t _out_pos;
	
}; // class queue

} // namespace km

#endif // __KM_QUEUE_H__
