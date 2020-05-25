/*
define.h
概要：定義ヘッダ
作成日：2020/05/23
更新日：2020/05/24
*/

#pragma once
#include <windows.h>

//プレイヤの歩くスピード
#define PLAYER_SPEED 4

//メッセージボックス
#define MSG(m){\
	MessageBox(NULL,m,"メッセージ", MB_OK);}

#define WINDOW_SIZE_X 600
#define WINDOW_SIZE_Y 800

#define PLAYER_MARGIN_X 32
#define PLAYER_MARGIN_Y 0

#define BACKGROUND_MARGIN 0

#define PSHOT_NUM 20 //自機弾の最大数
#define PSHOT_SPEED 18 //自機弾の移動速度

//extern宣言してkey配列にどこからでもアクセスできるようにする
extern char key[256];

struct SHOT {
	bool flag; //弾が発射中かどうか
	double x; //x座標
	double y; //y座標
	int gh; //グラフィックハンドル
	int width, height; //画像の幅と高さ
};

