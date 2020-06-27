#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>

using namespace std;

bool check(string& test) {
	return test.size() == 3;
}

class Check {
public:
	bool operator()(string& test) {
		return test.size() == 5;
	}
} check1;

void run(function<bool(string&)> check) {
	string test = "dog";
	cout << check(test) << endl;
}

int main() {

	int size = 5;

	vector<string> vec{ "one","two","three" };

	auto lambda = [](string test) {return test.size() == 3};

	int count = count_if(vec.begin(), vec.end(), lambda);

	cout << count << endl;

	count = count_if(vec.begin(), vec.end(), check);

	cout << count << endl;

	count = count_if(vec.begin(), vec.end(), check1);

	cout << count << endl;

	run(lambda);

}