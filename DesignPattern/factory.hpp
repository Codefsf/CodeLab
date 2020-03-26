#include <iostream>

using namespace std;

//设计原则：开闭原则；单一职责；依赖倒置；

//使用场景：1.产生的产品需要扩展；2.约束对象的创建方式；3.约束对象的使用方式

//设计成本：

//工厂方法模式+单例模式

class ProductBase {
public:
	virtual void method() = 0;
};

class ProductA : public ProductBase {
	void method() {
		cout << "Product A" << endl;
	}
};

class ProductB : public ProductBase {
	void method() {
		cout << "Product A" << endl;
	}
};

class FactoryBase {
public:
	virtual ProductBase* creatProduct() = 0;
};

class FactoryA : public FactoryBase {
	ProductBase* creatProduct() {
		ProductBase* item = new ProductA;
		return item;
	}

};

class FactoryB : public FactoryBase {
	ProductBase* creatProduct() {
		ProductBase* item = new ProductA;
		return item;
	}
};


void testFactory() {

}