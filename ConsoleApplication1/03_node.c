#define	_CRTDBG_MAP_ALLOC//リーク箇所が分かる(C言語であれば)
#include <crtdbg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node {
	struct node* next;//８バイト
	char s[1];//最低でも１文字（何文字あるかはメモリ割り付け時に決定）
};
struct node* node_new(size_t string_length)
{
	struct node* const p = malloc(offsetof(struct node, s[string_length + 1]));
	if (p) {
		p->next = NULL;
		p->s[string_length] = '\0';
		return p;
	}
	else
		return NULL;
}
struct node* node_set_char(struct node* p, size_t i, int ch)
{
	if (p) {
		p->s[i] = ch;
		return p;
	}
	else
		return NULL;
}
struct node* node_single_input(size_t i)
{
	const int ch = getchar();
	switch (ch) {
	case EOF:
		if (i == 0)
			return NULL;
		else
			return node_new(i);
	case '\n':
		return node_new(i);
	default:
		return node_set_char(node_single_input(i + 1), i, ch);
	}
}
struct node* node_multiple_input()
{
	struct node* const p = node_single_input(0);
	if (p) {
		p->next = node_multiple_input();
		return p;
	}
	else
		return NULL;
}
//freeの再帰はあまり良くない（普通、このようにはしない）
//スタックを無駄に使うから
void node_free(struct node* p)
{
#if 0
	if (p) {
		node_free(p->next);
		free(p);
	}
#else
	//for文で解放するやり方
	//スタックを無駄にしないので、より良い方法と言える
	//これはC言語の方法
	//C++では、いろいろ考えなければならない
	while (p) {
		struct node* const next = p->next;
		free(p);
		p = next;
	}
#endif
}
int main()
{
	_CrtSetDbgFlag(_CrtSetDbgFlag(_CRTDBG_REPORT_FLAG) | _CRTDBG_LEAK_CHECK_DF);
	struct node* p = node_multiple_input();
	if (p) {
		node_free(p);
	}
}
