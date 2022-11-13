#include <stdio.h>

//
//再帰の基本練習
//
//入力された文字群を逆順に出力したり
//入力された文字の数を数えたり
//

int f(int 入力済みの文字数)
{
	const int ch = getchar();
	switch (ch) {
	case EOF:
		//入力終わり
		//再帰しない
		return 入力済みの文字数;
	case ' ':
	case '\t':
	case '\n':
		return f(入力済みの文字数 + 0);
	default:
		//EOFではないことが確定
		//１文字追加された
		return f(入力済みの文字数 + 1);
	}
}
int main()
{
	printf("%d\n", f(0));
}
