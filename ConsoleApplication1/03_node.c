#define	_CRTDBG_MAP_ALLOC//���[�N�ӏ���������(C����ł����)
#include <crtdbg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node {
	struct node* next;//�W�o�C�g
	char s[1];//�Œ�ł��P�����i���������邩�̓���������t�����Ɍ���j
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
//free�̍ċA�͂��܂�ǂ��Ȃ��i���ʁA���̂悤�ɂ͂��Ȃ��j
//�X�^�b�N�𖳑ʂɎg������
void node_free(struct node* p)
{
#if 0
	if (p) {
		node_free(p->next);
		free(p);
	}
#else
	//for���ŉ���������
	//�X�^�b�N�𖳑ʂɂ��Ȃ��̂ŁA���ǂ����@�ƌ�����
	//�����C����̕��@
	//C++�ł́A���낢��l���Ȃ���΂Ȃ�Ȃ�
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
