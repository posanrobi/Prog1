#include <string>
#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

class Person {
public:
	Person(){}
	//Person(string n, int a) : n{n}, a{a}{
	Person(string f, string l,int a) : f{f},l{l},a{a}{

		if(a < 0 || a >=150) {
			throw runtime_error("Invalid age");
		}

		string n = f + l;

		char bad_characters [] = {';',':','"','\'','[',']','*','&','^','%','$','#','@','!'};

		for (int i = 0; i < n.length(); i++){
			for(int j = 0; j < 14; j++){
				if (n[i] == bad_characters[j])
					throw runtime_error("Invalid name");
			}
		}
		// vagy for (char c: n){ swich(c) case ';': ...
	};

	string first() const {return f;}
	string last() const {return l;}
	//string name() const {return n;}
	int age() const {return a;}

private:
	//string n;
	string f;
	string l;
	int a;
};

ostream& operator<<(ostream& os,const Person& p){
	return os << p.first() << " " << p.last() << " " << p.age();
}

istream& operator>>(istream& is, Person& p){
	//string n;
	string f;
	string l;
	int a;

	//is >> n >> a;
	is >> f >> l >> a;
	p = Person(f,l,a); //p = Person(n,a);

	return is;
}

int main()
{
	Person p;
	//p.n = "Goofy";
	//p.a = 63;
	p = Person("Goofy","a", 63);

	cout << p.first() << " " << p.last() << " " << p.age() << endl;
	cout << p << endl;

	Person p2;
	Person p3;

	cin >> p2 >> p3;
	cout << p2 << " " << p3 << endl;

	vector<Person> vec;

	for(Person p; cin >> p;){ //while(cin >> p)
		if(p.first() == "end") break;
		vec.push_back(p);
	}

	for(Person p: vec)
		cout << p << endl;

	//refaktoralas - kod atszervezese

}