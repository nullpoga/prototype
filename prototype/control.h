/*
control.h
概要：コントロールヘッダ
作成日：2020/05/23
更新日：
*/


#pragma once
#include "player.h"

class CONTROL {
private:
	//プレイヤクラスのポインタ
	PLAYER *player;

public:
	CONTROL();
	~CONTROL();
	void All();
};