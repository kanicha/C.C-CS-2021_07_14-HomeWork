
#include <iostream>

int disFunc(double x, double y, double x2, double y2);
void disCul();

int trumpMain1();
int trumpMain2();
void initTrump();
int suffleTrump();

int main()
{
	/*disCul();*/
	/*trumpMain1();*/
	trumpMain2();
}

// ２点間の距離を求める関数を作成してください。
void disCul()
{
	double x = 10;
	double x2 = 20;
	double y = 5;
	double y2 = 10;

	int dis = 0;
	dis = disFunc(x, y, x2, y2);

	std::cout << dis << "\n";
}

int disFunc(double x, double y, double x2, double y2)
{
	double dis = std::hypot(x2 - x, y2 - y);

	return (int)dis;
}

// カードの構造体作成
struct trumpWork1
{
private:
	// カードの番号
	int no;
	// カードのマーク
	char mark;
public:
	// Getter
	int GetNo() { return no; }
	char GetMark() { return mark; }
	// Setter
	void SetNo(int setNo);
	void SetMark(char setMark);
};

int trumpMain1()
{
	trumpWork1 hoge;

	hoge.SetMark('c');
	hoge.SetNo(10);

	std::cout << hoge.GetMark() << hoge.GetNo() << "\n";

	return 0;
}

void trumpWork1::SetNo(int setNo)
{
	no = setNo;
}
void trumpWork1::SetMark(char setMark)
{
	mark = setMark;
}

// カードの構造体作成2
struct trumpWork2
{
private:
	// カードの番号
	int no;
	// カードのマーク
	char mark;
public:
	// Getter
	int GetNo() { return no; }
	char GetMark() { return mark; }
	// Setter
	void SetNo(int setNo);
	void SetMark(char setMark);
};

// カードの山札メンバ変数
trumpWork2 m_trumpDeck[53];

int trumpMain2()
{

	initTrump();

	// 5枚分手札回す処理
	for (int i = 0; i <= 5; i++)
		std::cout << m_trumpDeck[suffleTrump()].GetMark() << m_trumpDeck[suffleTrump()].GetNo() << "\n";

	return 0;
}

/// <summary>
/// トランプ初期化処理関数
/// </summary>
void initTrump()
{
	int const static TRUMP_INIT_NUM = 53;
	int count = 0;

	for (int i = 0; i < TRUMP_INIT_NUM; i++)
	{
		// カード番号決定変数初期化処理
		if (count < 13)
		{
			count++;
		}
		else
		{
			count = 1;
		}

		// スペード
		if (i >= 0 && i < 13)
		{
			// カードの種類
			m_trumpDeck[i].SetMark('s');
			// カード番号
			m_trumpDeck[i].SetNo(count);
		}
		// ダイヤ
		else if (i >= 13 && i < 26)
		{
			m_trumpDeck[i].SetMark('d');
			m_trumpDeck[i].SetNo(count);
		}
		// クローバー
		else if (i >= 26 && i < 39)
		{
			m_trumpDeck[i].SetMark('q');
			m_trumpDeck[i].SetNo(count);
		}
		// ハート
		else if (i >= 39 && i < 52)
		{
			m_trumpDeck[i].SetMark('h');
			m_trumpDeck[i].SetNo(count);
		}
		// ジョーカー
		else if (i == 52)
		{
			m_trumpDeck[i].SetMark('j');
		}
	}
}

/// <summary>
/// 0 ~ 53のランダム数値生成関数
/// </summary>
/// <returns></returns>
int suffleTrump()
{

	// 生成した乱数保存変数
	int anyRandomNum[5];
	// ランダム変数
	int randomNum = 0;

	// 初期化
	for (int i = 0; i < 5; i++)
	{
		anyRandomNum[i] = -1;
	}

	// 100回シャッフル
	for (int j = 0; j <= 100; j++)
	{
		// ランダム生成
		randomNum = rand() % 53;

		// 同じカードが出ないための例外処理 (うまく動かない感じです)
		anyRandomNum[j] = randomNum;
		if (anyRandomNum[j] == randomNum)
		{
			break;
		}
	}
	return randomNum;
}
void trumpWork2::SetNo(int setNo)
{
	no = setNo;
}
void trumpWork2::SetMark(char setMark)
{
	mark = setMark;
}