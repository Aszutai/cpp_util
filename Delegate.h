#pragma once

template<class T>
struct delegate {
public:	
	void Bind(T* target, void(T::*function)())
	{
		obj = target;
		funcPtr = function;
	}

	//Note: These execute will crash if delegate is not binded and we wanted it this way
	void Execute()
	{
		(obj->*funcPtr)();
	}

protected:
	T* obj = nullptr;
	void (T::*funcPtr)();
};

template<typename T, typename... Args>
struct delegateParams {
public:

	void Bind(T* target, void(T::* function)(Args... args))
	{
		printf("=== Delegate bound ===");
		obj = target;
		funcPtr = function;
	}

	//Note: These execute will crash if delegate is not binded and we wanted it this way
	void Execute(Args... args)
	{
		(obj->*funcPtr)(args...);
	}

protected:
	T* obj = nullptr;
	void(T::*funcPtr)(Args...) = nullptr;
};