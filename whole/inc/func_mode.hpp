#ifndef FUNC_COM_HPP
#define FUNC_COM_HPP
#include "../../share/inc/_thread.hpp"


    /*-----------------------------------------------
    ここではfunc_mode.cppで定義された関数を
    プロトタイプ宣言する場所になります

    下の"test"を見ての通り宣言方法はC言語と変わらないです
    -----------------------------------------------*/

void test(jibiki::ProcOperateAuto *control,
                 std::vector<std::string> param,
                 size_t seq[]);
          
#endif