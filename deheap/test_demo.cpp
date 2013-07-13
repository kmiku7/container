

#include <iostream>
#include <iterator>
#include <algorithm>

#include <deheap.h>

using namespace std;
using namespace km;


void print(deheap<int>& h){

	cout<<string(20,'-')<<endl;
	cout<<"Size: "<<h.size()<<endl;
	cout<<"Capacity: "<<h.capacity()<<endl;
	cout<<"Max: "<<h.getMax()<<" Min: "<<h.getMin()<<endl;
	copy(h.begin(), h.end(), ostream_iterator<int>(cout," "));
	cout<<endl;

}

int main(int argc, char** argv){

	deheap<int> deh;
	int next;
	string op;

	cout<<"Input Negative Number To Exit."<<endl;

	while(true){
		cout<<"Input:";
		cin>>op;
		if( op=="add" or op=="a"){
			cin>>next;
			deh.push(next);
		}else if(op=="removemax"){
			deh.popMax();
		}else if(op=="removemin"){
			deh.popMin();
		}else{
			break;
		}
		print(deh);
	}

	cout<<"END"<<endl;

	return 0;
}
