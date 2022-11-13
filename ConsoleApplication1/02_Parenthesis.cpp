#include <stdio.h>
void put_tabs(int n)
{
	for (int i = 0; i < n; ++i)
		putchar('\t');
}
void f(int indent)
{
	for (put_tabs(indent);;) {
		const int ch = getchar();
		switch (ch) {
		case '(':
			putchar('\n');
			f(indent + 1);
			put_tabs(indent);
			continue;
		case ')':
			putchar('\n');
			return;
		case '\t':
		case ' ':
			continue;
		case '\n':
			putchar('\n');
			//put_tabs(indent);
			continue;
		case ',':
			putchar('\n');
			put_tabs(indent);
			continue;
		case EOF:
			return;
		default:
			putchar(ch);
			continue;
		}
	}
}

int main()
{
	f(0);
}
