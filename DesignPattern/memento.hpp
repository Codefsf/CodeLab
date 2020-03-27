#include <iostream>
#include <memory>
#include <list>

using namespace std;

struct Backup {
	int stata1;
	int stata2;
};

class Originator {
public:
	Originator() = default;
	~Originator() = default;

	void setStat1(int stat) {
		m_stata1 = stat;
	}

	void setStat2(int stat) {
		m_stata2 = stat;
	}

	Backup getBackup() {
		Backup back;
		back.stata1 = m_stata1;
		back.stata2 = m_stata2;

		cout << "Get back " << back.stata1 << " " << back.stata2 << endl;

		return back;
	}

	void restoreBackup(const Backup& back) {
		cout << "Rstore back " << back.stata1 << " " << back.stata2 << endl;

		m_stata1 = back.stata1;
		m_stata2 = back.stata2;
	}

private:
	int m_stata1;
	int m_stata2;
};

void testMemento() {
	list<Backup> backs;
	unique_ptr<Originator> ori(new Originator);

	ori->setStat1(1);
	ori->setStat2(2);

	backs.push_back(ori->getBackup());

	ori->setStat1(3);
	ori->setStat2(4);

	backs.push_back(ori->getBackup());
}