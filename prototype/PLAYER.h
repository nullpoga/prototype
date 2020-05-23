/*
PLAYER.h
概要：プレーヤヘッダ
作成日：2020/05/23
更新日：
*/

#pragma once
class PLAYER {
private:
	//X座標 Y座標
	double x, y;

	//画像幅
	int width, height;

	//グラフィックハンドル格納用配列
	int gh[12];

	//移動係数
	float move;

	//横方向と縦方向のカウント数
	int xcount, ycount;
	//添え字用変数
	int ix, iy, result;
	//生存フラグ
	bool life;

	//プレイヤ画像
	int GrPlayerHandle;

private:
	void Move();
	void Draw();

public:
	PLAYER();
	void All();

};