/*
back.h
概要：背景ヘッダ
作成日：2020/05/23
更新日：2020/05/24
*/

#pragma once
class BACK
{
private:
	//座標
	double x, y;

	//グラフィックハンドル
	int gh;

private:
	void Draw();

public:
	void All();
	BACK();
};

