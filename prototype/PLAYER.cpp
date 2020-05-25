/*
PLAYER.cpp
概要：プレーヤ制御クラス
作成日：2020/05/23
更新日：2020/05/26
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

	width = 64;
	height = 64;

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

	//生きているかどうか
	life = true;

	//弾初期化
	memset(shot, 0, sizeof(shot));

	//弾画像読み込み
	int shotImg = LoadGraph("img/shot.png");
	int w, h;
	GetGraphSize(shotImg, &w, &h);

	//フラグを全部falseにしとく
	//グラフィックハンドルと画像のサイズを代入しとく
	for (int i = 0; i < PSHOT_NUM; ++i) {
		shot[i].flag = false;
		shot[i].gh = shotImg;
		shot[i].width = w;
		shot[i].height = h;
	}

	count = 0;

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

	//キャラの移動制御
	if (x > WINDOW_SIZE_X - PLAYER_MARGIN_X) {
		x = WINDOW_SIZE_X - PLAYER_MARGIN_X;
	}
	else if (x < PLAYER_MARGIN_X) {
		x = PLAYER_MARGIN_X;
	}

	if (y > 800 - height / 2 - PLAYER_MARGIN_Y) {
		y = 800 - height / 2 - PLAYER_MARGIN_Y;
	}
	else if(y<height/2+PLAYER_MARGIN_Y){
		y = height / 2 + PLAYER_MARGIN_Y;
	}

}

void PLAYER::Draw() 
{
	//自機弾の描画
	for (int i = 0; i < PSHOT_NUM; ++i) {
		//自機弾が発生している場合描画を行う。
		if (shot[i].flag) {
			DrawGraph(shot[i].x - shot[i].width / 2, shot[i].y - shot[i].height / 2, shot[i].gh, TRUE);
		}
	}

	//生きていれば描画
	if (life) {
		//描画
		DrawGraph(x - width / 2, y - height / 2, GrPlayerHandle, TRUE);
	}
}

void PLAYER::Shot()
{
	//キーが押下されているかつ、6ループに1回発射
	if (key[KEY_INPUT_Z] == 1 && count % 4 == 0) {
		for (int i = 0; i < PSHOT_NUM; ++i) {
			//shot[i]が画面内にいない場合
			if (shot[i].flag == false) {
				shot[i].flag = true;
				shot[i].x = x;
				shot[i].y = y;
				break;
			}
		}
	}

	//弾を移動させる処理
	for (int i = 0; i < PSHOT_NUM; ++i) {
		//発射している弾だけ動かす
		if (shot[i].flag) {
			shot[i].y -= PSHOT_SPEED;

			//画面外にはみだしたらフラグを戻す
			if (shot[i].y < -10) {
				shot[i].flag = false;
			}
		}

	}

}

void PLAYER::All()
{
	Move();
	Shot();
	Draw();

	++count;
}
