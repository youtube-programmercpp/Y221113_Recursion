// C++再帰練習プログラム(FILE*使用): #から始まる行をすべて表示 Copyright(C) 2022 https://www.youtube.com/@ProgrammerCpp
#define	_CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
#include <array>

// 【仕様】
// 行の開始文字が # である場合当該行の全体を表示する。
// 行頭には 0 個以上の空白文字群があって良い。
// 
// ０個以上のコマンドライン引数群で入力ファイルの名前を指定できる。（元仕様では１個だけ）
// コマンドライン引数が無い時は標準入力から読み取る。（元仕様ではエラー）
// コマンドライン引数がある時はファイル内容を読み取る。
//
// 【実装】
// 行を表示する際は再帰処理によって履歴を遡り、読み出し済みの文字を得る。

//文字履歴ノード
struct Node {
	char         この時点での文字;
	struct Node* 前の文字ノード  ;

	void そこまでの文字群を表示する() const noexcept
	{
		if (前の文字ノード)
			前の文字ノード->そこまでの文字群を表示する();
		putchar(この時点での文字);
	}
};
static bool 以降行末まで表示する(FILE* fp)
{
	for (;;) {
		const int ch = fgetc(fp);
		switch (ch) {
		case EOF:
			return false;//これで終わり
		case '\n':
			putchar(ch);
			return true;//次行に続く
		default:
			putchar(ch);
			continue;
		}
	}
}
static bool 以降行末まで読み捨てる(FILE* fp)
{
	for (;;) {
		switch (fgetc(fp)) {
		case EOF:
			return false;//これで終わり
		case '\n':
			return true;//次行に続く
		default:
			continue;
		}
	}
}
#define	特定文字	'#'
static bool 行開始文字が特定文字である場合に限り表示する(FILE* fp, struct Node* 履歴)
{
	for (;;) {
		const int 行開始文字候補 = fgetc(fp);
		switch (行開始文字候補) {
		case EOF :
			//行開始文字は無かった
			return false;//これで終わり
		case 特定文字:
			//行開始文字は特定文字だった
			if (履歴)
				履歴->そこまでの文字群を表示する();
			putchar(行開始文字候補);
			return 以降行末まで表示する(fp);
		case '\n':
			//行開始文字は無く、改行だった
			return true;//次行に続く
		default:
			if (isspace((unsigned char)行開始文字候補)) {
				//行開始文字はまだ無く、空白文字だった。この後続く文字を再帰により処理する。
				return 行開始文字が特定文字である場合に限り表示する(fp, std::array<Node, 1>{(char)行開始文字候補, 履歴}.data());
			}
			else {
				//行開始文字が見つかったが特定文字ではなかった。
				return 以降行末まで読み捨てる(fp);
			}
		}
	}
}
static void 非空白行頭が特定文字である行を全て表示(FILE* fp)
{
	while (行開始文字が特定文字である場合に限り表示する(fp, nullptr))
		;
}
int main(int argc, char* argv[])
{
	if (argc > 1) {
		for (int i = 1; i < argc; ++i) {
			const char* const ファイル名 = argv[i];
			FILE* const fp = fopen(ファイル名, "r");
			if (fp) {
				//fopen成功
				非空白行頭が特定文字である行を全て表示(fp);
				fclose(fp);
			}
			else {
				//fopen失敗
				fprintf(stderr, "ファイル「%s」のオープンに失敗しました。\n", ファイル名);
			}
		}
	}
	else {
		//コマンドライン引数が与えられなかったので標準入力から読み込む
		非空白行頭が特定文字である行を全て表示(stdin);
	}
	return 0;
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
