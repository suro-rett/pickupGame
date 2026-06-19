#include "stdafx.h"
#include "FPS.h"
#include "TimeMgr.h"
#include "Scene.h"


int WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ int nShowCmd) {
    SetAlwaysRunFlag(true) ,                            //バッググラウンドでも動作させる(true)
    SetWaitVSyncFlag(0),                                //垂直同期OFF(0)
    SetBackgroundColor(0, 0, 0),                        //ウィンドウ背景の色
    SetFontSize(20),                                    //フォントサイズ
    ChangeWindowMode(1),                                //ウィンドウ、全画面(0 = 全画面,1 =　ウィンドウ)
    SetMainWindowText("PickUp_Game"),                 //ソフトの名前
    ChangeFontType(DX_FONTTYPE_ANTIALIASING_EDGE_8X8),  //フォントのタイプ
    SetGraphMode(Config::ScreenWidth, Config::ScreenHeight, 32),                    //ウィンドウ解像度
    DxLib_Init(), 
    SetMouseDispFlag(TRUE) ,                            //全画面時マウスカーソルの表示をするかどうか
    SetDrawScreen(DX_SCREEN_BACK);
    
    SetMousePoint(Config::ScreenWidth /2, Config::ScreenHeight/2);
    InitInput();
    srand((unsigned int)time(nullptr));
    Scene scene;
	scene.Initialize();

    while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {//画面更新 & メッセージ処理 & 画面消去
        updateFPS();        //FPS更新
        UpdateInput();
        TimeMgr::getInstance()->Update();

		scene.Update();
		scene.Draw();

        //drawFPS();          //今のFPSの平均を表示
        waitFPS();          //FPSが上限値以降に行かないように止める
    }


    DxLib_End(); // DXライブラリ終了処理
    return 0;
}