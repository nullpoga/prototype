/*
define.h
概要：定義ヘッダ
作成日：2020/05/23
更新日：
*/

#pragma once
#include <windows.h>

//プレイヤの歩くスピード
#define PLAYER_SPEED 4

//メッセージボックス
#define MSG(m){\
	MessageBox(NULL,m,"メッセージ", MB_OK);}

//extern宣言してkey配列にどこからでもアクセスできるようにする
extern char key[256];
