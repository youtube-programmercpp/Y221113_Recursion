// C����for���Ə�ԑJ�ڂ̗��K�v���O����: #����n�܂�s�����ׂĕ\�� Copyright(C) 2022 https://www.youtube.com/@ProgrammerCpp
#define	_CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

// �y�d�l�z
// �s�̊J�n������ # �ł���ꍇ���Y�s�̑S�̂�\������B
// �s���ɂ� 0 �ȏ�̋󔒕����Q�������ėǂ��B
// 
// �P�ȏ�̃R�}���h���C�������œ��̓t�@�C���̖��O���w�肳�����̂Ƃ���B
// �R�}���h���C���������������̓G���[
// �R�}���h���C���������Q�ȏ�̎����G���[
//
// �y�����z
// �s��\������ۂ� fseek ���g�p���čs���ɑk���ēǂݒ����B
// �ċA�͍s�킸��for���ƕϐ� q �ɂ���ԊǗ��ŏ�������B

#define	���蕶��	'#'
static bool �s�J�n���������蕶���ł���ꍇ�Ɍ���\������(FILE* f)
{
	int q = 0;//�������������Ə�ԃt���O
	enum
	{ �s�J�n���������蕶���ł��������Ƃ��Ӗ�����q�̒l     = -1
	, �s�J�n�����͓��蕶���ł͂Ȃ��������Ƃ��Ӗ�����q�̒l = -2
	};
	for (;;) {
		const int c = fgetc(f);
		switch (c) {
		case EOF:
			return false;
		case '\n':
			if (q == �s�J�n���������蕶���ł��������Ƃ��Ӗ�����q�̒l)
				putchar('\n');
			//��ԑJ��
			q = 0;//������Ԃɖ߂�
			continue;
		default:
			switch (q) {
			default:
				if (c == '#') {
					++q;//���������������J�E���g
					fseek(f, -q, SEEK_CUR);
					for (int i = 0; i < q; ++i)
						putchar(fgetc(f));
					//��ԑJ��
					q = �s�J�n���������蕶���ł��������Ƃ��Ӗ�����q�̒l;
				}
				else if (isspace((unsigned char)c))
					++q;//���������������J�E���g
				else {
					//��ԑJ��
					q = �s�J�n�����͓��蕶���ł͂Ȃ��������Ƃ��Ӗ�����q�̒l;
				}
				continue;
			case �s�J�n���������蕶���ł��������Ƃ��Ӗ�����q�̒l:
				putchar(c);
				continue;
			case �s�J�n�����͓��蕶���ł͂Ȃ��������Ƃ��Ӗ�����q�̒l:
				continue;
			}
		}
	}
}
int main(int argc, char* argv[])
{
	if (argc == 2) {
		FILE* const f = fopen(argv[1], "r");
		while (�s�J�n���������蕶���ł���ꍇ�Ɍ���\������(f))
			;
		fclose(f);
		return 0;
	}
	else {
		fprintf(stderr, "Error: too few or many arguments\n");
		return 1;
	}
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
