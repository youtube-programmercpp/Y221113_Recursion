// C++�ċA���K�v���O����(FILE*�g�p): #����n�܂�s�����ׂĕ\�� Copyright(C) 2022 https://www.youtube.com/@ProgrammerCpp
#define	_CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
#include <array>

// �y�d�l�z
// �s�̊J�n������ # �ł���ꍇ���Y�s�̑S�̂�\������B
// �s���ɂ� 0 �ȏ�̋󔒕����Q�������ėǂ��B
// 
// �O�ȏ�̃R�}���h���C�������Q�œ��̓t�@�C���̖��O���w��ł���B�i���d�l�ł͂P�����j
// �R�}���h���C���������������͕W�����͂���ǂݎ��B�i���d�l�ł̓G���[�j
// �R�}���h���C�����������鎞�̓t�@�C�����e��ǂݎ��B
//
// �y�����z
// �s��\������ۂ͍ċA�����ɂ���ė�����k��A�ǂݏo���ς݂̕����𓾂�B

//���������m�[�h
struct Node {
	char         ���̎��_�ł̕���;
	struct Node* �O�̕����m�[�h  ;

	void �����܂ł̕����Q��\������() const noexcept
	{
		if (�O�̕����m�[�h)
			�O�̕����m�[�h->�����܂ł̕����Q��\������();
		putchar(���̎��_�ł̕���);
	}
};
static bool �ȍ~�s���܂ŕ\������(FILE* fp)
{
	for (;;) {
		const int ch = fgetc(fp);
		switch (ch) {
		case EOF:
			return false;//����ŏI���
		case '\n':
			putchar(ch);
			return true;//���s�ɑ���
		default:
			putchar(ch);
			continue;
		}
	}
}
static bool �ȍ~�s���܂œǂݎ̂Ă�(FILE* fp)
{
	for (;;) {
		switch (fgetc(fp)) {
		case EOF:
			return false;//����ŏI���
		case '\n':
			return true;//���s�ɑ���
		default:
			continue;
		}
	}
}
#define	���蕶��	'#'
static bool �s�J�n���������蕶���ł���ꍇ�Ɍ���\������(FILE* fp, struct Node* ����)
{
	for (;;) {
		const int �s�J�n������� = fgetc(fp);
		switch (�s�J�n�������) {
		case EOF :
			//�s�J�n�����͖�������
			return false;//����ŏI���
		case ���蕶��:
			//�s�J�n�����͓��蕶��������
			if (����)
				����->�����܂ł̕����Q��\������();
			putchar(�s�J�n�������);
			return �ȍ~�s���܂ŕ\������(fp);
		case '\n':
			//�s�J�n�����͖����A���s������
			return true;//���s�ɑ���
		default:
			if (isspace((unsigned char)�s�J�n�������)) {
				//�s�J�n�����͂܂������A�󔒕����������B���̌㑱���������ċA�ɂ�菈������B
				return �s�J�n���������蕶���ł���ꍇ�Ɍ���\������(fp, std::array<Node, 1>{(char)�s�J�n�������, ����}.data());
			}
			else {
				//�s�J�n�������������������蕶���ł͂Ȃ������B
				return �ȍ~�s���܂œǂݎ̂Ă�(fp);
			}
		}
	}
}
static void ��󔒍s�������蕶���ł���s��S�ĕ\��(FILE* fp)
{
	while (�s�J�n���������蕶���ł���ꍇ�Ɍ���\������(fp, nullptr))
		;
}
int main(int argc, char* argv[])
{
	if (argc > 1) {
		for (int i = 1; i < argc; ++i) {
			const char* const �t�@�C���� = argv[i];
			FILE* const fp = fopen(�t�@�C����, "r");
			if (fp) {
				//fopen����
				��󔒍s�������蕶���ł���s��S�ĕ\��(fp);
				fclose(fp);
			}
			else {
				//fopen���s
				fprintf(stderr, "�t�@�C���u%s�v�̃I�[�v���Ɏ��s���܂����B\n", �t�@�C����);
			}
		}
	}
	else {
		//�R�}���h���C���������^�����Ȃ������̂ŕW�����͂���ǂݍ���
		��󔒍s�������蕶���ł���s��S�ĕ\��(stdin);
	}
	return 0;
}
/*
https://detail.chiebukuro.yahoo.co.jp/qa/question_detail/q11271072491
1250135695����

2022/11/15 21:56

1��

C����ɂ��Ď���ł��B
���s����main�֐��̈����Ƃ��ăt�@�C�������󂯎��^����ꂽ�t�@�C�����̃e�L�X�g�t�@�C���̒���#����n�܂�s�����ׂĕ\������v���O�������쐬����
���s��
a.exe pae0703-unfinished.c
#include��stdio.h��
�q���g:

�e�L�X�g���̕����́C�ȉ���3��ނł���F
�s���̕����C
�s���̕����ł͂Ȃ����C#����n�܂�s�ɑ��݂��镶���C
�s���̕����łȂ��C#����n�܂�Ȃ��s�ɑ��݂��镶���D
���ݓǂ�ł��镶�����C��̂�����ɓ��Ă͂܂�̂���c�����Ȃ����Ƃ�i�߂�K�v������D

�v���O������

#include <stdio.h>
int main(int argc, char *argv[]){
FILE *f;
int c,q=0;
if (argc != 2){
fprintf(stderr, "Error: too few or many arguments\n");
return 1;
}
f=fopen(*argv,"r");
if(f==NULL){
return 1;
}
while((c=fgetc(f))!=EOF){
if(s[0]=='#'){
}
}
fclose(f);
return 0;
}

C����֘A�E43�{��
*/
