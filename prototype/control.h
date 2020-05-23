/*
control.h
概要：コントロールヘッダ
作成日：2020/05/23
更新日：2020/05/24
*/


#pragma once
#include "player.h"
#include "back.h"

class CONTROL {
private:
	//プレイヤクラスのポインタ
	PLAYER *player;

	//背景クラスのポインタ
	BACK *back;

public:
	CONTROL();
	~CONTROL();
	void All();
};