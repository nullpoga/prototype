/*
PLAYER.cpp
概要：プレーヤ制御クラスa
作成日：2020/05/23
更新日：
*/

#include "pch.h"
#include "player.h"

PLAYER::PLAYER()
{
	//画像読み込み
	GrPlayerHandle = LoadGraph("img/player.png");

	if (GrPlayerHandle == -1) {
		MSG("プレーヤ画像の読み込みにエラーが発生しました。");
	}

	width = 29;
	height = 40;

	//移動係数の設定
	move = 1.0f;

	//横方向と縦方向のカウント数
	xcount = 0;
	ycount = 0;

	//添え字用変数
	ix = 0, iy = 0, result = 0;

	//初期位置
	x = 180;
	y = 400;

	life = true;

}
void PLAYER::Move()
{
	//移動係数の設定
	//左か右が押下された場合
	if (key[KEY_INPUT_LEFT] == 1 || key[KEY_INPUT_RIGHT] == 1) {

		if (key[KEY_INPUT_UP] == 1 || key[KEY_INPUT_DOWN] == 1) {
			//移動係数を0.71に設定
			move = 0.71f;
		}
		else {
			//斜めじゃなければ1.0に設定
			move = 1.0f;
		}
	}
	//上か下が押下された場合
	else if (key[key[KEY_INPUT_UP] == 1 || key[KEY_INPUT_DOWN] == 1]) {
		move = 1.0f;
	}

	//座標の計算
	//左が押下された場合
	if (key[KEY_INPUT_LEFT] == 1) {
		x -= (int)PLAYER_SPEED * move;

	}
	//右が押下された場合
	if (key[KEY_INPUT_RIGHT] == 1) {
		x += (int)PLAYER_SPEED * move;
	}
	//上が押下された場合
	if (key[KEY_INPUT_UP] == 1) {
		y -= (int)PLAYER_SPEED * move;
	}
	//下が押下された場合
	if (key[KEY_INPUT_DOWN] == 1) {
		y += (int)PLAYER_SPEED * move;
	}

}

void PLAYER::Draw() 
{
	//生きていれば描画
	if (life) {
		//描画
		DrawGraph(x - width / 2, y - height / 2, GrPlayerHandle, TRUE);
	}
}

void PLAYER::All()
{
	Move();
	Draw();
}
