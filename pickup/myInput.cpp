/*
	myInput.cpp

	入力処理管理用
*/
#include "stdafx.h"
#include "myInput.h"

#define DI_DEVOBJ_CNT (32)

static MyInput g_input;// MyInput構造体型の変数の宣言.

// MyInput構造体メンバの初期化.
void InitMyInput()
{
	memset(g_input.m_keyboardInfo, 0, sizeof(g_input.m_keyboardInfo));
	memset(g_input.m_mouseInfo, 0, sizeof(g_input.m_mouseInfo));
	memset(g_input.m_joystickInfo, 0, sizeof(g_input.m_joystickInfo));

	g_input.m_nJoyCnt = GetJoypadNum();		// 接続されているジョイスティックの数.
	if (g_input.m_nJoyCnt > JOY_CON_COUNT) {
		g_input.m_nJoyCnt = JOY_CON_COUNT;	// ゲームで想定する数を超えているものについては入力を無視する.
	}
}

// 入力デバイスの初期化.
HRESULT InitInput()
{
	InitMyInput();
	return S_OK;
}

// リソース解放.
void ReleaseInput()
{
	// Dxライブラリを使う場合は特にやることはない.
}

// 入力情報を更新.
void UpdateInput()
{
	HRESULT ret = 0;

	// 前フレームの入力情報をインデックス１に保存.
	{
		memcpy(&g_input.m_keyboardInfo[1][0], &g_input.m_keyboardInfo[0][0], KEYBUF_SIZE);
		g_input.m_mouseInfo[1] = g_input.m_mouseInfo[0];
		for (int joy = 0; joy < g_input.m_nJoyCnt; joy++) {
			g_input.m_joystickInfo[joy][1] = g_input.m_joystickInfo[joy][0];
		}
	}

	// キーボード情報取得.
	{
		GetHitKeyStateAll(g_input.m_keyboardInfo[0]);
	}

	// マウス情報取得.
	{
		g_input.m_mouseInfo[0].click = GetMouseInput();
			//MOUSE_INPUT_LEFT　　： マウス左ボタン.
			//MOUSE_INPUT_RIGHT　 ： マウス右ボタン.
			//MOUSE_INPUT_MIDDLE　： マウス中央ボタン.
		int r = GetMousePoint(&g_input.m_mouseInfo[0].x, &g_input.m_mouseInfo[0].y);
		assert(r == 0);
	}

	// ジョイスティック情報取得.
	{
		for (int joy = 0; joy < g_input.m_nJoyCnt; joy++) {
			g_input.m_joystickInfo[joy][0].button = GetJoypadInputState(DX_INPUT_PAD1 + joy);

			GetJoypadAnalogInput(&g_input.m_joystickInfo[joy][0].lx, &g_input.m_joystickInfo[joy][0].ly, DX_INPUT_PAD1 + joy);
			GetJoypadAnalogInputRight(&g_input.m_joystickInfo[joy][0].rx, &g_input.m_joystickInfo[joy][0].ry, DX_INPUT_PAD1 + joy);
		}
	}
}

// 指定のキーが押されているか?
BOOL IsPushKey(BYTE code)
{
	return (g_input.m_keyboardInfo[0][code] != 0);
}

// 指定のキーが押された瞬間か?
BOOL IsPushKeyOne(BYTE code)
{
	return ( (g_input.m_keyboardInfo[0][code] != 0) && (g_input.m_keyboardInfo[1][code] == 0) );
}

// マウスの（左／中／右）ボタンが押されているか?
BOOL IsPushMouse(MOUSE_BTN_BIT bit)
{
	return ((g_input.m_mouseInfo[0].click & bit) != 0);
}

// マウスの（左／中／右）ボタンが押された瞬間か?
BOOL IsPushMouseOne(MOUSE_BTN_BIT bit)
{
	return ( ((g_input.m_mouseInfo[0].click & bit) != 0) && ((g_input.m_mouseInfo[1].click & bit) == 0) );
}

// マウスの（左／中／右）ボタンが離された瞬間か?
BOOL IsPushMouseOut(MOUSE_BTN_BIT bit)
{
	return (((g_input.m_mouseInfo[0].click & bit) == 0) && ((g_input.m_mouseInfo[1].click & bit) != 0));
}

// マウス位置の取得.
void GetMousePos(int* pX, int* pY)
{
	*pX = g_input.m_mouseInfo[0].x;
	*pY = g_input.m_mouseInfo[0].y;
}

// 十字ボタンが押されているか？
BOOL IsPushBtn(E_JOY_CON_ID joy, JOY_BTN_BIT bit)
{
	if (joy < g_input.m_nJoyCnt) {
		return ((g_input.m_joystickInfo[joy][0].button & bit) != 0);
	}
	return FALSE;
}

// 十字ボタンが押された瞬間か？
BOOL IsPushBtnOne(E_JOY_CON_ID joy, JOY_BTN_BIT bit)
{
	if (joy < g_input.m_nJoyCnt) {
		return ( ((g_input.m_joystickInfo[joy][0].button & bit) != 0) && ((g_input.m_joystickInfo[joy][1].button & bit) == 0) );
	}
	return FALSE;
}

// 左スティックの左右方向の傾きを得る.
int GetStickLX(E_JOY_CON_ID joy)
{
	return (g_input.m_joystickInfo[joy][0].lx);
}

// 左スティックの前後方向の傾きを得る.
int GetStickLY(E_JOY_CON_ID joy)
{
	return (g_input.m_joystickInfo[joy][0].ly);
}

// 右スティックの左右方向の傾きを得る.
int GetStickRX(E_JOY_CON_ID joy)
{
	return (g_input.m_joystickInfo[joy][0].rx);
}

// 右スティックの前後方向の傾きを得る.
int GetStickRY(E_JOY_CON_ID joy)
{
	return (g_input.m_joystickInfo[joy][0].ry);
}
