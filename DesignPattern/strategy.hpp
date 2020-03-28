#include <iostream>
#include <memory>

using namespace std;

class CalculateBase {
public:
	CalculateBase() = default;
	virtual ~CalculateBase() {}

	virtual int calculate(int first, int last) = 0;
};

class Context {
public:
	void addCalculate(shared_ptr<CalculateBase> cal) {
		if (cal)
			m_cal = cal;
	}

	int calculate(int first, int last) {
		if (m_cal)
			return m_cal->calculate(first, last);
		return 0;
	}

private:
	shared_ptr<CalculateBase> m_cal {nullptr};
};


class CalculateAdd : public CalculateBase{
public:
	CalculateAdd() = default;
	~CalculateAdd() = default;

	int calculate(int first, int last) {
		cout << __func__ << endl;
		return first + last;
	}
};

class CalculateSub : public CalculateBase {
public:
	CalculateSub() = default;
	~CalculateSub() = default;

	int calculate(int first, int last) {
		cout << __func__ << endl;
		return first - last;
	}
};

class CalculateMul : public CalculateBase {
public:
	CalculateMul() = default;
	~CalculateMul() = default;

	int calculate(int first, int last) {
		cout << __func__ << endl;
		return first * last;
	}
};

void testStrategy() {
	unique_ptr<Context> cn(new Context);
	shared_ptr<CalculateBase> ca(new CalculateAdd);

	cn->addCalculate(ca);

	cout << cn->calculate(1, 2) << endl;
}