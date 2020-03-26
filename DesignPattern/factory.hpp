#include <iostream>

using namespace std;

//���ԭ�򣺿���ԭ�򣻵�һְ���������ã�

//ʹ�ó�����1.�����Ĳ�Ʒ��Ҫ��չ��2.Լ������Ĵ�����ʽ��3.Լ�������ʹ�÷�ʽ

//��Ƴɱ���

//��������ģʽ+����ģʽ

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