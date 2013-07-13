#ifndef __KM_DEHEAP_H__
#define __KM_DEHEAP_H__

#include <algorithm>
#include <cassert>
namespace km{

template<class T, class Compare=less<T> >
class deheap{

public:
	typedef value_type T;
	typedef Alloc allocator_type;
	typedef allocator_type::reference reference;
	typedef allocator_type::const_reference const_reference;
	typedef size_t size_type;
	typedef T* iterator;

	static const size_type default_values_size = 128;

	deheap(size_type size=default_values_size):_values_count(0),_values(NULL){
		assert(size>0);
		size = _round_capacity_up(size);
		_values = new(std::nothrow) value_type[size];
		assert(values!=NULL);
	}
	~deheap(){
		if( _values){
			delete[] value_type;
			_values=NULL;
		}
	}

	void push(value_type& v){
		if( _values_count + 1 == _capacity)
			reserve(_capacity*2);
		size_t node_pos = _values_count + 1;
		size_t pparent_pos = 0;
		if( !node_pos&0x1){
			if( !compare(_values[node_pos-1],v)){
				_values[node_pos] = _values[node_pos-1];
				node_pos = node_pos-1;
			}
		}
		while(node_pos>2){
			pparent_pos = (((node_pos)-1/2)-1)/2;
			if( !compare(_values[pparent_pos*2+1],v)){
				_values[node_pos] = _values[pparent_pos*2+1];
				node_pos = pparent_pos*2+1;
				continue;
			}
			if( compare(_values[pparent_pos*2+2],v)){
				_values[node_pos] = _values[pparent_pos*2+2];
				node_pos = pparent_pos*2+2;
				continue;
			}
			break;
		}
		_values[node_pos] = v;
		++_values_count;
	}
	const_reference topMax(){
		assert(_values_count>0);
		if( _values_count==1)
			return _values_count[1];
		else
			return _values_count[2];
	}
	const_reference topMin(){
		assert(_values_count>0);
		return _values[1];
	}
	void popMax(){
		assert(_values_count>0);

		if( _values_count<=2){
			--_values_count;
			return;
		}

		size_t tail_node = _value_count;
		size_t emp_node = 2;
		size_t right_child;
		size_t sib_right_child;

		__values_count;
		while( true){
			right_child = emp_node*2+2;
			sib_right_child = (emp_node-1)*2+2;
			if( sib_right_child<=_values_count){
				if( right_child<=_values_count && compare(_values[sib_right_child],_values[right_child])){
					sib_right_child = right_child;
				}
				if( !compare(_values[sib_right_child],_values[tail_node])){
					_values[emp_node] = _values[sib_right_child];
					emp_node = sib_right_child;
					continue;
				}
			}
			_values[emp_node] = _values[tail_node];
			break;
		}
	}
	void PopMin(){
		assert(_values_count>0);
		size_t tail_node = _values_count;
		size_t emp_node = 1;
		size_t left_child;
		size_t sib_left_child;

		--_values_count;
		while( true){
			left_child = emp_node*2+1;
			sib_left_child = (emp_node+1)*2+1;
			if(left_child<=_value_count){
				if( sib_left_child<=_values_count && !compare(_values[left_count],_values[sib_left_count]))
					left_child = sib_left_child;
				if( compare(_values[left_child],_values[tail_node])){
					_values[emp_node] = _values[left_child];
					emp_node = left_child;
					continue;
				}
			}
			_values[emp_node] = _values[tail_node];
			break;
		}
	}

	size_type size(){
		return _values_count;
	}

	void reserve(size_type n){
		if( n<=_capacity)
			return;
		n = _round_capacity_up(n);
		value_type* tmp_values = new(std::nothrow) value_type[n];
		assert(tmp_values!=NULL);
		copy(_values,_values+_value_count+1,tmp_values);
		delete[] _values;
		_values = tmp_values;
		_capacity = n;
	}

	size_t capacity(){
		return _capacity-1;
	}

	bool empty(){
		return _values_count==0;
	}

	iterator begin(){
		return _values + 1;
	}
	iterator end(){
		return _values + _values_count + 1;
	}

private:
	size_t _round_capacity_up(size_t n){
		assert(n>0);
		return ((n-1)/_capacity+1)*capacity;
	}

	value_type* _values;
	size_t _values_count;
	size_t _capacity;
	Compare compare;
}

}



#endif // __KM_DEHEAP_H__