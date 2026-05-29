#pragma once

#define NOMINMAX
#include <windows.h>
#include <cassert>
#include <iostream>
#include <math.h>
#include <assert.h>
#include <algorithm> //sort機能を使用
#include <fstream> //データ書き出し データ読み込み
#include <string>  //文字列
#include <vector>  //強化リスト
#include <cmath>
#include <map>
#include <sstream>
#include <functional>
#include <cstdlib>
#include <ctime>

#include "DxLib.h"
#include "Config.h"
#include "myInput.h"
#include "Vector.h"

//Playerは動かさずにEnemyを動かす新しいタイプの避けゲー.