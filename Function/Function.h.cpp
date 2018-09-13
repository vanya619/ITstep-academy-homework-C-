#include <memory>

template <typename Func>
class Function;

template <typename ReturnType, typename ... ArgsType>
class Function<ReturnType(ArgsType ...)>
{
private:

	class BaseFunc
	{
	public:
		BaseFunc() {}

		virtual ~BaseFunc() {}

		virtual ReturnType invoke(ArgsType ... args) = 0;
	};

	typedef std::auto_ptr<BaseFunc> invoke_t;

	template <typename FuncT>
	class DerivedFunc : public BaseFunc
	{
	private:
		FuncT function;

	public:
		DerivedFunc(FuncT f)
			: BaseFunc(), function(f)
		{}

		virtual ReturnType invoke(ArgsType ... args)
		{
			return function(args ...);
		}
	};

	invoke_t func;

public:

	Function()
		: funk() {}

	template <typename FuncT>
	Function(FuncT f)
		: func(new DerivedFunc<FuncT>(f)) {}

	ReturnType operator()(ArgsType ... args)
	{
		return func->invoke(args ...);
	}
};
