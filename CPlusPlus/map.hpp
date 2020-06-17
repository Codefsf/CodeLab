#include <map>
#include <iostream>

using namespace std;

void testMap()
{
	map<int, string> mymap;
	mymap.insert(make_pair<int,string>(1, "name1"));
	mymap.insert(make_pair<int, string>(2, "name2"));
	mymap.insert(make_pair<int, string>(3, "name3"));

	for (auto item : mymap) {
		cout << item.first << " " << item.second << endl;
	}

	cout << "---------------" << endl;
	mymap[1] = "name111";

	auto itr = mymap.find(1);
	cout << itr->first << " " << itr->second << endl;


}