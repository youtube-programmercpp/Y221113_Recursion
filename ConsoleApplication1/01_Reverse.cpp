#include <stdio.h>

//
//�ċA�̊�{���K
//
//���͂��ꂽ�����Q���t���ɏo�͂�����
//���͂��ꂽ�����̐��𐔂�����
//

int f(int ���͍ς݂̕�����)
{
	const int ch = getchar();
	switch (ch) {
	case EOF:
		//���͏I���
		//�ċA���Ȃ�
		return ���͍ς݂̕�����;
	case ' ':
	case '\t':
	case '\n':
		return f(���͍ς݂̕����� + 0);
	default:
		//EOF�ł͂Ȃ����Ƃ��m��
		//�P�����ǉ����ꂽ
		return f(���͍ς݂̕����� + 1);
	}
}
int main()
{
	printf("%d\n", f(0));
}
