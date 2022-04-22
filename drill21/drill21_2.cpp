//drill második része - map

//map - kulcs,ertek par tipusokat kell eloszor megadni, egyszer szerepelhetnek az ertekek
	//- sorrendiseg adott a map tulajdonsagai miatt, asszociativ kontener
//set - rendezett kulcsokat tartalmaz, egyedi kulcsok, asszociativ kontener
	//- pl vektorbol a duplikalt elemek kiszurese (dupla ciklus helyett copy-val beszuras a setbe duplikalt kontenerbol)

#include <iostream>
#include <map>
#include <string>
#include <stdexcept>
#include <numeric>

template<typename K, typename V>
	void print(const std::map<K,V>& m){
		for (std::pair<K,V> i : m){
	  //for(auto& i : m) - ugyanaz
			std::cout << i.first << '\t' << i.second << std::endl;
		}
	}

//referencia azert van mert modositani kell majd
void read_map(std::map<std::string,int>& m){
	std::string s;
	int i = 0;
	while(m.size() < 10){
		std::cin >> s >> i;
		//m[s] = i;
		m.insert(std::make_pair(s,i));
	}
}

int main()
try{
	std::map<std::string,int> msi;
	msi["a"] = 1;
	msi["b"] = 3;
	msi["ab"] = 7;
	msi["efgh"] = 98;
	msi["xy"] = 76;
	msi["qw"] = 61;
	msi["efh"] = 60;
	msi["xc"] = 23;
	msi["qwertz"] = 11;
	msi["ax"] = 1;

	std::cout << "MSI map: " << std::endl;
	print(msi);

	//std::pair --> kulcs és ertek osszekapcsolasa
	//foreach ciklus minden ilyen kollekcional megoldas
	//ha auto-t hasznalunk drillbe -> kell tudni amilyen tipust helyettesit

	msi.erase("a");
	std::cout << std::endl << "Egy elem törlése után: " << std::endl;
	print(msi);

	msi.erase(msi.begin(),msi.end()); //üres lesz a map
	std::cout << std::endl << "Teljes törlés után: " << std::endl;
	print(msi);

	std::cout << std::endl << "Adj meg 10 kulcs érték párt!" << std::endl;
	read_map(msi);
	std::cout << std::endl << "msi beolvasás után: " << std::endl;
	print(msi);

	int sum_of_values = 0;
	for(std::pair<std::string,int> a : msi)
		sum_of_values += a.second;

	std::cout << std::endl << "Értékek összege: " << sum_of_values << std::endl;

	//masik osszeadas(mindketto jo megoldas):
	/*int total = std::accumulate(msi.begin(),msi.end(),0,
					[](int sum, const std::pair<std::string,int>& p)
					{return sum += p.second;}
					);

	std::cout << "Értékek összege2: " << total << std::endl;*/

	//kulcs ertek csere
	std::map<int,std::string>mis;
	for(std::pair<std::string,int> i : msi){
		mis[i.second] = i.first;
	}

	std::cout << std::endl << "mis map: " << std::endl;
	print(mis);

}catch (std::exception& e) {
	std::cerr << "Exception: " << e.what() << std::endl;
	return 1;
}catch (...){
	std::cerr << "Unknown exception " << std::endl;
	return 2;
}