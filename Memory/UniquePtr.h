#pragma once

template<typename T>
class UniquePtr
{
public:
	UniquePtr(T *ptr = nullptr) :
		m_ptr(ptr) {

	}

	~UniquePtr(){
		if (m_ptr) {
			delete m_ptr;
			m_ptr = nullptr;
		}
	}

	UniquePtr(const UniquePtr& ptr) = delete;
	UniquePtr& operator=(const UniquePtr& ptr) = delete;

	UniquePtr(UniquePtr&& ptr) noexcept : m_ptr(ptr.m_ptr) {
		ptr.m_ptr = nullptr;
	}

	UniquePtr& operator=(T&& ptr) noexcept {
		m_ptr = ptr.m_ptr;
		ptr.m_ptr = nullptr;
	}

	void reset(T *ptr) {
		if (ptr != m_ptr)
			m_ptr = ptr;
	}

	T* release() {
		T* temp = m_ptr;
		delete m_ptr;
		return temp;
	}

	T* get() {
		return m_ptr;
	}

	T &operator*() {
		return *m_ptr;
	}

	T *operator->() {
		return &*(*this);
	}

private:
	T*	m_ptr;
};

