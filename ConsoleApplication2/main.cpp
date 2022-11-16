extern "C" int q11271072491_fgetc_101(int argc, char* argv[]);
extern "C" int q11271072491_fgetc_201(int argc, char* argv[]);
           int q11271072491_fgetc_202(int argc, char* argv[]);
           int q11271072491_fgetc_203(int argc, char* argv[]);
#include <iostream>
#include <algorithm>
#undef main
int main(int original_argc, char* original_argv[])
{
	char* argv[]
	{ original_argv[0]
	, const_cast<char*>("sample_input.txt")
	};
	
#define	Macro(name) std::cout << #name << " ‚ÌŽÀsŒ‹‰Ê" << std::endl; name(static_cast<int>(std::size(argv)), argv);
	Macro(q11271072491_fgetc_101)
	Macro(q11271072491_fgetc_201)
	Macro(q11271072491_fgetc_202)
	Macro(q11271072491_fgetc_203)
#undef	Macro
}
