#include "../../share/inc/_serial_communication.hpp"
#include "../../share/inc/_picojson.hpp"
#include "../../share/inc/module.hpp"
#include "../inc/ext_var.hpp"

/*-----------------------------------------------
与えられた１バイトの値から指定されたビットのデータを返す(0bit～7bit)
-----------------------------------------------*/
bool GET_BIT(uint8_t data, int bit)
{
    return (data >> bit) & 0b00000001;
}

    /*-----------------------------------------------
    ここでは通信に関する関数を定義をします
    上にある関数はリミットSWを使用するときに使った関数です
    ただの名残なので参考にしないでください

    (例)

    void com_pwm_control(std::string path, std::string name)
    -----------------------------------------------*/