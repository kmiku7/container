#include <cstdlib>
#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>
#include "deheap.h"
#include "km_utility.h"

using namespace std;
using namespace km;

int main(int argc, char**argv){

	deheap<int> deh;
	vector<int> v;

	utility::init_random_seed();

	for( int i=0; i<1000; i++){
		int next = rand();
		deh.push(next);
		v.push_back(next);
		
		assert( *max_element(v.begin(),v.end())==deh.getMax() 
				and *min_element(v.begin(),v.end())==deh.getMin());
	}

	while( deh.size()>1){
		if(not( *max_element(v.begin(),v.end())==deh.getMax() 
				and *min_element(v.begin(),v.end())==deh.getMin())){
			cout<<*max_element(v.begin(),v.end())<<endl;
			cout<<*min_element(v.begin(),v.end())<<endl;
			cout<<deh.getMax()<<endl;
			cout<<deh.getMin()<<endl;
			copy(v.begin(),v.end(),ostream_iterator<int>(cout," "));
			cout<<endl;
			copy(deh.begin(),deh.end(),ostream_iterator<int>(cout," "));
			cout<<endl;
			break;
		}
		v.erase(max_element(v.begin(),v.end()));
		v.erase(min_element(v.begin(),v.end()));
		deh.popMax();
		deh.popMin();
	}

	return 0;
}
