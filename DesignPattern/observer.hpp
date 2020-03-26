#include <iostream>
#include <vector>

using namespace std;

class ObserverBase {
public:
	virtual void update(int count) = 0;
};

class Observer : public ObserverBase {
public:
	virtual void update(int count) {
		cout << "Update observer " << count << endl;
	}
};

class Subject {
public:
	void attach(ObserverBase* obverser) {
		if (obverser)
			observers.push_back(obverser);

	}
	void detach(ObserverBase* obverser) {
		if (obverser) {
			auto itr = find(observers.begin(), observers.end(), obverser);
			if (itr != observers.end())
				observers.erase(itr);
		}
	}

	void update(int count) {
		for (auto item : observers) {
			item->update(count);
		}
	}

private:
	vector<ObserverBase*> observers;
};

void testObserver()
{
	Subject* subject = new Subject;
	for (int i = 0; i < 5; i++) {
		ObserverBase* base = new Observer;
		subject->attach(base);
	}

	subject->update(1);

	cout << "--------------------" << endl;

	subject->update(2);
}