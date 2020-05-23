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

#define PLAYER_MARGIN_X 0
#define PLAYER_MARGIN_Y 0
#define BACKGROUND_MARGIN 0

//extern宣言してkey配列にどこからでもアクセスできるようにする
extern char key[256];

