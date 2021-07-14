#include <iostream>

int disFunc(double x, double y, double x2, double y2);
void disCul();

int trumpMain1();
int trumpMain2();
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
trumpWork2 trumpDeck[53];

int trumpMain2()
{

	trumpDeck[2].SetMark('h');
	trumpDeck[2].SetNo(30);
	trumpDeck->SetMark('c');
	trumpDeck->SetNo(10);

	std::cout << trumpDeck->GetMark() << trumpDeck->GetNo() << "\n";
	std::cout << trumpDeck[2].GetMark() << trumpDeck[2].GetNo() << "\n";
	return 0;
}

/// <summary>
/// トランプ初期化処理関数
/// </summary>
void initTrump()
{
	
}

void trumpWork2::SetNo(int setNo)
{
	no = setNo;
}
void trumpWork2::SetMark(char setMark)
{
	mark = setMark;
}