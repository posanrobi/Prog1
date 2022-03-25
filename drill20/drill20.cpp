//pl.: *f2 = *f1 dereference operator -> ertekre mutat igy, nem a cimre
//distance operator - hany ugras van 2 dolog kozott
//kulon kontenerek:
#include <vector>
#include <list>
#include <array>
#include <string>
#include <iostream>
#include <algorithm>
#include <exception>

template<typename C>
void print(const C& c){

	for (auto i: c)
	{
		std::cout << i << ' ';
	}
	std::cout<<std::endl;
}

template<typename C> //increase the array,vector,array, template-be lehet egyszerre
void inc(C& c, int n){
	for(auto& i : c){
		i += n;
	}
}

template<typename Iter1, typename Iter2> //copy operation
// requires Input_iterator<Iter1>() && Output_iterator<Iter2>()
Iter2 orai_copy(Iter1 f1, Iter1 e1, Iter2 f2){
	for(Iter1 p = f1; p != e1; ++p){
		*f2++ = *p;
		//f2++; ez nem kell a fenti miatt (osszevonva van fent)
		//ha f1 == e1 a sor ures es nincs mit masolni
	}
	return f2;
}

int main()
try{

constexpr int size = 10; //10 elemu lesz, fix meret

int arr[size]; 
for(int i = 0; i < size; ++i) arr[i] = i;
std::cout << "C array: ";
print(arr);

std::array<int,size> ai;
std::copy(arr,arr+size,ai.begin()); 
std::cout << "std array: ";
print(ai);

std::vector<int>vi(size);
std::copy(arr,arr+size,vi.begin()); 
std::cout << "std vector: ";
print(vi);

std::list<int> li(size);
std::copy(arr,arr+size,li.begin()); 
std::cout << "std list: ";
print(li);

std::array<int,size> ai2 = ai; //copy of the first array
std::vector<int> vi2 = vi; //copy of the first vector
std::list<int> li2 = li;	//copy of the first list

print(ai2);
print(vi2);
print(li2);

inc(ai2,2);	//novelem 2vel
inc(vi2,3); //novelem 3mal
inc(li2,5); //novelem 5tel

print(ai2);
print(vi2);
print(li2);

orai_copy(ai2.begin(), ai2.end(), vi2.begin());
orai_copy(li2.begin(), li2.end(), ai2.begin());

print(ai2);
print(vi2);
print(li2);

std::vector<int>::iterator vit;
std::cout << "Does the vector contains the value 3? ";
vit = std::find(vi2.begin(), vi2.end(), 3);
if(vit != vi2.end()) {
	std::cout << "Found at: " << std::distance(vi2.begin(),vit) << std::endl;
}else {
	std::cout << "Not found" << std::endl;
}

std::list<int>::iterator lit;
std::cout << "Does the list contains the value 27? ";
lit = find(li2.begin(), li2.end(), 27);
if(lit != li2.end()) {
	std::cout << "Found at: " << std::distance(li2.begin(),lit) << std::endl;
}else {
	std::cout << "Not found" << std::endl;
}

}

catch(std::exception& e){
	std::cerr << "Exception: " << e.what() << std::endl;
	return 1;
}
catch(...){
	std::cerr << "Unknown exception" << std::endl;
	return 2;
}