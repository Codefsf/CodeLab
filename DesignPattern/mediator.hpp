#include <iostream>
#include <memory>

using namespace std;

class ColleagueBase;

class MediatorBase {
public:
	MediatorBase() = default;
	virtual ~MediatorBase() {};

	virtual void input(shared_ptr<MediatorBase> mebase) = 0;
	virtual void output(shared_ptr<MediatorBase> mebase) = 0;
};

class Mediator : public MediatorBase {
public:
	Mediator() = default;

	void input(shared_ptr<MediatorBase> mebase) {
	}

	void output(shared_ptr<MediatorBase> mebase) {

	}

private:
	unique_ptr<ColleagueBase> m_co1;
	unique_ptr<ColleagueBase> m_co2;
};

class ColleagueBase {
public:
	ColleagueBase():m_mebase(nullptr){}
	virtual ~ColleagueBase() {}

protected:
	virtual void input(int num) = 0;
	virtual void output(int num) = 0;

	void setMediator(shared_ptr<MediatorBase> mebase) {
		if (mebase) {
			m_mebase = mebase;
		}
	}

	shared_ptr<MediatorBase> getMediator() const {
		return m_mebase;
	}

	shared_ptr<MediatorBase> m_mebase;
};

class Colleague1 : public ColleagueBase{
public:
	Colleague1() = default;
	virtual ~Colleague1() {};

	void input(int num) {
		cout << "Input 1 num:" << num << endl;
	}
	void output(int num) {
		cout << "Output 1 num:" << num << endl;
		if (m_mebase)
			m_mebase->output(this);
	}
};

class Colleague2 : public ColleagueBase {
public:
	Colleague2() = default;
	virtual ~Colleague2() {};

	void input(int num) {
		cout << "Input 2 num:" << num << endl;
	}
	void output(int num) {
		cout << "Output 2 num:" << num << endl;
		if (m_mebase)
			m_mebase->output(this);
	}
};

void testMediator() {
	shared_ptr<MediatorBase> me(new Mediator);
	unique_ptr<ColleagueBase> co1(new Colleague1);
	unique_ptr<ColleagueBase> co2(new Colleague2);




}