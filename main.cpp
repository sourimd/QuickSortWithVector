#include <iostream>
#include <vector>

void display( std::vector<int> & vec){
	int s = vec.size();
	for(int i = 0; i< s; i++){
		std::cout << vec[i] << "->" ;
	}
	std::cout << "end" << std::endl;
}

void quickSort( std::vector<int> & vec , int start, int end){
	if( start == end ){
		return;
	}
	else{
		int pivot = (start+end)/2;
		int p = start;
		int temp;
		while( p < pivot){
			if( vec[p] > vec[pivot]){
				temp = vec[p];
				int i;
				//shift a whole bunch
				for(i = p; i<end; i++ ){
					vec[i] = vec[i+1];
				}
				vec[i] = temp;
				--pivot;
			}
			else{
				++p;
			}
		}
		p = pivot+1;
		while( p <= end ){
			if( vec[p] < vec[pivot]){
				temp = vec[p];
				int i;
				for(i=p;i>pivot;i--){
					vec[i]=vec[i-1];
				}
				vec[i] = temp;
				++pivot;
				++p; 
			}
			else{
				++p;
			}
		}
		if( pivot != start ){
			quickSort( vec, start, pivot-1);
		}
		
		if(pivot != end){
			quickSort( vec, pivot+1, end);
		}
		
	}
}

int main(){
	std::vector<int> vec;
	vec.reserve(16);

	vec.push_back( 34);
	vec.push_back( 12);
	vec.push_back( 71);
	vec.push_back( 21);
	vec.push_back( 25);
	vec.push_back( 56);
	vec.push_back( 85);
	vec.push_back( 92);
	vec.push_back( 43);
	vec.push_back( 87);
	vec.push_back( 55);
	vec.push_back( 11);
	vec.push_back( 90);
	vec.push_back( 8);
	vec.push_back( 57);
	vec.push_back( 84);

	display( vec );

	quickSort( vec, 0, 15);
	display( vec );
}