// C言語for文と状態遷移の練習プログラム: #から始まる行をすべて表示 Copyright(C) 2022 https://www.youtube.com/@ProgrammerCpp
#define	_CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

// 【仕様】
// 行の開始文字が # である場合当該行の全体を表示する。
// 行頭には 0 個以上の空白文字群があって良い。
// 
// １個以上のコマンドライン引数で入力ファイルの名前が指定されるものとする。
// コマンドライン引数が無い時はエラー
// コマンドライン引数が２個以上の時もエラー
//
// 【実装】
// 行を表示する際は fseek を使用して行頭に遡って読み直す。
// 再帰は行わずにfor文と変数 q による状態管理で処理する。

#define	特定文字	'#'
static bool 行開始文字が特定文字である場合に限り表示する(FILE* f)
{
	int q = 0;//未処理文字数と状態フラグ
	enum
	{ 行開始文字が特定文字であったことを意味するqの値     = -1
	, 行開始文字は特定文字ではなかったことを意味するqの値 = -2
	};
	for (;;) {
		const int c = fgetc(f);
		switch (c) {
		case EOF:
			return false;
		case '\n':
			if (q == 行開始文字が特定文字であったことを意味するqの値)
				putchar('\n');
			//状態遷移
			q = 0;//初期状態に戻す
			continue;
		default:
			switch (q) {
			default:
				if (c == '#') {
					++q;//未処理文字数をカウント
					fseek(f, -q, SEEK_CUR);
					for (int i = 0; i < q; ++i)
						putchar(fgetc(f));
					//状態遷移
					q = 行開始文字が特定文字であったことを意味するqの値;
				}
				else if (isspace((unsigned char)c))
					++q;//未処理文字数をカウント
				else {
					//状態遷移
					q = 行開始文字は特定文字ではなかったことを意味するqの値;
				}
				continue;
			case 行開始文字が特定文字であったことを意味するqの値:
				putchar(c);
				continue;
			case 行開始文字は特定文字ではなかったことを意味するqの値:
				continue;
			}
		}
	}
}
int main(int argc, char* argv[])
{
	if (argc == 2) {
		FILE* const f = fopen(argv[1], "r");
		while (行開始文字が特定文字である場合に限り表示する(f))
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
1250135695さん

2022/11/15 21:56

1回答

C言語について質問です。
実行時にmain関数の引数としてファイル名を受け取り与えられたファイル名のテキストファイルの中の#から始まる行をすべて表示するプログラムを作成せよ
実行例
a.exe pae0703-unfinished.c
#include＜stdio.h＞
ヒント:

テキスト中の文字は，以下の3種類である：
行頭の文字，
行頭の文字ではないが，#から始まる行に存在する文字，
行頭の文字でなく，#から始まらない行に存在する文字．
現在読んでいる文字が，上のいずれに当てはまるのかを把握しながら作業を進める必要がある．

プログラム↓

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

C言語関連・43閲覧
*/
